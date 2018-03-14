#ifndef MAILCORE_MCOBJECT_H

#define MAILCORE_MCOBJECT_H

#include <pthread.h>

#if defined(__APPLE__) || defined(__ANDROID__)
#include <dispatch/dispatch.h>
#endif

#if __APPLE__
#include <libkern/OSAtomic.h>
#endif

#if __ANDROID__
#if __cplusplus
extern "C" {
#endif
    
    // Create a heap based copy of a Block or simply add a reference to an existing one.
    // This must be paired with Block_release to recover memory, even when running
    // under Objective-C Garbage Collection.
    void *_Block_copy(const void *aBlock);
    
    // Lose the reference, and if heap based and last reference, recover the memory
    void _Block_release(const void *aBlock);
    
#if __cplusplus
}
#endif

// Type correct macros

#define Block_copy(...) ((__typeof(__VA_ARGS__))_Block_copy((const void *)(__VA_ARGS__)))
#define Block_release(...) _Block_release((const void *)(__VA_ARGS__))

#endif

#include <MailCore/MCUtils.h>

#ifdef __cplusplus

namespace mailcore {
    
    extern bool zombieEnabled;

    #ifdef __ANDROID__
    // Android main queue
    extern dispatch_queue_t mainQueue;
    #endif
    
    class String;
    class HashMap;
    
    class MAILCORE_EXPORT Object {
    public:
        Object();
        virtual ~Object();
        
        virtual int retainCount();
        virtual Object * retain();
        virtual void release();
        virtual Object * autorelease();
        virtual String * description();
        virtual String * className();
        
        virtual bool isEqual(Object * otherObject);
        virtual unsigned int hash();
        
        // optional
        virtual Object * copy();
        virtual HashMap * serializable();
        virtual void importSerializable(HashMap * serializable);
        
        typedef void (Object::*Method) (void *);
        virtual void performMethod(Method method, void * context);
#ifndef __ANDROID__
        virtual void performMethodOnMainThread(Method method, void * context, bool waitUntilDone = false);
#endif
        virtual void performMethodAfterDelay(Method method, void * context, double delay);
#if defined(__APPLE__) || defined(__ANDROID__)
        virtual void performMethodOnDispatchQueue(Method method, void * context, void * targetDispatchQueue, bool waitUntilDone = false);
        virtual void performMethodOnDispatchQueueAfterDelay(Method method, void * context, void * targetDispatchQueue, double delay);
        virtual void cancelDelayedPerformMethodOnDispatchQueue(Method method, void * context, void * targetDispatchQueue);
#endif
        virtual void cancelDelayedPerformMethod(Method method, void * context);
        
        // serialization utils
        static void registerObjectConstructor(const char * className, void * (* objectConstructor)(void));
        static Object * objectWithSerializable(HashMap * serializable);

        // Druk: in Android dispatch_get_main_queue() return dead queue that not drained
        // That's why in Swift we create another queue that called `main` but it executes task NOT on Android main thread
        // We store reference for that "main" queue in global variable mailcore::mainQueue
        static dispatch_queue_t getMainQueue();
        
    public: // private
        
    private:
#if __APPLE__
        OSSpinLock mLock;
#else
        pthread_mutex_t mLock;
#endif
        int mCounter;
        void init();
        static void initObjectConstructors();
    };

}

#endif

#endif
