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
    };
    typedef struct CIMAPPart CIMAPPart;
    
    const UChar*    CIMAPPart_partID(struct CIMAPPart self)
                    CF_SWIFT_NAME(getter:CIMAPPart.partID(self:));
    
    void            CIMAPPart_setPartID(struct CIMAPPart self, const UChar* partID)
                    CF_SWIFT_NAME(setter:CIMAPPart.partID(self:newValue:));
    
    unsigned int    CIMAPPart_size(struct CIMAPPart self)
                    CF_SWIFT_NAME(getter:CIMAPPart.size(self:));
    
    void            CIMAPPart_setSize(struct CIMAPPart self, unsigned int size)
                    CF_SWIFT_NAME(setter:CIMAPPart.size(self:newValue:));
    
    Encoding        CIMAPPart_encoding(struct CIMAPPart self)
                    CF_SWIFT_NAME(getter:CIMAPPart.encoding(self:));
    
    void            CIMAPPart_setEncoding(struct CIMAPPart self, Encoding encoding)
                    CF_SWIFT_NAME(setter:CIMAPPart.encoding(self:newValue:));
    
    unsigned int    CIMAPPart_decodedSize(struct CIMAPPart self)
                    CF_SWIFT_NAME(CIMAPPart.decodedSize(self:));
    
    CIMAPPart       CIMAPPart_castCIMAPPart(CObject obj)
                    CF_SWIFT_NAME(CIMAPPart.init(cobject:));
    
#ifdef __cplusplus
}

CIMAPPart CIMAPPart_new(mailcore::IMAPPart *part);
#endif

#endif /* CIMAPPart_h */
