#include "CIMAPIdleOperation.h"
#include "CIMAPIdleOperation+Private.h"
#include "CIMAPBaseOperation+Private.h"

void start(struct CIMAPIdleOperation *self, CIMAPIdleOperationCompletionType completionBlock);
void cancel(struct CIMAPIdleOperation *self);
void interruptIdle(struct CIMAPIdleOperation *self);
void operationCompleted(struct COperation *self);

extern "C" CIMAPIdleOperation newCIMAPIdleOperation(mailcore::Operation* operationRef){
    CIMAPIdleOperation operation;
    operation.ancestor = newCIMAPBaseOperation(operationRef);
    operation.ancestor.inheritor = &operation;
    operation.ancestor.cOperation.operationCompleted = &operationCompleted;
    return operation;
}

void start(struct CIMAPIdleOperation *self, CIMAPIdleOperationCompletionType completionBlock) {
    self->_completionBlock = completionBlock;
    self->ancestor.cOperation.start(&self->ancestor.cOperation);
}

void cancel(struct CIMAPIdleOperation *self) {
    self->_completionBlock = NULL;
    self->ancestor.cOperation.cancel(&self->ancestor.cOperation);
}

void interruptIdle(struct CIMAPIdleOperation *self) {
    reinterpret_cast<mailcore::IMAPIdleOperation *>(self->ancestor.cOperation.self)->interruptIdle();
}

void operationCompleted(struct COperation *cOp) {
    CIMAPIdleOperation* self = reinterpret_cast<CIMAPIdleOperation *>(reinterpret_cast<CIMAPBaseOperation *>(cOp->inheritor)->inheritor);
    if (self->_completionBlock == NULL) {
        return;
    }
    mailcore::IMAPIdleOperation *op = reinterpret_cast<mailcore::IMAPIdleOperation *>(self->ancestor.cOperation.self);
    ErrorCode code =static_cast<ErrorCode>(op->error());
    self->_completionBlock(code);
    self->_completionBlock = NULL;
}

extern "C" void deleteCIMAPIdleOperation(CIMAPIdleOperation *operation){
    
}
