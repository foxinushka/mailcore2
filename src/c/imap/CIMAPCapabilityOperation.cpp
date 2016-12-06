#include "CIMAPCapabilityOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCapabilityOperation
#define structName CIMAPCapabilityOperation

CIndexSet capabilities(struct CIMAPCapabilityOperation self);

CIMAPCapabilityOperation newCIMAPCapabilityOperation(mailcore::IMAPCapabilityOperation *operationRef){
    CIMAPCapabilityOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.capabilities = &capabilities;
    
    return self;
}

void deleteCIMAPFetchFoldersOperation(CIMAPCapabilityOperation operation) {
    
}

CIndexSet capabilities(struct CIMAPCapabilityOperation self) {
    return newCIndexSet(self.instance->capabilities());
}
