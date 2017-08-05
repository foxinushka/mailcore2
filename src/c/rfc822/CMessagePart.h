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
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CMessagePart, mailcore::MessagePart)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMessagePart)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CMessagePart, MailCoreString, partID, setPartID)
    
#ifdef __cplusplus
}
#endif

#endif
