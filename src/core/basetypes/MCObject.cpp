#include "MCObject.h"

#include <stdlib.h>
#include <typeinfo>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif
#include <libetpan/libetpan.h>
#include <string.h>
#if __APPLE__
#include <Block.h>
#elif defined(_MSC_VER)
#include <Block/Block.h>
#endif

#include "MCAutoreleasePool.h"
#include "MCString.h"
#include "MCHash.h"
#include "MCLog.h"
#include "MCUtils.h"
#include "MCAssert.h"
#include "MCMainThread.h"
#include "MCLog.h"
#include "MCHashMap.h"
#include "MCLock.h"

#if defined(ANDROID) || defined(__ANDROID__)
// TODO: remove when swift toolchain updated to 15c
#include <string>
#endif

using namespace mailcore;

bool mailcore::zombieEnabled = 0;

Object::Object()
{
    init();
}

Object::~Object()
{
#ifndef __APPLE__
    pthread_mutex_destroy(&mLock);
#endif
}

void Object::init()
{
#ifdef _MSC_VER
	mLock = SRWLOCK_INIT;
#elif __APPLE__
    mLock = OS_UNFAIR_LOCK_INIT;
#else
    pthread_mutex_init(&mLock, NULL);
#endif
    mCounter = 1;
}

int Object::retainCount()
{
    MC_LOCK(&mLock);
    int value = mCounter;
    MC_UNLOCK(&mLock);
    
    return value;
}

Object * Object::retain()
{
    MC_LOCK(&mLock);
    mCounter ++;
    MC_UNLOCK(&mLock);
    return this;
}

void Object::release()
{
    bool shouldRelease = false;
    
    MC_LOCK(&mLock);
    mCounter --;
    if (mCounter == 0) {
        shouldRelease = true;
    }
    if (mCounter < 0) {
        MCLog("release too much %p %s", this, MCUTF8(className()));
        //MCAssert(0);
    }
    MC_UNLOCK(&mLock);

    if (shouldRelease && !zombieEnabled) {
        //int status;
        //char * unmangled = abi::__cxa_demangle(typeid(* this).name(), NULL, NULL, &status);
        //MCLog("dealloc %p %s", this, unmangled);
        delete this;
    }
}

//Add Swift autorelease call
#ifndef __APPLE__
Object * Object::autorelease()
{
    AutoreleasePool::autorelease(this);
    return this;
}
#endif

String * Object::className()
{
#ifdef _MSC_VER
    String * result = String::uniquedStringWithUTF8Characters(typeid(*this).name());
	// typeid(*this).name() will return "class mailcore::Object". Therefore, we'll strip the prefix "class " from it.
	if (result->hasPrefix(MCSTR("class "))) {
		result = result->substringFromIndex(6);
	}
#else
	int status;

    #if defined(ANDROID) || defined(__ANDROID__)
        // workaround for android ndk 14b
        // see: https://github.com/android-ndk/ndk/issues/355
        // TODO: remove when swift toolchain updated to 15c
        static const std::string prefix = "_Z";

        const char* symbolName = typeid(* this).name();
        const char* typeName;

        std::string prefixed;

        if (prefix.compare(0, 2, symbolName) != 0) {
            prefixed = prefix + std::string(symbolName);

            typeName = prefixed.c_str();
        }
        else {
            typeName = symbolName;
        }
    #else
        const char* typeName = typeid(* this).name();
    #endif

    char * unmangled = abi::__cxa_demangle(typeName, NULL, NULL, &status);
    String * result = String::uniquedStringWithUTF8Characters(unmangled);
    free(unmangled);
#endif
    return result;
}

String * Object::description()
{
    return String::stringWithUTF8Format("<%s:%p>", className()->UTF8Characters(), this);
}

bool Object::isEqual(Object * otherObject)
{
    return this == otherObject;
}

unsigned int Object::hash()
{
    return hashCompute((const char *) this, sizeof(this));
}

Object * Object::copy()
{
    MCAssert(0);
    return NULL;
}

void Object::performMethod(Object::Method method, void * context)
{
    (this->*method)(context);
}

struct mainThreadCallData {
    Object * obj;
    void * context;
    Object::Method method;
    void * caller;
};

static chash * delayedPerformHash = NULL;
static MC_LOCK_TYPE delayedPerformLock = MC_LOCK_INITIAL_VALUE;

static void reallyInitDelayedPerform()
{
    delayedPerformHash = chash_new(CHASH_DEFAULTSIZE, CHASH_COPYKEY);
}

#ifdef _MSC_VER

static INIT_ONCE delayedPerformOnce = INIT_ONCE_STATIC_INIT;

BOOL CALLBACK reallyInitDelayedPerformCallback(PINIT_ONCE InitOnce, PVOID Parameter, PVOID * lpContext) {
	reallyInitDelayedPerform();
	return TRUE;
}

#else

static pthread_once_t delayedPerformOnce = PTHREAD_ONCE_INIT;

#endif

static void initDelayedPerform()
{
#ifdef _MSC_VER
	InitOnceExecuteOnce(&delayedPerformOnce, reallyInitDelayedPerformCallback, NULL, NULL);
#else
    pthread_once(&delayedPerformOnce, reallyInitDelayedPerform);
#endif
}

struct mainThreadCallKeyData {
    Object * dispatchQueueIdentifier;
    Object * obj;
    void * context;
    Object::Method method;
};

static void removeFromPerformHash(Object * obj, Object::Method method, void * context, void * targetDispatchQueue)
{
    chashdatum key;
    struct mainThreadCallKeyData keyData;
    Object * queueIdentifier = NULL;
#if MC_HAS_GCD
    if (targetDispatchQueue != NULL) {
        queueIdentifier = (Object *) dispatch_queue_get_specific((dispatch_queue_t) targetDispatchQueue, "MCDispatchQueueID");
    }
#endif
    memset(&keyData, 0, sizeof(keyData));
    keyData.dispatchQueueIdentifier = queueIdentifier;
    keyData.obj = obj;
    keyData.context = context;
    keyData.method = method;
    key.data = &keyData;
    key.len = sizeof(keyData);

    MC_LOCK(&delayedPerformLock);
    chash_delete(delayedPerformHash, (chashdatum *) &key, NULL);
    MC_UNLOCK(&delayedPerformLock);
}

static void queueIdentifierDestructor(void * identifier)
{
    Object * obj = (Object *) identifier;
    MC_SAFE_RELEASE(obj);
}

static void addToPerformHash(Object * obj, Object::Method method, void * context, void * targetDispatchQueue,
                             void * performValue)
{
    chashdatum key;
    chashdatum value;
    struct mainThreadCallKeyData keyData;
    Object * queueIdentifier = NULL;
#if MC_HAS_GCD
    if (targetDispatchQueue == NULL) {
        queueIdentifier = NULL;
    }
    else {
        queueIdentifier = (Object *) dispatch_queue_get_specific((dispatch_queue_t) targetDispatchQueue, "MCDispatchQueueID");
        if (queueIdentifier == NULL) {
            queueIdentifier = new Object();
            dispatch_queue_set_specific((dispatch_queue_t) targetDispatchQueue, "MCDispatchQueueID", queueIdentifier, queueIdentifierDestructor);
        }
    }
#endif
    memset(&keyData, 0, sizeof(keyData));
    keyData.dispatchQueueIdentifier = queueIdentifier;
    keyData.obj = obj;
    keyData.context = context;
    keyData.method = method;
    key.data = &keyData;
    key.len = sizeof(keyData);
    value.data = performValue;
    value.len = 0;
    MC_LOCK(&delayedPerformLock);
    chash_set(delayedPerformHash, &key, &value, NULL);
    MC_UNLOCK(&delayedPerformLock);
}

static void * getFromPerformHash(Object * obj, Object::Method method, void * context, void * targetDispatchQueue)
{
    chashdatum key;
    chashdatum value;
    struct mainThreadCallKeyData keyData;
    int r;
    
    Object * queueIdentifier = NULL;
#if MC_HAS_GCD
    if (targetDispatchQueue != NULL) {
        queueIdentifier = (Object *) dispatch_queue_get_specific((dispatch_queue_t) targetDispatchQueue, "MCDispatchQueueID");
        if (queueIdentifier == NULL)
            return NULL;
    }
#endif
    memset(&keyData, 0, sizeof(keyData));
    keyData.dispatchQueueIdentifier = queueIdentifier;
    keyData.obj = obj;
    keyData.context = context;
    keyData.method = method;
    key.data = &keyData;
    key.len = sizeof(keyData);
    
    MC_LOCK(&delayedPerformLock);
    r = chash_get(delayedPerformHash, &key, &value);
    MC_UNLOCK(&delayedPerformLock);
    if (r < 0)
        return NULL;
    
    return value.data;
}

static void performOnMainThread(void * info)
{
    struct mainThreadCallData * data;
    void * context;
    Object * obj;
    Object::Method method;
    
    data = (struct mainThreadCallData *) info;
    obj = data->obj;
    context = data->context;
    method = data->method;
    
    (obj->*method)(context);
    
    free(data);
}
 
void Object::performMethodOnMainThread(Method method, void * context, bool waitUntilDone)
{
    struct mainThreadCallData * data;
    
    data = (struct mainThreadCallData *) calloc(sizeof(* data), 1);
    data->obj = this;
    data->context = context;
    data->method = method;
    data->caller = NULL;
    
    if (waitUntilDone) {
        callOnMainThreadAndWait(performOnMainThread, data);
    }
    else {
        callOnMainThread(performOnMainThread, data);
    }
}

#if MC_HAS_GCD
void Object::performMethodOnDispatchQueue(Method method, void * context, void * targetDispatchQueue, bool waitUntilDone)
{
    if (waitUntilDone) {
        dispatch_retain((dispatch_queue_t) targetDispatchQueue);
        dispatch_sync((dispatch_queue_t) targetDispatchQueue, ^{
            (this->*method)(context);
        });
        dispatch_release((dispatch_queue_t) targetDispatchQueue);
    }
    else {
        dispatch_async((dispatch_queue_t) targetDispatchQueue, ^{
            (this->*method)(context);
        });
    }
}

struct cancellableBlock {
    void (^block)(void);
    bool cancelled;
};

void Object::performMethodOnDispatchQueueAfterDelay(Method method, void * context, void * targetDispatchQueue, double delay)
{
    initDelayedPerform();
    
    __block bool cancelled = false;

    void (^dupCancelableBlock)(bool cancel) = NULL;
    void (^cancelableBlock)(bool cancel) = ^(bool cancel) {
        Block_release(dupCancelableBlock);
        if (cancel) {
            cancelled = true;
            return;
        }
        if (!cancelled) {
            (this->*method)(context);
        }
    };
    
    dupCancelableBlock = Block_copy(cancelableBlock);
    
    retain();
    addToPerformHash(this, method, context, targetDispatchQueue, (void *) dupCancelableBlock);
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(delay * NSEC_PER_SEC));
    dispatch_after(popTime, (dispatch_queue_t) targetDispatchQueue, ^(void) {
        if (!cancelled) {
            removeFromPerformHash(this, method, context, targetDispatchQueue);
        }
        dupCancelableBlock(false);
        Block_release(dupCancelableBlock);
        if (!cancelled) {
            release();
        }
    });
}

void Object::cancelDelayedPerformMethodOnDispatchQueue(Method method, void * context, void * targetDispatchQueue)
{
    initDelayedPerform();
    void (^dupCancelableBlock)(bool cancel) = (void (^)(bool)) getFromPerformHash(this, method, context, targetDispatchQueue);
    if (dupCancelableBlock == NULL) {
        return;
    }
    removeFromPerformHash(this, method, context, targetDispatchQueue);
    dupCancelableBlock(true);
    release();
}
#endif

void Object::performMethodAfterDelay(Method method, void * context, double delay)
{
#if MC_HAS_GCD
    performMethodOnDispatchQueueAfterDelay(method, context, Object::getMainQueue(), delay);
#else
    initDelayedPerform();
    
    struct mainThreadCallData * data;
    
    data = (struct mainThreadCallData *) calloc(sizeof(* data), 1);
    data->obj = this;
    data->context = context;
    data->method = method;
    data->caller = callAfterDelay(performAfterDelay, data, delay);
    addToPerformHash(this, method, context, NULL, data);
#endif
}

void Object::cancelDelayedPerformMethod(Method method, void * context)
{
#if MC_HAS_GCD
    cancelDelayedPerformMethodOnDispatchQueue(method, context, Object::getMainQueue());
#else
    initDelayedPerform();
    
    struct mainThreadCallData * data = (struct mainThreadCallData *) getFromPerformHash(this, method, context, NULL);
    if (data == NULL)
        return;
    
    removeFromPerformHash(this, method, context, NULL);
    cancelDelayedCall(data->caller);
    free(data);
#endif
}

HashMap * Object::serializable()
{
    HashMap * result = HashMap::hashMap();
    result->setObjectForKey(MCSTR("class"), className());
    return result;
}

void Object::importSerializable(HashMap * serializable)
{
    MCAssert(0);
}

#ifdef _MSC_VER

BOOL CALLBACK Object::initObjectConstructorsCallback(PINIT_ONCE InitOnce, PVOID Parameter, PVOID * lpContext) {
	initObjectConstructors();
	return TRUE;
}

#endif

static chash * constructors = NULL;

void Object::initObjectConstructors()
{
    constructors = chash_new(CHASH_DEFAULTSIZE, CHASH_COPYKEY);
}

void Object::registerObjectConstructor(const char * className, void * (* objectConstructor)(void))
{
#ifdef _MSC_VER
	INIT_ONCE once = INIT_ONCE_STATIC_INIT;
	InitOnceExecuteOnce(&once, initObjectConstructorsCallback, NULL, NULL);
#else
    static pthread_once_t once = PTHREAD_ONCE_INIT;
	pthread_once(&once, initObjectConstructors);
#endif

    chashdatum key;
    chashdatum value;
    key.data = (void *) className;
    key.len = (unsigned int) strlen(className);
    value.data = (void *) objectConstructor;
    value.len = 0;
    chash_set(constructors, &key, &value, NULL);
}

Object * Object::objectWithSerializable(HashMap * serializable)
{
    if (serializable == NULL)
        return NULL;
    
    void * (* objectConstructor)(void) = NULL;
    
    chashdatum key;
    chashdatum value;
    const char * className = ((String *) serializable->objectForKey(MCSTR("class")))->UTF8Characters();
    key.data = (void *) className;
    key.len = (unsigned int) strlen(className);
    int r = chash_get(constructors, &key, &value);
    if (r < 0)
        return NULL;
    
    objectConstructor = (void * (*)()) value.data;
    Object * obj = (Object *) objectConstructor();
    obj->importSerializable(serializable);
    return obj->autorelease();
}

#if defined(__ANDROID__)
dispatch_queue_t mailcore::mainQueue = NULL;
#endif

#if MC_HAS_GCD
dispatch_queue_t Object::getMainQueue()
{
    #if defined(__ANDROID__)
        dispatch_queue_t queue = mailcore::mainQueue;
        // You should set mainQueue before using MailCore
        assert(queue != NULL);
        dispatch_retain(queue);
        return queue;
    #else
        return dispatch_get_main_queue();
    #endif

}
#endif

