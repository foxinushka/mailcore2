#include "CIMAPAppendMessageOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPAppendMessageOperation
#define structName CIMAPAppendMessageOperation

C_SYNTHESIZE_SCALAR(time_t, time_t, setDate, date)

CIMAPAppendMessageOperation CIMAPAppendMessageOperation_new(mailcore::IMAPAppendMessageOperation *op){
    CIMAPAppendMessageOperation self;
    self.baseOperation = CIMAPBaseOperation_new(op);
    self.instance = op;
    return self;
}

uint32_t CIMAPAppendMessageOperation_createdUID(struct CIMAPAppendMessageOperation self) {
    return self.instance->createdUID();
}

void CIMAPAppendMessageOperation_release(CIMAPAppendMessageOperation operation) {

}
