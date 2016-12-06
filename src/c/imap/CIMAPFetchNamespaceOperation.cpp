#include "CIMAPFetchNamespaceOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchNamespaceOperation
#define structName CIMAPFetchNamespaceOperation

CDictionary namespaces(struct CIMAPFetchNamespaceOperation self);

CIMAPFetchNamespaceOperation newCIMAPFetchNamespaceOperation(mailcore::IMAPFetchNamespaceOperation *operationRef){
    CIMAPFetchNamespaceOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.namespaces = &namespaces;
    
    return self;
}

void deleteCIMAPFetchNamespaceOperation(CIMAPFetchNamespaceOperation operation) {
    
}

CDictionary namespaces(struct CIMAPFetchNamespaceOperation self) {
    return newCDictionary(self.instance->namespaces());
}
