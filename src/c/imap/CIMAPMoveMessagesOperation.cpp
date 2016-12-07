#include "CIMAPMoveMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPMoveMessagesOperation
#define structName CIMAPMoveMessagesOperation

CDictionary uidMapping(struct CIMAPMoveMessagesOperation self);

CIMAPMoveMessagesOperation newCIMAPMoveMessagesOperation(mailcore::IMAPMoveMessagesOperation *operationRef){
    CIMAPMoveMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(operationRef);
    self.instance = operationRef;
    
    self.uidMapping = &uidMapping;
    
    return self;
}

void deleteCIMAPMoveMessagesOperation(CIMAPMoveMessagesOperation operation) {
    
}

CDictionary uidMapping(struct CIMAPMoveMessagesOperation self) {
    return newCDictionary(self.instance->uidMapping());
}
