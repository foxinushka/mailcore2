#include "CIMAPFetchContentOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchContentOperation
#define structName CIMAPFetchContentOperation

CIMAPFetchContentOperation CIMAPFetchContentOperation_new(mailcore::IMAPFetchContentOperation *operationRef){
    CIMAPFetchContentOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

extern "C" void CIMAPFetchContentOperation_release(CIMAPFetchContentOperation operation) {

}

CData CIMAPFetchContentOperation_data(struct CIMAPFetchContentOperation self){
    mailcore::Data *data = self.instance->data();
    CData cdata; 
    cdata.bytes = data->bytes();
    cdata.length = data->length();
    return cdata;
}
