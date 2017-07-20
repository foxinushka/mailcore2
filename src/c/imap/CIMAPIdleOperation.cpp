#include "CIMAPIdleOperation.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPIdleOperation
#define structName CIMAPIdleOperation

CIMAPIdleOperation CIMAPIdleOperation_new(mailcore::IMAPIdleOperation* operation) {
    CIMAPIdleOperation self;
    self.operation = CIMAPBaseOperation_new(operation);
    self.instance = operation;
    return self;
}

void CIMAPIdleOperation_interruptIdle(struct CIMAPIdleOperation self) {
    self.instance->interruptIdle();
}
