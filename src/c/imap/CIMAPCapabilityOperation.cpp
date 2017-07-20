#include "CIMAPCapabilityOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCapabilityOperation
#define structName CIMAPCapabilityOperation

CIMAPCapabilityOperation CIMAPCapabilityOperation_new(mailcore::IMAPCapabilityOperation *operationRef){
    CIMAPCapabilityOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPCapabilityOperation_release(CIMAPCapabilityOperation operation) {
    
}

CIndexSet CIMAPCapabilityOperation_capabilities(struct CIMAPCapabilityOperation self) {
    return CIndexSet_new(self.instance->capabilities());
}
