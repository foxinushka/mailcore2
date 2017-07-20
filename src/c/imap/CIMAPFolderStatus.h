#ifndef CIMAPFolderStatus_h
#define CIMAPFolderStatus_h

#include "stdint.h"
#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolderStatus;
}

extern "C" {
#endif
    
    struct CIMAPFolderStatus {
#ifdef __cplusplus
        mailcore::IMAPFolderStatus*     instance;
#else
        void*                           instance;
#endif
    };
    typedef struct CIMAPFolderStatus CIMAPFolderStatus;
    
    uint32_t        CIMAPFolderStatus_uidNext(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.uidNext(self:));
    
    void            CIMAPFolderStatus_setUidNext(struct CIMAPFolderStatus self, uint32_t uid)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.uidNext(self:newValue:));
    
    uint32_t        CIMAPFolderStatus_uidValidity(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.uidValidity(self:));
    
    void            CIMAPFolderStatus_setUidValidity(struct CIMAPFolderStatus self, uint32_t uid)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.uidValidity(self:newValue:));
    
    uint32_t        CIMAPFolderStatus_recentCount(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.recentCount(self:));
    
    void            CIMAPFolderStatus_setRecentCount(struct CIMAPFolderStatus self, uint32_t recentCount)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.recentCount(self:newValue:));
    
    uint32_t        CIMAPFolderStatus_unseenCount(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.unseenCount(self:));
    
    void            CIMAPFolderStatus_setUnseenCount(struct CIMAPFolderStatus self, uint32_t messageCount)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.unseenCount(self:newValue:));
    
    uint32_t        CIMAPFolderStatus_messageCount(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.messageCount(self:));
    
    void            CIMAPFolderStatus_setMessageCount(struct CIMAPFolderStatus self, uint32_t messageCount)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.messageCount(self:newValue:));
    
    uint64_t        CIMAPFolderStatus_highestModSeqValue(struct CIMAPFolderStatus self)
                    CF_SWIFT_NAME(getter:CIMAPFolderStatus.highestModSeqValue(self:));
    
    void            CIMAPFolderStatus_setHighestModSeqValue(struct CIMAPFolderStatus self, uint64_t highestModSeqValue)
                    CF_SWIFT_NAME(setter:CIMAPFolderStatus.highestModSeqValue(self:newValue:));
    
    void            CIMAPFolderStatus_release(CIMAPFolderStatus self)
                    CF_SWIFT_NAME(CIMAPFolderStatus.release(self:));
    
#ifdef __cplusplus
}

CIMAPFolderStatus CIMAPFolderStatus_new(mailcore::IMAPFolderStatus *folder);
#endif

#endif /* CIMAPFolderStatus_h */
