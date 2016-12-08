#include "CIMAPCheckAccountOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

const UChar*  loginResponse(struct CIMAPCheckAccountOperation self) {
    return self.instance->loginResponse()->unicodeCharacters();
}

CData loginUnparsedResponseData(struct CIMAPCheckAccountOperation self) {
    mailcore::Data* data = self.instance->loginUnparsedResponseData();
    if (data != NULL) {
        return newCData(data->bytes(), data->length());
    }
    return newCData(NULL, 0);
}

CIMAPCheckAccountOperation newCIMAPCheckAccountOperation(mailcore::IMAPCheckAccountOperation *operationRef){
    CIMAPCheckAccountOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.loginResponse = &loginResponse;
    self.loginUnparsedResponseData = &loginUnparsedResponseData;
    
    return self;
}

void deleteCIMAPCheckAccountOperation(CIMAPCheckAccountOperation operation) {
    
}
