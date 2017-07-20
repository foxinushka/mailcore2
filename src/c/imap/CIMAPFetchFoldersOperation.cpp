#include "CIMAPFetchFoldersOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchFoldersOperation
#define structName CIMAPFetchFoldersOperation

CIMAPFetchFoldersOperation CIMAPFetchFoldersOperation_new(mailcore::IMAPFetchFoldersOperation *operationRef){
    CIMAPFetchFoldersOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPFetchFoldersOperation_release(CIMAPFetchFoldersOperation operation) {
    
}

CArray CIMAPFetchFoldersOperation_folders(struct CIMAPFetchFoldersOperation self) {
    return CArray_new(self.instance->folders());
}
