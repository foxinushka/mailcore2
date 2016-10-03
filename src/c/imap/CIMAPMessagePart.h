#ifndef CIMAPMessagePart_h
#define CIMAPMessagePart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessagePart;
}

extern "C" {
#endif
    
    struct CIMAPMessagePart {
#ifdef __cplusplus
        mailcore::IMAPMessagePart*  instance;
#else
        void*                       instance;
#endif
        CAbstractMessagePart abstractMessagePart;
        
        const UChar*    (*partID)(struct CIMAPMessagePart self);
        void            (*setPartID)(struct CIMAPMessagePart self, const UChar* partID);
    };
    typedef struct CIMAPMessagePart CIMAPMessagePart;
    
    void deleteCIMAPMessagePart(CIMAPMessagePart self);
    
#ifdef __cplusplus
}

CIMAPMessagePart newCIMAPMessagePart(mailcore::IMAPMessagePart *part);
#endif

#endif /* CIMAPMessagePart_h */
