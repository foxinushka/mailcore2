#include "CIMAPMoveMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPMoveMessagesOperation
#define structName CIMAPMoveMessagesOperation

CIMAPMoveMessagesOperation CIMAPMoveMessagesOperation_new(mailcore::IMAPMoveMessagesOperation *operationRef){
    CIMAPMoveMessagesOperation self;
    self.baseOperation = CIMAPBaseOperation_new(operationRef);
    self.instance = operationRef;
    return self;
}

void CIMAPMoveMessagesOperation_release(CIMAPMoveMessagesOperation operation) {
    
}

CDictionary CIMAPMoveMessagesOperation_uidMapping(struct CIMAPMoveMessagesOperation self) {
    return CDictionary_new(self.instance->uidMapping());
}
