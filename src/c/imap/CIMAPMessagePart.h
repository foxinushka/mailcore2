#ifndef CIMAPMessagePart_h
#define CIMAPMessagePart_h

#include "CBase.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPMessagePart {
        CAbstractMessagePart abstractMessagePart;
        
        const UChar*    (*partID)(struct CIMAPMessagePart self);
        void            (*setPartID)(struct CIMAPMessagePart self, const UChar* partID);
    };
    typedef struct CIMAPMessagePart CIMAPMessagePart;
    
    void deleteCIMAPMessagePart(CIMAPMessagePart self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPMessagePart newCIMAPMessagePart(mailcore::IMAPMessagePart *part);
mailcore::IMAPMessagePart* cast(CIMAPMessagePart self);
#endif

#endif /* CIMAPMessagePart_h */
