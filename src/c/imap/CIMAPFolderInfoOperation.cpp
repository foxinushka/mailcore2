#include "CIMAPFolderInfoOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFolderInfoOperation
#define structName CIMAPFolderInfoOperation

CIMAPFolderInfo info(struct CIMAPFolderInfoOperation self);

CIMAPFolderInfoOperation newCIMAPFolderInfoOperation(mailcore::IMAPFolderInfoOperation *operation){
    CIMAPFolderInfoOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    self.instance = operation;
    
    self.info = &info;
    
    return self;
}

void deleteCIMAPFolderInfoOperation(CIMAPFolderInfoOperation operation) {
    
}

CIMAPFolderInfo info(CIMAPFolderInfoOperation self) {
    return newCIMAPFolderInfo(self.instance->info());
}
