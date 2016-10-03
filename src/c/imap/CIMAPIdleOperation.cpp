#include "CIMAPIdleOperation.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPIdleOperation
#define structName CIMAPIdleOperation

void interruptIdle(struct CIMAPIdleOperation self);

CIMAPIdleOperation newCIMAPIdleOperation(mailcore::IMAPIdleOperation* operation) {
    CIMAPIdleOperation self;
    self.operation = newCIMAPBaseOperation(operation);
    self.instance = operation;
    
    self.interruptIdle = &interruptIdle;
    
    return self;
}

void interruptIdle(struct CIMAPIdleOperation self) {
    self.instance->interruptIdle();
}
