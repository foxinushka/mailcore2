#include "CIMAPPart.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPPart
#define structName CIMAPPart

C_SYNTHESIZE_STRING(setPartID, partID)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setSize, size)
C_SYNTHESIZE_ENUM(Encoding, mailcore::Encoding, setEncoding, encoding)

unsigned int decodedSize(struct CIMAPPart self);

CIMAPPart newCIMAPPart(mailcore::IMAPPart *part) {
    CIMAPPart self;
    self.abstractPart = newCAbstractPart(part);
    
    self.partID = &partID;
    self.setPartID = &setPartID;
    self.size = &size;
    self.setSize = &setSize;
    self.encoding = &encoding;
    self.setEncoding = &setEncoding;
    self.decodedSize = &decodedSize;
    
    return self;
}

mailcore::IMAPPart* cast(CIMAPPart self) {
    return reinterpret_cast<mailcore::IMAPPart*>(self.abstractPart.nativeInstance);
}

unsigned int decodedSize(struct CIMAPPart self) {
    return cast(self)->decodedSize();
}

CIMAPPart castCIMAPPart(CObject obj) {
    return newCIMAPPart((mailcore::IMAPPart*) obj.nativeInstance);
}

