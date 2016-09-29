#include "CIMAPAppendMessageOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPAppendMessageOperation
#define structName CIMAPAppendMessageOperation

C_SYNTHESIZE_SCALAR(time_t, time_t, setDate, date)

uint32_t    createdUID(struct CIMAPAppendMessageOperation self);

CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *op){
    CIMAPAppendMessageOperation self;
    self.baseOperation = newCIMAPBaseOperation(op);
    
    self.setDate = &setDate;
    self.date = &date;
    self.createdUID = &createdUID;
    
    return self;
}

mailcore::IMAPAppendMessageOperation* cast(CIMAPAppendMessageOperation self) {
    return reinterpret_cast<mailcore::IMAPAppendMessageOperation*>(self.baseOperation.cOperation.nativeInstance);
}

uint32_t createdUID(struct CIMAPAppendMessageOperation self) {
    return cast(self)->createdUID();
}

void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation operation) {

}
