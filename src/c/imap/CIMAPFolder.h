#ifndef CIMAPFolder_h
#define CIMAPFolder_h

#include <stdio.h>

#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"

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
    };
    typedef struct CIMAPFolder CIMAPFolder;
    
    const UChar*    CIMAPFolder_path(struct CIMAPFolder self)
                    CF_SWIFT_NAME(getter:CIMAPFolder.path(self:));
    
    void            CIMAPFolder_setPath(struct CIMAPFolder self, const UChar* path)
                    CF_SWIFT_NAME(setter:CIMAPFolder.path(self:newValue:));
    
    char            CIMAPFolder_delimiter(struct CIMAPFolder self)
                    CF_SWIFT_NAME(getter:CIMAPFolder.delimiter(self:));
    
    void            CIMAPFolder_setDelimiter(struct CIMAPFolder self, char delimiter)
                    CF_SWIFT_NAME(setter:CIMAPFolder.delimiter(self:newValue:));
    
    IMAPFolderFlag  CIMAPFolder_flags(struct CIMAPFolder self)
                    CF_SWIFT_NAME(getter:CIMAPFolder.flags(self:));
    
    void            CIMAPFolder_setFlags(struct CIMAPFolder self, IMAPFolderFlag flags)
                    CF_SWIFT_NAME(setter:CIMAPFolder.flags(self:newValue:));
    
    CObject         CIMAPFolder_castToCObject(struct CIMAPFolder self)
                    CF_SWIFT_NAME(CIMAPFolder.castToCObject(self:));
    
    CIMAPFolder     CIMAPFolder_castFromCObject(CObject obj)
                    CF_SWIFT_NAME(CIMAPFolder.init(cobject:));
    
    void            CIMAPFolder_release(CIMAPFolder self)
                    CF_SWIFT_NAME(CIMAPFolder.release(self:));
#ifdef __cplusplus
}

CIMAPFolder CIMAPFolder_new(mailcore::IMAPFolder *folder);
#endif

#endif /* CIMAPFolder_h */
