#include "CIMAPCustomCommandOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

const UChar* CIMAPCustomCommandOperation_response(struct CIMAPCustomCommandOperation self) {
    return self.instance->response()->unicodeCharacters();
}

CIMAPCustomCommandOperation CIMAPCustomCommandOperation_new(mailcore::IMAPCustomCommandOperation *operationRef){
    CIMAPCustomCommandOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPCustomCommandOperation_release(CIMAPCustomCommandOperation operation) {
    
}
