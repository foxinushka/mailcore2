#ifndef CIMAPFolderStatus_h
#define CIMAPFolderStatus_h

#include "stdint.h"
#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderStatus;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFolderStatus, mailcore::IMAPFolderStatus)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderStatus)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, uidNext, setUidNext)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, uidValidity, setUidValidity)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, recentCount, setRecentCount)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, unseenCount, setUnseenCount)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, messageCount, setMessageCount)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint64_t, highestModSeqValue, setHighestModSeqValue)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFolderStatus_h */
