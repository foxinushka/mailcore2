#include "CIMAPFetchParsedContentOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchParsedContentOperation
#define structName CIMAPFetchParsedContentOperation

CIMAPFetchParsedContentOperation CIMAPFetchParsedContentOperation_new(mailcore::IMAPFetchParsedContentOperation *operationRef){
    CIMAPFetchParsedContentOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPFetchParsedContentOperation_release(CIMAPFetchParsedContentOperation operation) {
    
}

CMessageParser CIMAPFetchParsedContentOperation_parser(struct CIMAPFetchParsedContentOperation self) {
    return CMessageParser_new(self.instance->parser());
}
