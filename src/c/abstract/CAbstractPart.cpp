#include <MailCore/MCCore.h>
#include "CAbstractPart.h"
#include "CBase+Private.h"
#include "CData.h"

#define nativeType mailcore::AbstractPart
#define structName CAbstractPart

C_SYNTHESIZE_STRING(setFilename, filename);
C_SYNTHESIZE_STRING(setMimeType, mimeType);
C_SYNTHESIZE_STRING(setCharset, charset);
C_SYNTHESIZE_STRING(setUniqueID, uniqueID);
C_SYNTHESIZE_STRING(setContentID, contentID);
C_SYNTHESIZE_STRING(setContentLocation, contentLocation);
C_SYNTHESIZE_STRING(setContentDescription, contentDescription);
C_SYNTHESIZE_BOOL(setInlineAttachment, isInlineAttachment);
C_SYNTHESIZE_BOOL(setAttachment, isAttachment);
C_SYNTHESIZE_ENUM(PartType, mailcore::PartType, setPartType, partType)

CAbstractPart CAbstractPart_new(mailcore::AbstractPart *part){
    CAbstractPart self;
    self.instance = part;
    C_SAFE_RETAIN(self);
    return self;
}

void CAbstractPart_release(CAbstractPart self){
    C_SAFE_RELEASE(self.instance);
}

struct CAbstractPart CAbstractPart_partForContentID(struct CAbstractPart self, MailCoreString contentID){
    return CAbstractPart_new(self.instance->partForContentID(contentID.instance));
}

struct CAbstractPart CAbstractPart_partForUniqueID(struct CAbstractPart self, MailCoreString uniqueID){
    return CAbstractPart_new(self.instance->partForUniqueID(uniqueID.instance));
}

void CAbstractPart_setContentTypeParameterValue(struct CAbstractPart self, MailCoreString value, MailCoreString name){
    self.instance->setContentTypeParameter(value.instance, name.instance);
}

void CAbstractPart_removeContentTypeParameterForName(struct CAbstractPart self, MailCoreString name){
    self.instance->removeContentTypeParameter(name.instance);
}

MailCoreString CAbstractPart_contentTypeParameterValueForName(struct CAbstractPart self, MailCoreString name){
    return MailCoreString_new(self.instance->contentTypeParameterValueForName(name.instance));
}

CArray CAbstractPart_allContentTypeParametersNames(struct CAbstractPart self){
    return CArray_new(self.instance->allContentTypeParametersNames());
}

CAbstractPart CAbstractPart_castFromCObject(CObject obj) {
    return CAbstractPart_new(reinterpret_cast<mailcore::AbstractPart*>(obj.instance));
}

CObject CAbstractPart_castToCObject(struct CAbstractPart self) {
    return CObject_new(static_cast<mailcore::Object*>(self.instance));
}

MailCoreString CAbstractPart_decodedStringForData(struct CAbstractPart self, const uint8_t* bytes, uint32_t lenght) {
    return MailCoreString();
}

CData CAbstractPartHelper_getData(CAbstractPart part) {
    mailcore::AbstractPart *mcPart = reinterpret_cast<mailcore::AbstractPart*>(part.instance);
    if (mcPart->className()->isEqual(MCSTR("mailcore::Attachment"))) {
        mailcore::Attachment *att = reinterpret_cast<mailcore::Attachment*>(mcPart);
        return CData_new(att->data());
    }
    return CData_new(NULL, 0);
}


