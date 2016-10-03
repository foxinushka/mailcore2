#ifndef CIMAPPart_h
#define CIMAPPart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPPart;
}

extern "C" {
#endif
    
    struct CIMAPPart {
#ifdef __cplusplus
        mailcore::IMAPPart*     instance;
#else
        void*                   instance;
#endif
        CAbstractPart abstractPart;
        
        const UChar*    (*partID)(struct CIMAPPart self);
        void            (*setPartID)(struct CIMAPPart self, const UChar* partID);
        unsigned int    (*size)(struct CIMAPPart self);
        void            (*setSize)(struct CIMAPPart self, unsigned int size);
        Encoding        (*encoding)(struct CIMAPPart self);
        void            (*setEncoding)(struct CIMAPPart self, Encoding encoding);
        
        unsigned int    (*decodedSize)(struct CIMAPPart self);
    };
    typedef struct CIMAPPart CIMAPPart;
    
    CIMAPPart castCIMAPPart(CObject obj);
    
#ifdef __cplusplus
}

CIMAPPart newCIMAPPart(mailcore::IMAPPart *part);
#endif

#endif /* CIMAPPart_h */
