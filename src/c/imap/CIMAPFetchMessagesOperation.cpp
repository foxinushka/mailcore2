#include "CIMAPFetchMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchMessagesOperation
#define structName CIMAPFetchMessagesOperation

CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation_new(mailcore::IMAPFetchMessagesOperation *operationRef){
    CIMAPFetchMessagesOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    return self;
}

void CIMAPFetchMessagesOperation_release(CIMAPFetchMessagesOperation operation) {

}

CArray CIMAPFetchMessagesOperation_messages(struct CIMAPFetchMessagesOperation self){
    return CArray_new(self.instance->messages());
}

CIndexSet CIMAPFetchMessagesOperation_vanishedMessages(struct CIMAPFetchMessagesOperation self){
    return CIndexSet_new(self.instance->vanishedMessages());
}

CArray CIMAPFetchMessagesOperation_extraHeaders(struct CIMAPFetchMessagesOperation self){
    return CArray_new(self.instance->extraHeaders());
}
void CIMAPFetchMessagesOperation_setExtraHeaders(struct CIMAPFetchMessagesOperation self, CArray array){
    self.instance->setExtraHeaders(array.instance);
}
