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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderStatus)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, uidNext, setUidNext)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, uidValidity, setUidValidity)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, recentCount, setRecentCount)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, unseenCount, setUnseenCount)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint32_t, messageCount, setMessageCount)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderStatus, uint64_t, highestModSeqValue, setHighestModSeqValue)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFolderStatus_h */
