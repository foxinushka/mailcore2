#include "MCOperation.h"

using namespace mailcore;

Operation::Operation()
{
    mCallback = NULL;
    mCancelled = false;
    mShouldRunWhenCancelled = false;

	MCB_LOCK_INIT(&mLock);

#if defined(__APPLE__) || defined(__ANDROID__)
    mCallbackDispatchQueue = getMainQueue();
#endif
}

Operation::~Operation()
{
#if defined(__APPLE__) || defined(__ANDROID__)
    if (mCallbackDispatchQueue != NULL) {
        dispatch_release(mCallbackDispatchQueue);
    }
#endif

    MCB_LOCK_DESTROY(&mLock);
}

void Operation::setCallback(OperationCallback * callback)
{
    mCallback = callback;
}

OperationCallback * Operation::callback()
{
    return mCallback;
}

void Operation::cancel()
{
	MCB_LOCK(&mLock);
    mCancelled = true;
	MCB_UNLOCK(&mLock);
}

bool Operation::isCancelled()
{
	MCB_LOCK(&mLock);
    bool value = mCancelled;
	MCB_UNLOCK(&mLock);
    
    return value;
}

bool Operation::shouldRunWhenCancelled()
{
    return mShouldRunWhenCancelled;
}

void Operation::setShouldRunWhenCancelled(bool shouldRunWhenCancelled)
{
    mShouldRunWhenCancelled = shouldRunWhenCancelled;
}

void Operation::beforeMain()
{
}

void Operation::main()
{
}

void Operation::afterMain()
{
}

void Operation::start()
{
}

#if defined(__APPLE__) || defined(__ANDROID__)
void Operation::setCallbackDispatchQueue(dispatch_queue_t callbackDispatchQueue)
{
    if (mCallbackDispatchQueue != NULL) {
        dispatch_release(mCallbackDispatchQueue);
    }
    mCallbackDispatchQueue = callbackDispatchQueue;
    if (mCallbackDispatchQueue != NULL) {
        dispatch_retain(mCallbackDispatchQueue);
    }
}

dispatch_queue_t Operation::callbackDispatchQueue()
{
    return mCallbackDispatchQueue;
}
#endif

void Operation::performMethodOnCallbackThread(Method method, void * context, bool waitUntilDone)
{
#if defined(__APPLE__) || defined(__ANDROID__)
    dispatch_queue_t queue = mCallbackDispatchQueue;
    if (queue == NULL) {
        queue = getMainQueue();
    }
    performMethodOnDispatchQueue(method, context, queue, waitUntilDone);
#else
    performMethodOnMainThread(method, context, waitUntilDone);
#endif
}
