#include "CIMAPFolderStatus.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolderStatus
#define structName CIMAPFolderStatus

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidNext, uidNext)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUidValidity, uidValidity)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setRecentCount, recentCount)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUnseenCount, unseenCount)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setMessageCount, messageCount)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setHighestModSeqValue, highestModSeqValue)
