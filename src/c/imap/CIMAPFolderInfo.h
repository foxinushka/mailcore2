#ifndef CIMAPFolderInfo_h
#define CIMAPFolderInfo_h

#include "stdint.h"
#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderInfo;
}

extern "C" {
#endif
    
    struct CIMAPFolderInfo {
#ifdef __cplusplus
        mailcore::IMAPFolderInfo*   instance;
#else
        void*                       instance;
#endif
    };
    typedef struct CIMAPFolderInfo CIMAPFolderInfo;
    
    uint32_t        CIMAPFolderInfo_uidNext(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.uidNext(self:));
    
    void            CIMAPFolderInfo_setUidNext(struct CIMAPFolderInfo self, uint32_t uid)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.uidNext(self:newValue:));
    
    uint32_t        CIMAPFolderInfo_uidValidity(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.uidValidity(self:));
    
    void            CIMAPFolderInfo_setUidValidity(struct CIMAPFolderInfo self, uint32_t uid)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.uidValidity(self:newValue:));
    
    uint64_t        CIMAPFolderInfo_modSequenceValue(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.modSequenceValue(self:));
    
    void            CIMAPFolderInfo_setModSequenceValue(struct CIMAPFolderInfo self, uint64_t modSequenceValue)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.modSequenceValue(self:newValue:));
    
    int             CIMAPFolderInfo_messageCount(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.messageCount(self:));
    
    void            CIMAPFolderInfo_setMessageCount(struct CIMAPFolderInfo self, int messageCount)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.messageCount(self:newValue:));
    
    uint32_t        CIMAPFolderInfo_firstUnseenUid(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.firstUnseenUid(self:));
    
    void            CIMAPFolderInfo_setFirstUnseenUid(struct CIMAPFolderInfo self, uint32_t firstUnseenUid)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.firstUnseenUid(self:newValue:));
    
    bool            CIMAPFolderInfo_allowsNewPermanentFlags(struct CIMAPFolderInfo self)
                    CF_SWIFT_NAME(getter:CIMAPFolderInfo.allowsNewPermanentFlags(self:));
    
    void            CIMAPFolderInfo_setAllowsNewPermanentFlags(struct CIMAPFolderInfo self, bool allowsNewPermanentFlags)
                    CF_SWIFT_NAME(setter:CIMAPFolderInfo.allowsNewPermanentFlags(self:newValue:));
    
    void            CIMAPFolderInfo_release(CIMAPFolderInfo self)
                    CF_SWIFT_NAME(CIMAPFolderInfo.release(self:));
    
#ifdef __cplusplus
}

CIMAPFolderInfo CIMAPFolderInfo_new(mailcore::IMAPFolderInfo *folder);
#endif

#endif /* CIMAPFolderInfo_h */
