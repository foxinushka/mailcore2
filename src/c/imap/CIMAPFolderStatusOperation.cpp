#include "CIMAPFolderStatusOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPFolderStatusOperation
#define structName CIMAPFolderStatusOperation

CIMAPFolderStatus status(struct CIMAPFolderStatusOperation self);

CIMAPFolderStatusOperation newCIMAPFolderStatusOperation(mailcore::IMAPFolderStatusOperation *operation){
    CIMAPFolderStatusOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    
    self.status = &status;
    
    return self;
}

mailcore::IMAPFolderStatusOperation * cast(CIMAPFolderStatusOperation self) {
    return reinterpret_cast<mailcore::IMAPFolderStatusOperation *>(self.baseOperation.cOperation.nativeInstance);
}

void deleteCIMAPFolderStatusOperation(CIMAPFolderStatusOperation operation) {
    
}

CIMAPFolderStatus status(CIMAPFolderStatusOperation self) {
    return newCIMAPFolderStatus(cast(self)->status());
}
