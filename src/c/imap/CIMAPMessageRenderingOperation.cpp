#include "CIMAPMessageRenderingOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPMessageRenderingOperation
#define structName CIMAPMessageRenderingOperation

CIMAPMessageRenderingOperation CIMAPMessageRenderingOperation_new(mailcore::IMAPMessageRenderingOperation *operationRef){
    CIMAPMessageRenderingOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPMessageRenderingOperation_release(CIMAPMessageRenderingOperation operation) {
    
}

MailCoreString CIMAPMessageRenderingOperation_result(struct CIMAPMessageRenderingOperation self) {
    return MailCoreString_new(self.instance->result());
}
