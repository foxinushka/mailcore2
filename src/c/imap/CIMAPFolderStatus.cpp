#include "CIMAPFolderStatus.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolderStatus
#define structName CIMAPFolderStatus

C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidNext, uidNext)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidValidity, uidValidity)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setRecentCount, recentCount)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUnseenCount, unseenCount)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setMessageCount, messageCount)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setHighestModSeqValue, highestModSeqValue)


CIMAPFolderStatus newCIMAPFolderStatus(mailcore::IMAPFolderStatus *status) {
    CIMAPFolderStatus self;
    status->retain();
    self.nativeInstance = status;
    
    self.uidNext = &uidNext;
    self.setUidNext = &setUidNext;
    self.uidValidity = &uidValidity;
    self.setUidValidity = &setUidValidity;
    self.recentCount = &recentCount;
    self.setRecentCount = &setRecentCount;
    self.unseenCount = &unseenCount;
    self.setUnseenCount = &setUnseenCount;
    self.messageCount = &messageCount;
    self.setMessageCount = &setMessageCount;
    self.highestModSeqValue = &highestModSeqValue;
    self.setHighestModSeqValue = &setHighestModSeqValue;
    
    return self;
}

mailcore::IMAPFolderStatus * cast(CIMAPFolderStatus self) {
    return reinterpret_cast<mailcore::IMAPFolderStatus*>(self.nativeInstance);
}

void deleteCIMAPFolderStatus(CIMAPFolderStatus self) {
    C_SAFE_RELEASE(self);
}
