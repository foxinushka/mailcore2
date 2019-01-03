#include <MailCore/MCAsync.h>
#include "COperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::Operation
#define structName COperation

C_SYNTHESIZE_BOOL(setShouldRunWhenCancelled, shouldRunWhenCancelled);
C_SYNTHESIZE_SCALAR(dispatch_queue_t, dispatch_queue_t, setCallbackDispatchQueue, callbackDispatchQueue)
C_SYNTHESIZE_COBJECT_CAST()

class COperationCompletionCallback : public mailcore::Object, public mailcore::OperationCallback {
private:
    COperationCompletionBlock completionBlock = NULL;
    const void* userInfo = NULL;
public:
    COperationCompletionCallback(COperationCompletionBlock block, const void* userInfo) {
        this->completionBlock = block;
        this->userInfo = userInfo;
    }
    
    virtual void operationFinished(mailcore::Operation * op)
    {
        completionBlock(this->userInfo);
    }
};

COperation COperation_new(mailcore::Operation *operationRef) {
    COperation self;
    self.instance = operationRef;
    self._callback = NULL;
    return self;
}

struct COperation COperation_setCompletionBlock(COperation self, COperationCompletionBlock block, const void* userInfo) {
    COperation_clearCompletionBlock(self);
    self._callback = new COperationCompletionCallback(block, userInfo);
    self.instance->setCallback(self._callback);
    return self;
}

struct COperation COperation_clearCompletionBlock(COperation self) {
    COperationCompletionCallback *callback = self._callback;
    mailcore::Operation *instance = self.instance;
    
    if (callback == NULL) {
        return self;
    }
    
    self._callback = NULL;
    
    dispatch_queue_t callbackQueue = self.instance->callbackDispatchQueue();
    
    if (callbackQueue == NULL) {
        MCAssert(0);
        instance->setCallback(NULL);
        callback->release();
    }
    else {
        // clear and release callback on callback queue
        // to be in sync with "callback() == NULL" checks in other places of Mailcore
        
        instance->retain();
        
        dispatch_async(callbackQueue, ^{
            instance->setCallback(NULL);
            instance->release();
            callback->release();
        });
    }
    
    return self;
}


C_SYNTHESIZE_FUNC_WITH_SCALAR(bool, isCancelled)
C_SYNTHESIZE_FUNC_WITH_VOID(cancel)
C_SYNTHESIZE_FUNC_WITH_VOID(start)

void COperation_release(COperation self) {
    self.instance->release();
}

void COperation_retain(COperation self) {
    self.instance->retain();
}

int COperation_retainCount(COperation self) {
    return self.instance->retainCount();
}
