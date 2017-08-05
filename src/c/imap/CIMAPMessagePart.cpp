#include "CIMAPMessagePart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPMessagePart
#define structName CIMAPMessagePart

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STRING(setPartID, partID)
