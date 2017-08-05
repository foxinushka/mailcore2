#ifndef CIMAPFolderInfo_h
#define CIMAPFolderInfo_h

#include "stdint.h"
#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderInfo;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFolderInfo, mailcore::IMAPFolderInfo)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolderInfo)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, uint32_t, uidNext, setUidNext)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, uint32_t, uidValidity, setUidValidity)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, uint64_t, modSequenceValue, setModSequenceValue)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, int, messageCount, setMessageCount)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, uint32_t, firstUnseenUid, setFirstUnseenUid)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolderInfo, bool, allowsNewPermanentFlags, setAllowsNewPermanentFlags)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFolderInfo_h */
