#include "CIMAPMessagePart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeInstance abstractMessagePart.abstractPart.nativeInstance
#define nativeType mailcore::IMAPMessagePart
#define structName CIMAPMessagePart

C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMessagePart CIMAPMessage_new(mailcore::IMAPMessagePart *part) {
    CIMAPMessagePart self;
    self.abstractMessagePart = CAbstractMessagePart_new(part);
    self.instance = part;
    return self;
}
