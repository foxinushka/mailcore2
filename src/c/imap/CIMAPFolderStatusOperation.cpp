#include "CIMAPFolderStatusOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFolderStatusOperation
#define structName CIMAPFolderStatusOperation

CIMAPFolderStatusOperation CIMAPFolderStatusOperation_new(mailcore::IMAPFolderStatusOperation *operation){
    CIMAPFolderStatusOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operation);
    self.instance = operation;
    return self;
}

void CIMAPFolderStatusOperation_release(CIMAPFolderStatusOperation operation) {
    
}

CIMAPFolderStatus CIMAPFolderStatusOperation_status(CIMAPFolderStatusOperation self) {
    return CIMAPFolderStatus_new(self.instance->status());
}
