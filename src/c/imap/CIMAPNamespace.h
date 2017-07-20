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
    };
    typedef struct CIMAPNamespace CIMAPNamespace;

    const UChar*    CIMAPNamespace_mainPrefix(struct CIMAPNamespace self)
                    CF_SWIFT_NAME(CIMAPNamespace.mainPrefix(self:));
    
    char            CIMAPNamespace_mainDelimiter(struct CIMAPNamespace self)
                    CF_SWIFT_NAME(CIMAPNamespace.mainDelimiter(self:));
    
    CArray          CIMAPNamespace_prefixes(struct CIMAPNamespace self)
                    CF_SWIFT_NAME(CIMAPNamespace.prefixes(self:));
    
    const UChar*    CIMAPNamespace_pathForComponents(struct CIMAPNamespace self, CArray components)
                    CF_SWIFT_NAME(CIMAPNamespace.pathForComponents(self:components:));
    
    const UChar*    CIMAPNamespace_pathForComponentsAndPrefix(struct CIMAPNamespace self, CArray components, const UChar* prefix)
                    CF_SWIFT_NAME(CIMAPNamespace.pathForComponentsAndPrefix(self:components:prefix:));
    
    CArray          CIMAPNamespace_componentsFromPath(struct CIMAPNamespace self, const UChar* path)
                    CF_SWIFT_NAME(CIMAPNamespace.componentsFromPath(self:path:));
    
    bool            CIMAPNamespace_containsFolderPath(struct CIMAPNamespace self, const UChar* path)
                    CF_SWIFT_NAME(CIMAPNamespace.containsFolderPath(self:path:));
    
    CObject         CIMAPNamespace_castToCObject(struct CIMAPNamespace self)
                    CF_SWIFT_NAME(CIMAPNamespace.castToCObject(self:));
    
    CIMAPNamespace  CIMAPNamespace_castFromCObject(CObject obj)
                    CF_SWIFT_NAME(CIMAPNamespace.init(cobject:));
    
    CIMAPNamespace  CIMAPNamespace_new(const UChar* prefix, char delimiter)
                    CF_SWIFT_NAME(CIMAPNamespace.init(prefix:delimiter:));
    
    void            CIMAPNamespace_release(CIMAPNamespace self)
                    CF_SWIFT_NAME(CIMAPNamespace.release(self:));

#ifdef __cplusplus
}

CIMAPNamespace CIMAPNamespace_new(mailcore::IMAPNamespace *folder);
#endif

#endif
