#include "CIMAPMultipart.h"
#include <MailCore/MCCore.h>

#include "CBase+Private.h"

#define nativeType mailcore::IMAPMultipart
#define structName CIMAPMultipart

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()
C_SYNTHESIZE_STRING(setPartID, partID);

CIMAPMultipart CIMAPMultipart_init() {
    return CIMAPMultipart_new(new mailcore::IMAPMultipart());
}

