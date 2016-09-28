#ifndef CIMAPNamespaceItem_h
#define CIMAPNamespaceItem_h

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPNamespaceItem {
        ref nativeInstance;
        
        const UChar*        (*prefix)(struct CIMAPNamespaceItem self);
        void                (*setPrefix)(struct CIMAPNamespaceItem self, const UChar* prefix);
        char                (*delimiter)(struct CIMAPNamespaceItem self);
        void                (*setDelimiter)(struct CIMAPNamespaceItem self, char delimiter);
        const UChar*        (*pathForComponents)(struct CIMAPNamespaceItem self, CArray components);
        CArray              (*componentForPath)(struct CIMAPNamespaceItem self, const UChar* path);
        bool                (*containsFolder)(struct CIMAPNamespaceItem self, const UChar* folder);
    };
    typedef struct CIMAPNamespaceItem CIMAPNamespaceItem;
    
    CIMAPNamespaceItem newCIMAPNamespaceItem(const UChar* prefix, char delimiter);
    void deleteCIMAPNamespaceItem(CIMAPNamespaceItem self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPNamespaceItem newCIMAPNamespaceItem(mailcore::IMAPNamespaceItem *folder);
mailcore::IMAPNamespaceItem * cast(CIMAPNamespaceItem self);
#endif

#endif /* CIMAPNamespaceItem_h */
