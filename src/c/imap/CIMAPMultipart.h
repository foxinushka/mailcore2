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
        
        const UChar*    (*partID)(struct CIMAPMultipart self);
        void            (*setPartID)(struct CIMAPMultipart self, const UChar* partID);
    };
    typedef struct CIMAPMultipart CIMAPMultipart;
    
    void deleteCIMAPMultipart(CIMAPMultipart self);
    
#ifdef __cplusplus
}

CIMAPMultipart newCIMAPMultipart(mailcore::IMAPMultipart *part);
#endif

#endif /* CIMAPMultipart_h */
