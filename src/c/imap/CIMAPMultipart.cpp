#include "CIMAPMultipart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPMultipart
#define structName CIMAPMultipart

C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMultipart newCIMAPMultipart(mailcore::IMAPMultipart *part) {
    CIMAPMultipart self;
    self.abstractMultipart = newCAbstractMultipart(part);
    self.instance = part;
    
    self.partID = &partID;
    self.setPartID = &setPartID;
    
    return self;
}
