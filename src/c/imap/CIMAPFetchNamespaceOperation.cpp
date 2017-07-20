#include "CIMAPFetchNamespaceOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchNamespaceOperation
#define structName CIMAPFetchNamespaceOperation

CIMAPFetchNamespaceOperation CIMAPFetchNamespaceOperation_new(mailcore::IMAPFetchNamespaceOperation *operationRef){
    CIMAPFetchNamespaceOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPFetchNamespaceOperation_release(CIMAPFetchNamespaceOperation operation) {
    
}

CDictionary CIMAPFetchNamespaceOperation_namespaces(struct CIMAPFetchNamespaceOperation self) {
    return CDictionary_new(self.instance->namespaces());
}
