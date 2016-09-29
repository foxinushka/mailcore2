#ifndef CIMAPPart_h
#define CIMAPPart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPPart {
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
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPPart newCIMAPMessagePart(mailcore::IMAPPart *part);
mailcore::IMAPPart * cast(CIMAPPart self);
#endif

#endif /* CIMAPPart_h */
