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
        
        uint32_t        (*uidNext)(struct CIMAPFolderInfo self);
        void            (*setUidNext)(struct CIMAPFolderInfo self, uint32_t uid);
        uint32_t        (*uidValidity)(struct CIMAPFolderInfo self);
        void            (*setUidValidity)(struct CIMAPFolderInfo self, uint32_t uid);
        uint64_t        (*modSequenceValue)(struct CIMAPFolderInfo self);
        void            (*setModSequenceValue)(struct CIMAPFolderInfo self, uint64_t modSequenceValue);
        int             (*messageCount)(struct CIMAPFolderInfo self);
        void            (*setMessageCount)(struct CIMAPFolderInfo self, int messageCount);
        uint32_t        (*firstUnseenUid)(struct CIMAPFolderInfo self);
        void            (*setFirstUnseenUid)(struct CIMAPFolderInfo self, uint32_t firstUnseenUid);
        bool            (*allowsNewPermanentFlags)(struct CIMAPFolderInfo self);
        void            (*setAllowsNewPermanentFlags)(struct CIMAPFolderInfo self, bool allowsNewPermanentFlags);
    };
    typedef struct CIMAPFolderInfo CIMAPFolderInfo;
    
    void deleteCIMAPFolderInfo(CIMAPFolderInfo self);
    
#ifdef __cplusplus
}

CIMAPFolderInfo newCIMAPFolderInfo(mailcore::IMAPFolderInfo *folder);
#endif

#endif /* CIMAPFolderInfo_h */