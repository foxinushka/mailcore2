#include "CIMAPFetchContentOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPFetchContentOperation
#define structName CIMAPFetchContentOperation

CData data(struct CIMAPFetchContentOperation self);

CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operationRef){
    CIMAPFetchContentOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    
    self.data = &data;
    
    return self;
}

mailcore::IMAPFetchContentOperation* cast(CIMAPFetchContentOperation self) {
    return reinterpret_cast<mailcore::IMAPFetchContentOperation*>(self.baseOperation.cOperation.nativeInstance);
}

extern "C" void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation operation) {

}

CData data(struct CIMAPFetchContentOperation self){
    mailcore::Data *data = cast(self)->data();
    CData cdata; 
    cdata.bytes = data->bytes();
    cdata.lenght = data->length();
    return cdata;
}
