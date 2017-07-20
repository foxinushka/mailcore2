#include <MailCore/MCCore.h>
#include "CAbstractPart.h"
#include "CBase+Private.h"

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

struct CAbstractPart CAbstractPart_partForContentID(struct CAbstractPart self, const UChar* contentID){
    return CAbstractPart_new(self.instance->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

struct CAbstractPart CAbstractPart_partForUniqueID(struct CAbstractPart self, const UChar* uniqueID){
    return CAbstractPart_new(self.instance->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

void CAbstractPart_setContentTypeParameterValue(struct CAbstractPart self, const UChar* value, const UChar* name){
    self.instance->setContentTypeParameter(mailcore::String::stringWithCharacters(value), mailcore::String::stringWithCharacters(name));
}

void CAbstractPart_removeContentTypeParameterForName(struct CAbstractPart self, const UChar* name){
    self.instance->removeContentTypeParameter(mailcore::String::stringWithCharacters(name));
}

const UChar* CAbstractPart_contentTypeParameterValueForName(struct CAbstractPart self, const UChar* name){
    return self.instance->contentTypeParameterValueForName(mailcore::String::stringWithCharacters(name))->unicodeCharacters();
}

CArray CAbstractPart_allContentTypeParametersNames(struct CAbstractPart self){
    return CArray_new(self.instance->allContentTypeParametersNames());
}

CAbstractPart CAbstractPart_castFromCObject(CObject obj) {
    return CAbstractPart_new((mailcore::AbstractPart*) obj.instance);
}

CObject CAbstractPart_castToCObject(struct CAbstractPart self) {
    return CObject_new((mailcore::Object*) self.instance);
}

const UChar* CAbstractPart_decodedStringForData(struct CAbstractPart self, const uint8_t* bytes, uint32_t lenght) {
    return NULL;
}


