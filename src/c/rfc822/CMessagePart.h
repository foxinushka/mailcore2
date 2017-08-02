#ifndef MAILCORE_C_MESSAGE_PART_H
#define MAILCORE_C_MESSAGE_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"
#include "CMessageHeader.h"
#include "CAbstractMessagePart.h"

#ifdef __cplusplus

namespace mailcore {
    class MessagePart;
}

extern "C" {
#endif
    
    typedef struct CMessagePart {
#ifdef __cplusplus
        mailcore::MessagePart*          instance;
#else
        void*                           instance;
#endif
        CAbstractMessagePart abstractMessagePart;
    } CMessagePart;
    
    MailCoreString                  CMessagePart_partID(struct CMessagePart self)
                                    CF_SWIFT_NAME(getter:CMessagePart.partID(self:));
    
    void                            CMessagePart_setPartID(struct CMessagePart self, MailCoreString  partID)
                                    CF_SWIFT_NAME(setter:CMessagePart.partID(self:newValue:));
    
#ifdef __cplusplus
}

CMessagePart CMessagePart_new(mailcore::MessagePart *part);
#endif

#endif
