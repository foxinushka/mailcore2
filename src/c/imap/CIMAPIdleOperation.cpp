#include "CIMAPIdleOperation.h"

#define nativeType mailcore::IMAPIdleOperation
#define structName CIMAPIdleOperation

void interruptIdle(struct CIMAPIdleOperation *self);

CIMAPIdleOperation newCIMAPIdleOperation(mailcore::IMAPIdleOperation* operation) {
    CIMAPIdleOperation self;
    self.operation = newCIMAPBaseOperation(operation);
    
    self.interruptIdle = &interruptIdle;
    
    return self;
}

void interruptIdle(struct CIMAPIdleOperation *self) {
    reinterpret_cast<nativeType*>(self->operation.cOperation.nativeInstance)->interruptIdle();
}

extern "C" void deleteCIMAPIdleOperation(CIMAPIdleOperation *self) {
    deleteCIMAPBaseOperation(&self->operation);
}
