#include "CIMAPAppendMessageOperation.h"

#define nativeType mailcore::IMAPAppendMessageOperation
#define structName CIMAPAppendMessageOperation

void        setDate(struct CIMAPAppendMessageOperation *self, time_t date);
time_t      date(struct CIMAPAppendMessageOperation *self);
uint32_t    createdUID(struct CIMAPAppendMessageOperation *self);

extern "C" CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *op){
    CIMAPAppendMessageOperation self;
    self.baseOperation = newCIMAPBaseOperation(op);
    
    self.setDate = &setDate;
    self.date = &date;
    self.createdUID = &createdUID;
    
    return self;
}

void setDate(struct CIMAPAppendMessageOperation *self, time_t date) {
    reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->setDate(date);
}

time_t date(struct CIMAPAppendMessageOperation *self) {
    return reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->date();
}

uint32_t createdUID(struct CIMAPAppendMessageOperation *self) {
    return reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->createdUID();
}

extern "C" void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation *operation) {

}
