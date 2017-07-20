#include "CIMAPFolderInfoOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFolderInfoOperation
#define structName CIMAPFolderInfoOperation

CIMAPFolderInfoOperation CIMAPFolderInfoOperation_new(mailcore::IMAPFolderInfoOperation *operation){
    CIMAPFolderInfoOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operation);
    self.instance = operation;
    return self;
}

void CIMAPFolderInfoOperation_release(CIMAPFolderInfoOperation operation) {
    
}

CIMAPFolderInfo CIMAPFolderInfoOperation_info(CIMAPFolderInfoOperation self) {
    return CIMAPFolderInfo_new(self.instance->info());
}
