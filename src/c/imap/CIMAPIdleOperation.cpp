#include <MailCore/MCAsync.h>
#include "CIMAPIdleOperation.h"


extern "C" {
    void start(struct CIMAPIdleOperation *self, CIMAPIdleOperationCompletionType completionBlock);
    void cancel(struct CIMAPIdleOperation *self);
    void interruptIdle(struct CIMAPIdleOperation *self);
    void operationCompleted(struct COperation *self);
    
    CIMAPIdleOperation initCIMAPIdleOperation(/*mailcore::Operation*/ref operationRef){
        CIMAPIdleOperation operation;
        operation.ancestor = initCIMAPBaseOperation(operationRef);
        operation.ancestor.inheritor = &operation;
        operation.ancestor.ancestor.operationCompleted = &operationCompleted;
        return operation;
    }
    
    void deleteCIMAPIdleOperation(CIMAPIdleOperation *operation){
    
    }
    
    void start(struct CIMAPIdleOperation *self, CIMAPIdleOperationCompletionType completionBlock) {
        self->_completionBlock = completionBlock;
        self->ancestor.ancestor.start(&self->ancestor.ancestor);
    }
    
    void cancel(struct CIMAPIdleOperation *self) {
        self->_completionBlock = NULL;
        self->ancestor.ancestor.cancel(&self->ancestor.ancestor);
    }
    
    void interruptIdle(struct CIMAPIdleOperation *self) {
        reinterpret_cast<mailcore::IMAPIdleOperation *>(self->ancestor.ancestor.self)->interruptIdle();
    }
    
    void operationCompleted(struct COperation *cOp) {
        CIMAPIdleOperation* self = reinterpret_cast<CIMAPIdleOperation *>(reinterpret_cast<CIMAPBaseOperation *>(cOp->inheritor)->inheritor);
        if (self->_completionBlock == NULL) {
            return;
        }
        mailcore::IMAPIdleOperation *op = reinterpret_cast<mailcore::IMAPIdleOperation *>(self->ancestor.ancestor.self);
        ErrorCode code =static_cast<ErrorCode>(op->error());
        self->_completionBlock(code);
        self->_completionBlock = NULL;
    }
}
