#include "CIMAPFetchParsedContentOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchParsedContentOperation
#define structName CIMAPFetchParsedContentOperation

CMessageParser parser(struct CIMAPFetchParsedContentOperation self);

CIMAPFetchParsedContentOperation newCIMAPFetchParsedContentOperation(mailcore::IMAPFetchParsedContentOperation *operationRef){
    CIMAPFetchParsedContentOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.parser = &parser;
    
    return self;
}

void deleteCIMAPFetchNamespaceOperation(CIMAPFetchParsedContentOperation operation) {
    
}

CMessageParser parser(struct CIMAPFetchParsedContentOperation self) {
    return newCMessageParser(self.instance->parser());
}
