#include "CIMAPIdentityOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPIdentityOperation
#define structName CIMAPIdentityOperation

CIMAPIdentity serverIdentity(struct CIMAPIdentityOperation self) {
    return newCIMAPIdentity(self.instance->serverIdentity());
}

CIMAPIdentityOperation newCIMAPIdentityOperation(mailcore::IMAPIdentityOperation *operationRef){
    CIMAPIdentityOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.serverIdentity = &serverIdentity;
    
    return self;
}

void deleteCIMAPFetchNamespaceOperation(CIMAPIdentityOperation operation) {
    
}
