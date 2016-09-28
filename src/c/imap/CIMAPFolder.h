#ifndef CIMAPFolder_h
#define CIMAPFolder_h

#include <stdio.h>

#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFolder {
        ref nativeInstance;
        
        const UChar*    (*path)(struct CIMAPFolder *self);
        void            (*setPath)(struct CIMAPFolder *self, const UChar* path);
        char            (*delimiter)(struct CIMAPFolder *self);
        void            (*setDelimiter)(struct CIMAPFolder *self, char delimiter);
        IMAPFolderFlag  (*flags)(struct CIMAPFolder *self);
        void            (*setFlags)(struct CIMAPFolder *self, IMAPFolderFlag flags);
    };
    typedef struct CIMAPFolder CIMAPFolder;
    
    void deleteCIMAPFolder(CIMAPFolder *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPFolder newCIMAPFolder(mailcore::IMAPFolder *folder);
mailcore::IMAPFolder * cast(CIMAPFolder *self);
#endif

#endif /* CIMAPFolder_h */
