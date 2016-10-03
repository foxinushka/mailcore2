#ifndef CIMAPFolder_h
#define CIMAPFolder_h

#include <stdio.h>

#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolder;
}

extern "C" {
#endif
    
    struct CIMAPFolder {
#ifdef __cplusplus
        mailcore::IMAPFolder*   instance;
#else
        void*                   instance;
#endif
        
        const UChar*    (*path)(struct CIMAPFolder self);
        void            (*setPath)(struct CIMAPFolder self, const UChar* path);
        char            (*delimiter)(struct CIMAPFolder self);
        void            (*setDelimiter)(struct CIMAPFolder self, char delimiter);
        IMAPFolderFlag  (*flags)(struct CIMAPFolder self);
        void            (*setFlags)(struct CIMAPFolder self, IMAPFolderFlag flags);
    };
    typedef struct CIMAPFolder CIMAPFolder;
    
    void deleteCIMAPFolder(CIMAPFolder self);
    
#ifdef __cplusplus
}

CIMAPFolder newCIMAPFolder(mailcore::IMAPFolder *folder);
#endif

#endif /* CIMAPFolder_h */
