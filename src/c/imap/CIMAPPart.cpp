#include "CIMAPPart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPPart
#define structName CIMAPPart

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STRING(setPartID, partID)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setSize, size)
C_SYNTHESIZE_ENUM(Encoding, mailcore::Encoding, setEncoding, encoding)

C_SYNTHESIZE_FUNC_WITH_SCALAR(unsigned int, decodedSize)

CIMAPPart CIMAPPart_init() {
    return CIMAPPart_new(new mailcore::IMAPPart());
}
