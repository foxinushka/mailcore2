#include "CIMAPFolderInfo.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolderInfo
#define structName CIMAPFolderInfo

C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidNext, uidNext)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidValidity, uidValidity)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setModSequenceValue, modSequenceValue)
C_SYNTHESIZE_SCALAR(int, int, setMessageCount, messageCount)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setFirstUnseenUid, firstUnseenUid)
C_SYNTHESIZE_BOOL(setAllowsNewPermanentFlags, allowsNewPermanentFlags);

CIMAPFolderInfo newCIMAPFolderInfo(mailcore::IMAPFolderInfo *info) {
    CIMAPFolderInfo self;
    info->retain();
    self.nativeInstance = info;
    
    self.uidNext = &uidNext;
    self.setUidNext = &setUidNext;
    self.uidValidity = &uidValidity;
    self.setUidValidity = &setUidValidity;
    self.modSequenceValue = &modSequenceValue;
    self.setModSequenceValue = &setModSequenceValue;
    self.messageCount = &messageCount;
    self.setMessageCount = &setMessageCount;
    self.firstUnseenUid = &firstUnseenUid;
    self.setFirstUnseenUid = &setFirstUnseenUid;
    self.allowsNewPermanentFlags = &allowsNewPermanentFlags;
    self.setAllowsNewPermanentFlags = &setAllowsNewPermanentFlags;
    
    return self;
}

mailcore::IMAPFolderInfo * cast(CIMAPFolderInfo self) {
    return reinterpret_cast<mailcore::IMAPFolderInfo*>(self.nativeInstance);
}

void deleteCIMAPFolderInfo(CIMAPFolderInfo self) {
    C_SAFE_RELEASE(self);
}

