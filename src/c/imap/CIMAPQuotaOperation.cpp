#include "CIMAPQuotaOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPQuotaOperation
#define structName CIMAPQuotaOperation

uint32_t CIMAPQuotaOperation_usage(struct CIMAPQuotaOperation self) {
    return self.instance->usage();
}

uint32_t CIMAPQuotaOperation_limit(struct CIMAPQuotaOperation self) {
    return self.instance->limit();
}

CIMAPQuotaOperation CIMAPQuotaOperation_new(mailcore::IMAPQuotaOperation *operationRef){
    CIMAPQuotaOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPQuotaOperation_release(CIMAPQuotaOperation operation) {
    
}
