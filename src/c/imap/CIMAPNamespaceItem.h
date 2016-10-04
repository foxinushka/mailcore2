#ifndef CIMAPNamespaceItem_h
#define CIMAPNamespaceItem_h

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPNamespaceItem;
}

extern "C" {
#endif
    
    struct CIMAPNamespaceItem {
#ifdef __cplusplus
        mailcore::IMAPNamespaceItem*    instance;
#else
        void*                           instance;
#endif
        
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

CIMAPNamespaceItem newCIMAPNamespaceItem(mailcore::IMAPNamespaceItem *folder);
#endif

#endif /* CIMAPNamespaceItem_h */
