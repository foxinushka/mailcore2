#include "CIMAPMultipart.h"
#include <MailCore/MCCore.h>

#include "CBase+Private.h"

#define nativeType mailcore::IMAPMultipart
#define structName CIMAPMultipart

C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMultipart CIMAPMultipart_new(mailcore::IMAPMultipart *part) {
    CIMAPMultipart self;
    self.abstractMultipart = CAbstractMultipart_new(part);
    self.instance = part;
    return self;
}
