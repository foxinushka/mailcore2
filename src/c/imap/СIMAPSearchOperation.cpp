#include "СIMAPSearchOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPSearchOperation
#define structName CIMAPSearchOperation

CIMAPSearchOperation CIMAPSearchOperation_new(mailcore::IMAPSearchOperation *operation){
    CIMAPSearchOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operation);
    self.instance = operation;
    return self;
}

void CIMAPSearchOperation_release(CIMAPSearchOperation operation) {

}

CIndexSet CIMAPSearchOperation_uids(CIMAPSearchOperation self) {
    return CIndexSet_new(self.instance->uids());
}
