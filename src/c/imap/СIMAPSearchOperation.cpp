#include "СIMAPSearchOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPSearchOperation
#define structName CIMAPSearchOperation

CIndexSet uids(struct CIMAPSearchOperation self);

CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *operation){
    CIMAPSearchOperation self;
    self.baseOperation = newCIMAPBaseOperation(operation);
    self.instance = operation;
    
    self.uids = &uids;
    
    return self;
}

void deleteCIMAPSearchOperation(CIMAPSearchOperation operation) {

}

CIndexSet uids(CIMAPSearchOperation self) {
    return newCIndexSet(self.instance->uids());
}
