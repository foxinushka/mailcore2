#include "CIMAPCopyMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPCopyMessagesOperation
#define structName CIMAPCopyMessagesOperation

CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation_new(mailcore::IMAPCopyMessagesOperation *ref){
    CIMAPCopyMessagesOperation self;
    self.baseOperation = CIMAPBaseOperation_new(ref);
    self.instance = ref;
    return self;
}

void CIMAPCopyMessagesOperation_release(CIMAPCopyMessagesOperation operation) {
    
}

CDictionary CIMAPCopyMessagesOperation_uidMapping(struct CIMAPCopyMessagesOperation self) {
    return CDictionary_new(self.instance->uidMapping());
}
