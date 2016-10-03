#include "CIMAPCopyMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCopyMessagesOperation
#define structName CIMAPCopyMessagesOperation

CDictionary uidMapping(struct CIMAPCopyMessagesOperation self);

CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *ref){
    CIMAPCopyMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(ref);
    self.instance = ref;
    
    self.uidMapping = &uidMapping;
    
    return self;
}

void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation operation) {
    
}

CDictionary uidMapping(struct CIMAPCopyMessagesOperation self) {
    return newCDictionary(self.instance->uidMapping());
}
