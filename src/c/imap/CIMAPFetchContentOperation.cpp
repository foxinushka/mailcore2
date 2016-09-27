#include "CIMAPFetchContentOperation.h"

#define nativeType mailcore::IMAPFetchContentOperation
#define structName CIMAPFetchContentOperation

CData data(struct CIMAPFetchContentOperation *self);

extern "C" CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operationRef){
    CIMAPFetchContentOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    
    self.data = &data;
    
    return self;
}

extern "C" void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation operation) {

}

CData data(struct CIMAPFetchContentOperation *self){
    mailcore::Data *data = reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->data();
    CData cdata; 
    cdata.bytes = data->bytes();
    cdata.lenght = data->length();
    return cdata;
}
