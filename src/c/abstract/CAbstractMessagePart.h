#ifndef MAILCORE_CABSTRACT_MESSAGE_PART_H
#define MAILCORE_CABSTRACT_MESSAGE_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"
#include "CMessageHeader.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessagePart;
}

extern "C" {
#endif
    
    typedef struct CAbstractMessagePart {
#ifdef __cplusplus
        mailcore::AbstractMessagePart*  instance;
#else
        void*                           instance;
#endif
        CAbstractPart abstractPart;
    } CAbstractMessagePart;
    
    struct CMessageHeader           CAbstractMessagePart_header(struct CAbstractMessagePart self)
                                    CF_SWIFT_NAME(getter:CAbstractMessagePart.header(self:));
    
    void                            CAbstractMessagePart_setHeader(struct CAbstractMessagePart self, struct CMessageHeader header)
                                    CF_SWIFT_NAME(setter:CAbstractMessagePart.header(self:newValue:));
    
    struct CAbstractPart            CAbstractMessagePart_mainPart(struct CAbstractMessagePart self)
                                    CF_SWIFT_NAME(getter:CAbstractMessagePart.mainPart(self:));
    
    void                            CAbstractMessagePart_setMainPart(struct CAbstractMessagePart self, struct CAbstractPart part)
                                    CF_SWIFT_NAME(setter:CAbstractMessagePart.mainPart(self:newValue:));
    
#ifdef __cplusplus
}

CAbstractMessagePart CAbstractMessagePart_new(mailcore::AbstractMessagePart *part);
#endif

#endif
