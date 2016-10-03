#include "CIMAPAppendMessageOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPAppendMessageOperation
#define structName CIMAPAppendMessageOperation

C_SYNTHESIZE_SCALAR(time_t, time_t, setDate, date)

uint32_t    createdUID(struct CIMAPAppendMessageOperation self);

CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *op){
    CIMAPAppendMessageOperation self;
    self.baseOperation = newCIMAPBaseOperation(op);
    self.instance = op;
    
    self.setDate = &setDate;
    self.date = &date;
    self.createdUID = &createdUID;
    
    return self;
}

uint32_t createdUID(struct CIMAPAppendMessageOperation self) {
    return self.instance->createdUID();
}

void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation operation) {

}
