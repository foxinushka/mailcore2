#include "CIMAPFetchMessagesOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPFetchMessagesOperation
#define structName CIMAPFetchMessagesOperation

CArray      messages(struct CIMAPFetchMessagesOperation self);
CIndexSet   vanishedMessages(struct CIMAPFetchMessagesOperation self);
CArray      extraHeaders(struct CIMAPFetchMessagesOperation self);
void        setExtraHeaders(struct CIMAPFetchMessagesOperation self, CArray array);

CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operationRef){
    CIMAPFetchMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);

    self.messages = &messages;
    self.vanishedMessages = &vanishedMessages;
    self.extraHeaders = &extraHeaders;
    self.setExtraHeaders = &setExtraHeaders;
    
    return self;
}

mailcore::IMAPFetchMessagesOperation* cast(CIMAPFetchMessagesOperation self) {
    return reinterpret_cast<mailcore::IMAPFetchMessagesOperation*>(self.baseOperation.cOperation.nativeInstance);
}

void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation operation) {

}

CArray messages(struct CIMAPFetchMessagesOperation self){
    return newCArray(cast(self)->messages());
}

CIndexSet vanishedMessages(struct CIMAPFetchMessagesOperation self){
    return newCIndexSet(cast(self)->vanishedMessages());
}

CArray extraHeaders(struct CIMAPFetchMessagesOperation self){
    return newCArray(cast(self)->extraHeaders());
}
void setExtraHeaders(struct CIMAPFetchMessagesOperation self, CArray array){
    cast(self)->setExtraHeaders(cast(array));
}
