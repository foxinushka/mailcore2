#include "CIMAPCheckAccountOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

const UChar*  CIMAPCheckAccountOperation_loginResponse(struct CIMAPCheckAccountOperation self) {
    mailcore::String* response = self.instance->loginResponse();
    return (response != NULL) ? response->unicodeCharacters() : NULL;
}

CData CIMAPCheckAccountOperation_loginUnparsedResponseData(struct CIMAPCheckAccountOperation self) {
    mailcore::Data* data = self.instance->loginUnparsedResponseData();
    if (data != NULL) {
        return CData_new(data->bytes(), data->length());
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
