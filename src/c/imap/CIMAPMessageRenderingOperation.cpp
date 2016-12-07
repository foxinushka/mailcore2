#include "CIMAPMessageRenderingOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPMessageRenderingOperation
#define structName CIMAPMessageRenderingOperation

const UChar*    result(struct CIMAPMessageRenderingOperation self);

CIMAPMessageRenderingOperation newCIMAPMessageRenderingOperation(mailcore::IMAPMessageRenderingOperation *operationRef){
    CIMAPMessageRenderingOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.result = &result;
    
    return self;
}

void deleteCIMAPMessageRenderingOperation(CIMAPMessageRenderingOperation operation) {
    
}

const UChar* result(struct CIMAPMessageRenderingOperation self) {
    return self.instance->result()->unicodeCharacters();
}
