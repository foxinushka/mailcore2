#include "CIMAPFetchFoldersOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchFoldersOperation
#define structName CIMAPFetchFoldersOperation

CArray folders(struct CIMAPFetchFoldersOperation self);

CIMAPFetchFoldersOperation newCIMAPFetchFoldersOperation(mailcore::IMAPFetchFoldersOperation *operationRef){
    CIMAPFetchFoldersOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.folders = &folders;
    
    return self;
}

void deleteCIMAPFetchFoldersOperation(CIMAPFetchFoldersOperation operation) {
    
}

CArray folders(struct CIMAPFetchFoldersOperation self) {
    return newCArray(self.instance->folders());
}
