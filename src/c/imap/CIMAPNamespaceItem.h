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
    };
    typedef struct CIMAPNamespaceItem CIMAPNamespaceItem;
    
    const UChar*        CIMAPNamespaceItem_prefix(struct CIMAPNamespaceItem self)
                        CF_SWIFT_NAME(getter:CIMAPNamespaceItem.prefix(self:));
    
    void                CIMAPNamespaceItem_setPrefix(struct CIMAPNamespaceItem self, const UChar* prefix)
                        CF_SWIFT_NAME(setter:CIMAPNamespaceItem.prefix(self:newValue:));
    
    char                CIMAPNamespaceItem_delimiter(struct CIMAPNamespaceItem self)
                        CF_SWIFT_NAME(getter:CIMAPNamespaceItem.delimiter(self:));
    
    void                CIMAPNamespaceItem_setDelimiter(struct CIMAPNamespaceItem self, char delimiter)
                        CF_SWIFT_NAME(setter:CIMAPNamespaceItem.delimiter(self:newValue:));
    
    const UChar*        CIMAPNamespaceItem_pathForComponents(struct CIMAPNamespaceItem self, CArray components)
                        CF_SWIFT_NAME(CIMAPNamespaceItem.pathForComponents(self:components:));
    
    CArray              CIMAPNamespaceItem_componentForPath(struct CIMAPNamespaceItem self, const UChar* path)
                        CF_SWIFT_NAME(CIMAPNamespaceItem.componentForPath(self:path:));
    
    bool                CIMAPNamespaceItem_containsFolder(struct CIMAPNamespaceItem self, const UChar* folder)
                        CF_SWIFT_NAME(CIMAPNamespaceItem.containsFolder(self:folder:));
    
    CIMAPNamespaceItem  CIMAPNamespaceItem_new(const UChar* prefix, char delimiter)
                        CF_SWIFT_NAME(CIMAPNamespaceItem.init(prefix:delimiter:));

    void                CIMAPNamespaceItem_release(CIMAPNamespaceItem self)
                        CF_SWIFT_NAME(CIMAPNamespaceItem.release(self:));

    
#ifdef __cplusplus
}

CIMAPNamespaceItem CIMAPNamespaceItem_new(mailcore::IMAPNamespaceItem *folder);
#endif

#endif /* CIMAPNamespaceItem_h */
