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
    };
    typedef struct CIMAPMessagePart CIMAPMessagePart;
    
    MailCoreString    CIMAPMessagePart_partID(struct CIMAPMessagePart self)
                    CF_SWIFT_NAME(getter:CIMAPMessagePart.partID(self:));
    
    void            CIMAPMessagePart_setPartID(struct CIMAPMessagePart self, MailCoreString partID)
                    CF_SWIFT_NAME(setter:CIMAPMessagePart.partID(self:newValue:));
    
    void            CIMAPMessagePart_release(CIMAPMessagePart self)
                    CF_SWIFT_NAME(CIMAPMessagePart.release(self:));
    
#ifdef __cplusplus
}

CIMAPMessagePart CIMAPMessagePart_new(mailcore::IMAPMessagePart *part);
#endif

#endif /* CIMAPMessagePart_h */
