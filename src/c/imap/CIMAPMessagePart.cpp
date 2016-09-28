#include "CIMAPMessagePart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeInstance abstractMessagePart.abstractPart.nativeInstance
#define nativeType mailcore::IMAPMessagePart
#define structName CIMAPMessagePart

C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMessagePart newCIMAPMessage(mailcore::IMAPMessagePart *part) {
    CIMAPMessagePart self;
    self.abstractMessagePart = newCAbstractMessagePart(part);
    
    self.partID = &partID;
    self.setPartID = &setPartID;
    
    return self;
}

mailcore::IMAPMessagePart* cast(CIMAPMessagePart *self) {
    return reinterpret_cast<mailcore::IMAPMessagePart*>(self->nativeInstance);
}
