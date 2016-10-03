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
        
        uint32_t        (*uidNext)(struct CIMAPFolderStatus self);
        void            (*setUidNext)(struct CIMAPFolderStatus self, uint32_t uid);
        uint32_t        (*uidValidity)(struct CIMAPFolderStatus self);
        void            (*setUidValidity)(struct CIMAPFolderStatus self, uint32_t uid);
        uint32_t        (*recentCount)(struct CIMAPFolderStatus self);
        void            (*setRecentCount)(struct CIMAPFolderStatus self, uint32_t recentCount);
        uint32_t        (*unseenCount)(struct CIMAPFolderStatus self);
        void            (*setUnseenCount)(struct CIMAPFolderStatus self, uint32_t messageCount);
        uint32_t        (*messageCount)(struct CIMAPFolderStatus self);
        void            (*setMessageCount)(struct CIMAPFolderStatus self, uint32_t messageCount);
        uint64_t        (*highestModSeqValue)(struct CIMAPFolderStatus self);
        void            (*setHighestModSeqValue)(struct CIMAPFolderStatus self, uint64_t highestModSeqValue);
    };
    typedef struct CIMAPFolderStatus CIMAPFolderStatus;
    
    void deleteCIMAPFolderStatus(CIMAPFolderStatus self);
    
#ifdef __cplusplus
}

CIMAPFolderStatus newCIMAPFolderStatus(mailcore::IMAPFolderStatus *folder);
#endif

#endif /* CIMAPFolderStatus_h */
