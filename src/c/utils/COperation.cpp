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

void setCompletionBlock(COperation *self, COperationCompletionBlock block);
bool COperationIsCanceled(COperation *operation);
void COperationCancel(COperation *operation);
void COperationStart(COperation *operation);
bool shouldRunWhenCancelled(struct COperation *self);
void setShouldRunWhenCancelled(struct COperation *self, bool shouldRunWhenCancelled);

COperation newCOperation(mailcore::Operation *operationRef) {
    COperation self;
    self.nativeInstance = operationRef;
    self._callback = NULL;
    
    self.setCompletionBlock = &setCompletionBlock;
    self.isCanceled = &COperationIsCanceled;
    self.cancel = &COperationCancel;
    self.start = &COperationStart;
    self.shouldRunWhenCancelled = &shouldRunWhenCancelled;
    self.setShouldRunWhenCancelled = &setShouldRunWhenCancelled;
    
    return self;
}

void setCompletionBlock(COperation *self, COperationCompletionBlock block) {
    COperationCompletionCallback *callback = new COperationCompletionCallback(block);
    self->_callback = reinterpret_cast<void *>(callback);
    C_NATIVE_INSTANCE->setCallback(callback);
}

C_SYNTHESIZE_BOOL(setShouldRunWhenCancelled, shouldRunWhenCancelled);

bool COperationIsCanceled(COperation *self) {
    return C_NATIVE_INSTANCE->isCancelled();
}

void COperationCancel(COperation *self) {
    C_NATIVE_INSTANCE->cancel();
}

void COperationStart(COperation *self) {
    C_NATIVE_INSTANCE->start();
}

extern "C" void deleteCOperation(COperation *self) {
    C_NATIVE_INSTANCE->release();
    if (self->_callback != NULL) {
        reinterpret_cast<COperationCompletionCallback *>(self->_callback)->release();
    }
}
