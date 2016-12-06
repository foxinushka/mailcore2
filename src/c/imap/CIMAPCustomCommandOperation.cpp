#include "CIMAPCustomCommandOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

const UChar* response(struct CIMAPCustomCommandOperation self) {
    return self.instance->response()->unicodeCharacters();
}

CIMAPCustomCommandOperation newCIMAPCustomCommandOperation(mailcore::IMAPCustomCommandOperation *operationRef){
    CIMAPCustomCommandOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.response = &response;
    
    return self;
}

void deleteCIMAPCustomCommandOperation(CIMAPCustomCommandOperation operation) {
    
}
