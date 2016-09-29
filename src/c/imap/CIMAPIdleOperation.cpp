#include "CIMAPIdleOperation.h"

#define nativeType mailcore::IMAPIdleOperation
#define structName CIMAPIdleOperation

void interruptIdle(struct CIMAPIdleOperation self);

CIMAPIdleOperation newCIMAPIdleOperation(mailcore::IMAPIdleOperation* operation) {
    CIMAPIdleOperation self;
    self.operation = newCIMAPBaseOperation(operation);
    
    self.interruptIdle = &interruptIdle;
    
    return self;
}

mailcore::IMAPIdleOperation* cast(CIMAPIdleOperation self) {
    return reinterpret_cast<nativeType*>(self.operation.cOperation.nativeInstance);
}

void interruptIdle(struct CIMAPIdleOperation self) {
    cast(self)->interruptIdle();
}

void deleteCIMAPIdleOperation(CIMAPIdleOperation self) {
}
