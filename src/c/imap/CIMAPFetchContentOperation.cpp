#include "CIMAPFetchContentOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchContentOperation
#define structName CIMAPFetchContentOperation

CData data(struct CIMAPFetchContentOperation self);

CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operationRef){
    CIMAPFetchContentOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.data = &data;
    
    return self;
}

extern "C" void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation operation) {

}

CData data(struct CIMAPFetchContentOperation self){
    mailcore::Data *data = self.instance->data();
    CData cdata; 
    cdata.bytes = data->bytes();
    cdata.length = data->length();
    return cdata;
}
