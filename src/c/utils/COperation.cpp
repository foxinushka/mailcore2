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

struct COperation setCompletionBlock(COperation self, COperationCompletionBlock block, const void* userInfo);
bool COperationIsCanceled(COperation self);
void COperationCancel(COperation self);
void COperationStart(COperation self);

COperation newCOperation(mailcore::Operation *operationRef) {
    COperation self;
    self.instance = operationRef;
    self.instance->retain();
    self._callback = NULL;
    
    self.setCompletionBlock = &setCompletionBlock;
    self.isCanceled = &COperationIsCanceled;
    self.cancel = &COperationCancel;
    self.start = &COperationStart;
    self.shouldRunWhenCancelled = &shouldRunWhenCancelled;
    self.setShouldRunWhenCancelled = &setShouldRunWhenCancelled;
    self.callbackDispatchQueue = &callbackDispatchQueue;
    self.setCallbackDispatchQueue = &setCallbackDispatchQueue;
    
    return self;
}

struct COperation setCompletionBlock(COperation self, COperationCompletionBlock block, const void* userInfo) {
    self._callback = new COperationCompletionCallback(block, userInfo);
    self.instance->setCallback(self._callback);
    return self;
}



bool COperationIsCanceled(COperation self) {
    return self.instance->isCancelled();
}

void COperationCancel(COperation self) {
    self.instance->cancel();
}

void COperationStart(COperation self) {
    self.instance->start();
}

extern "C" void deleteCOperation(COperation self) {
    self.instance->release();
    if (self._callback != NULL) {
        self._callback->release();
    }
}
