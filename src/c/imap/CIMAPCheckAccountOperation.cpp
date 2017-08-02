#include "CIMAPCheckAccountOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>
#include "CData.h"

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

MailCoreString  CIMAPCheckAccountOperation_loginResponse(struct CIMAPCheckAccountOperation self) {
    mailcore::String* response = self.instance->loginResponse();
    return MailCoreString_new(response);
}

CData CIMAPCheckAccountOperation_loginUnparsedResponseData(struct CIMAPCheckAccountOperation self) {
    mailcore::Data* data = self.instance->loginUnparsedResponseData();
    if (data != NULL) {
        return CData_new(data);
    }
    return CData_new(NULL, 0);
}

CIMAPCheckAccountOperation CIMAPCheckAccountOperation_new(mailcore::IMAPCheckAccountOperation *operationRef){
    CIMAPCheckAccountOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPCheckAccountOperation_release(CIMAPCheckAccountOperation operation) {
    
}
