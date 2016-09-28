#include "CIMAPFolderInfoOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPFolderInfoOperation
#define structName CIMAPFolderInfoOperation

CIMAPFolderInfo info(struct CIMAPFolderInfoOperation self);

CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operation){
    CIMAPFolderInfoOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    
    self.info = &info;
    
    return self;
}

mailcore::IMAPFolderInfoOperation * cast(CIMAPFolderInfoOperation self) {
    return reinterpret_cast<mailcore::IMAPFolderInfoOperation *>(self.baseOperation.cOperation.nativeInstance);
}

void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation operation) {
    
}

CIMAPFolderInfo info(CIMAPFolderInfoOperation self) {
    return newCIMAPFolderInfo(cast(self)->info());
}
