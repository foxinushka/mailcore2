#include "CIMAPIdentityOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPIdentityOperation
#define structName CIMAPIdentityOperation

CIMAPIdentity CIMAPIdentityOperation_serverIdentity(struct CIMAPIdentityOperation self) {
    return CIMAPIdentity_new(self.instance->serverIdentity());
}

CIMAPIdentityOperation CIMAPIdentityOperation_new(mailcore::IMAPIdentityOperation *operationRef){
    CIMAPIdentityOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPIdentityOperation_release(CIMAPIdentityOperation operation) {
    
}
