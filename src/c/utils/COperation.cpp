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

void setCompletionBlock(COperation self, COperationCompletionBlock block);
bool COperationIsCanceled(COperation self);
void COperationCancel(COperation self);
void COperationStart(COperation self);
bool shouldRunWhenCancelled(COperation self);
void setShouldRunWhenCancelled(COperation self, bool shouldRunWhenCancelled);

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

mailcore::Operation* cast(COperation self) {
    return reinterpret_cast<mailcore::Operation *>(self.nativeInstance);
}

void setCompletionBlock(COperation self, COperationCompletionBlock block) {
    COperationCompletionCallback *callback = new COperationCompletionCallback(block);
    self._callback = reinterpret_cast<void *>(callback);
    cast(self)->setCallback(callback);
}

C_SYNTHESIZE_BOOL(setShouldRunWhenCancelled, shouldRunWhenCancelled);

bool COperationIsCanceled(COperation self) {
    return cast(self)->isCancelled();
}

void COperationCancel(COperation self) {
    cast(self)->cancel();
}

void COperationStart(COperation self) {
    cast(self)->start();
}

extern "C" void deleteCOperation(COperation self) {
    cast(self)->release();
    if (self._callback != NULL) {
        reinterpret_cast<COperationCompletionCallback *>(self._callback)->release();
    }
}
