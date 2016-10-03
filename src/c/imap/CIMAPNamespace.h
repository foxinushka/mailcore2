#ifndef MAILCORE_CIMAP_NAMESPACE_H
#define MAILCORE_CIMAP_NAMESPACE_H

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPNamespace;
}

extern "C" {
#endif
    
    struct CIMAPNamespace {
#ifdef __cplusplus
        mailcore::IMAPNamespace*    instance;
#else
        void*                       instance;
#endif
        
        const UChar*    (*mainPrefix)(struct CIMAPNamespace self);
        char            (*mainDelimiter)(struct CIMAPNamespace self);
        CArray          (*prefixes)(struct CIMAPNamespace self);
        const UChar*    (*pathForComponents)(struct CIMAPNamespace self, CArray components);
        const UChar*    (*pathForComponentsAndPrefix)(struct CIMAPNamespace self, CArray components, const UChar* prefix);
        CArray          (*componentsFromPath)(struct CIMAPNamespace self, const UChar* path);
        bool            (*containsFolderPath)(struct CIMAPNamespace self, const UChar* path);
        
    };
    typedef struct CIMAPNamespace CIMAPNamespace;

    CIMAPNamespace newCIMAPNamespace(const UChar* prefix, char delimiter);
    void deleteCIMAPNamespace(CIMAPNamespace self);

#ifdef __cplusplus
}

CIMAPNamespace newCIMAPNamespace(mailcore::IMAPNamespace *folder);
#endif

#endif
