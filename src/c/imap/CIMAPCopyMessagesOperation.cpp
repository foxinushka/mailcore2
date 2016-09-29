#include "CIMAPCopyMessagesOperation.h"
#include "CBase+Private.h"

#define nativeType mailcore::IMAPCopyMessagesOperation
#define structName CIMAPCopyMessagesOperation

CDictionary uidMapping(struct CIMAPCopyMessagesOperation self);

CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *ref){
    CIMAPCopyMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(ref);
    
    self.uidMapping = &uidMapping;
    
    return self;
}

mailcore::IMAPCopyMessagesOperation * cast(CIMAPCopyMessagesOperation self) {
    return reinterpret_cast<mailcore::IMAPCopyMessagesOperation*>(self.baseOperation.cOperation.nativeInstance);
}

void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation operation) {
    
}

CDictionary uidMapping(struct CIMAPCopyMessagesOperation self) {
    return newCDictionary(cast(self)->uidMapping());
}
