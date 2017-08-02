#include <MailCore/MCCore.h>
#include "CMessagePart.h"
#include "CBase+Private.h"

#define nativeType mailcore::MessagePart
#define structName CMessagePart

C_SYNTHESIZE_STRING(setPartID, partID)

CMessagePart CMessagePart_new(mailcore::MessagePart *part){
    CMessagePart self;
    self.abstractMessagePart = CAbstractMessagePart_new(part);
    self.instance = part;
    return self;
}
