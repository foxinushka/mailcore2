#include "CIMAPPart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPPart
#define structName CIMAPPart

C_SYNTHESIZE_STRING(setPartID, partID)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setSize, size)
C_SYNTHESIZE_ENUM(Encoding, mailcore::Encoding, setEncoding, encoding)

CIMAPPart CIMAPPart_new(mailcore::IMAPPart *part) {
    CIMAPPart self;
    self.abstractPart = CAbstractPart_new(part);
    return self;
}

unsigned int CIMAPPart_decodedSize(struct CIMAPPart self) {
    return self.instance->decodedSize();
}


CIMAPPart CIMAPPart_castCIMAPPart(CObject obj) {
    return CIMAPPart_new((mailcore::IMAPPart*) obj.instance);
}
