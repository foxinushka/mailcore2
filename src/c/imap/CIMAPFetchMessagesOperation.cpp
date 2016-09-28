#include "CIMAPFetchMessagesOperation.h"

#define nativeType mailcore::IMAPFetchMessagesOperation
#define structName CIMAPFetchMessagesOperation

CArray      messages(struct CIMAPFetchMessagesOperation *self);
CIndexSet   vanishedMessages(struct CIMAPFetchMessagesOperation *self);
CArray      extraHeaders(struct CIMAPFetchMessagesOperation *self);
void        setExtraHeaders(struct CIMAPFetchMessagesOperation *self, CArray *array);

CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operationRef){
    CIMAPFetchMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);

    self.messages = &messages;
    //self.vanishedMessages = &vanishedMessages;
    self.extraHeaders = &extraHeaders;
    self.setExtraHeaders = &setExtraHeaders;
    
    return self;
}

void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation *operation) {

}

CArray messages(struct CIMAPFetchMessagesOperation *self){
    return newCArray2(reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->messages());
}

CIndexSet vanishedMessages(struct CIMAPFetchMessagesOperation *self){
    return newCIndexSet(reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->vanishedMessages());
}

CArray extraHeaders(struct CIMAPFetchMessagesOperation *self){
    return newCArray2(reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->extraHeaders());
}
void setExtraHeaders(struct CIMAPFetchMessagesOperation *self, CArray *array){
    reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->setExtraHeaders(cast(array));
}
