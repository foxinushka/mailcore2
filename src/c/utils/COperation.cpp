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
    self.instance->retain();
    self._callback = NULL;
    return self;
}

struct COperation COperation_setCompletionBlock(COperation self, COperationCompletionBlock block, const void* userInfo) {
    self._callback = new COperationCompletionCallback(block, userInfo);
    self.instance->setCallback(self._callback);
    return self;
}

C_SYNTHESIZE_FUNC_WITH_SCALAR(bool, isCancelled)
C_SYNTHESIZE_FUNC_WITH_VOID(cancel)
C_SYNTHESIZE_FUNC_WITH_VOID(start)


void COperation_release(COperation self) {
    self.instance->release();
    if (self._callback != NULL) {
        self._callback->release();
    }
}

void COperation_retain(COperation self) {
    self.instance->retain();
}
