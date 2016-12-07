#include "CIMAPQuotaOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPQuotaOperation
#define structName CIMAPQuotaOperation

uint32_t usage(struct CIMAPQuotaOperation self) {
    return self.instance->usage();
}

uint32_t limit(struct CIMAPQuotaOperation self) {
    return self.instance->limit();
}

CIMAPQuotaOperation newCIMAPQuotaOperation(mailcore::IMAPQuotaOperation *operationRef){
    CIMAPQuotaOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.usage = &usage;
    self.limit = &limit;
    
    return self;
}

void deleteCIMAPQuotaOperation(CIMAPQuotaOperation operation) {
    
}
