#ifndef CIMAPMultipart_h
#define CIMAPMultipart_h

#include "CBase.h"
#include "CAbstractMultipart.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMultipart;
}

extern "C" {
#endif
    
    struct CIMAPMultipart {
#ifdef __cplusplus
        mailcore::IMAPMultipart*    instance;
#else
        void*                       instance;
#endif
        CAbstractMultipart abstractMultipart;
    };
    typedef struct CIMAPMultipart CIMAPMultipart;
    
    const UChar*    CIMAPMultipart_partID(struct CIMAPMultipart self)
                    CF_SWIFT_NAME(getter:CIMAPMultipart.partID(self:));
    
    void            CIMAPMultipart_setPartID(struct CIMAPMultipart self, const UChar* partID)
                    CF_SWIFT_NAME(setter:CIMAPMultipart.partID(self:newValue:));
    
    void            CIMAPMultipart_release(CIMAPMultipart self);
                    CF_SWIFT_NAME(CIMAPMultipart.release(self:));
    
#ifdef __cplusplus
}

CIMAPMultipart CIMAPMultipart_new(mailcore::IMAPMultipart *part);
#endif

#endif /* CIMAPMultipart_h */
