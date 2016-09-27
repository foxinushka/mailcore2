#include "CIMAPCopyMessagesOperation.h"

#define nativeType mailcore::IMAPCopyMessagesOperation
#define structName CIMAPCopyMessagesOperation

CDictionary uidMapping(struct CIMAPCopyMessagesOperation *self);

extern "C" CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *ref){
    CIMAPCopyMessagesOperation self;
    self.baseOperation = newCIMAPBaseOperation(ref);
    
    self.uidMapping = &uidMapping;
    
    return self;
}

extern "C" void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation operation) {
    
}

CDictionary uidMapping(struct CIMAPCopyMessagesOperation *self) {
    return newCDictionary(reinterpret_cast<nativeType*>(self->baseOperation.cOperation.nativeInstance)->uidMapping());
}
