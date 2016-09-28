#include "CIMAPMultipart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeInstance abstractMultipart.abstractPart.nativeInstance
#define nativeType mailcore::IMAPMultipart
#define structName CIMAPMultipart

C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMultipart newCIMAPMultipart(mailcore::IMAPMultipart *part) {
    CIMAPMultipart self;
    self.abstractMultipart = newCAbstractMultipart(part);
    
    self.partID = &partID;
    self.setPartID = &setPartID;
    
    return self;
}

mailcore::IMAPMultipart* cast(CIMAPMultipart *self) {
    return reinterpret_cast<mailcore::IMAPMultipart*>(self->nativeInstance);
}
