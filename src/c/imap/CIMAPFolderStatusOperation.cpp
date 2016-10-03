#include "CIMAPFolderStatusOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFolderStatusOperation
#define structName CIMAPFolderStatusOperation

CIMAPFolderStatus status(struct CIMAPFolderStatusOperation self);

CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operation){
    CIMAPFolderStatusOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    self.instance = operation;
    
    self.status = &status;
    
    return self;
}

void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation operation) {
    
}

CIMAPFolderStatus status(CIMAPFolderStatusOperation self) {
    return newCIMAPFolderStatus(self.instance->status());
}
