#include <MailCore/MCAsync.h>
#include "COperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::Operation
#define structName COperation


class COperationCompletionCallback : public mailcore::Object, public mailcore::OperationCallback {
public:
    COperationCompletionCallback(COperationCompletionBlock block) {
        completionBlock = block;
    }
    
    virtual void operationFinished(mailcore::Operation * op)
    {
        completionBlock();
    }
    
private:
    COperationCompletionBlock completionBlock;;
};

struct COperation  setCompletionBlock(COperation self, COperationCompletionBlock block);
bool COperationIsCanceled(COperation self);
void COperationCancel(COperation self);
void COperationStart(COperation self);
bool shouldRunWhenCancelled(COperation self);
void setShouldRunWhenCancelled(COperation self, bool shouldRunWhenCancelled);

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
    
    return self;
}

struct COperation setCompletionBlock(COperation self, COperationCompletionBlock block) {
    self._callback = new COperationCompletionCallback(block);
    self.instance->setCallback(self._callback);
    return self;
}

C_SYNTHESIZE_BOOL(setShouldRunWhenCancelled, shouldRunWhenCancelled);

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
