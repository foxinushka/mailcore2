#include <MailCore/MCAsync.h>
#include "COperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::Operation
#define structName COperation

C_SYNTHESIZE_BOOL(setShouldRunWhenCancelled, shouldRunWhenCancelled);
C_SYNTHESIZE_SCALAR(dispatch_queue_t, dispatch_queue_t, setCallbackDispatchQueue, callbackDispatchQueue)

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

bool COperation_isCanceled(COperation self) {
    return self.instance->isCancelled();
}

void COperation_cancel(COperation self) {
    self.instance->cancel();
}

void COperation_start(COperation self) {
    self.instance->start();
}

extern "C" void COperation_release(COperation self) {
    self.instance->release();
    if (self._callback != NULL) {
        self._callback->release();
    }
}
