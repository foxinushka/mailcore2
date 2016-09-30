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

struct CAbstractPart    partForContentID(struct CAbstractPart self, const UChar* contentID);
struct CAbstractPart    partForUniqueID(struct CAbstractPart self, const UChar* uniqueID);
void                    setContentTypeParameterValue(struct CAbstractPart self, const UChar* value, const UChar* name);
void                    removeContentTypeParameterForName(struct CAbstractPart self, const UChar* name);
const UChar*            contentTypeParameterValueForName(struct CAbstractPart self, const UChar* name);
CArray                  allContentTypeParametersNames(struct CAbstractPart self);

CAbstractPart newCAbstractPart(mailcore::AbstractPart *part){
    CAbstractPart self;
    self.nativeInstance = part;
    C_SAFE_RETAIN(self);
    
    self.partType = &partType;
    self.setPartType = &setPartType;
    self.filename = &filename;
    self.setFilename = &setFilename;
    self.mimeType = &mimeType;
    self.setMimeType = &setMimeType;
    self.charset = &charset;
    self.setCharset = &setCharset;
    self.uniqueID = &uniqueID;
    self.setUniqueID = &setUniqueID;
    self.contentID = &contentID;
    self.setContentID = &setContentID;
    self.contentLocation = &contentLocation;
    self.setContentLocation = &setContentLocation;
    self.contentDescriprion = &contentDescription;
    self.setContentDescription = &setContentDescription;
    self.isInlineAttachment = &isInlineAttachment;
    self.setInlineAttachment = &setInlineAttachment;
    self.isAttachment = &isAttachment;
    self.setAttachment = &setAttachment;
    self.partForContentID = &partForContentID;
    self.partForUniqueID = &partForUniqueID;
    self.setContentTypeParameterValue = &setContentTypeParameterValue;
    self.removeContentTypeParameterForName = &removeContentTypeParameterForName;
    self.contentTypeParameterValueForName = &contentTypeParameterValueForName;
    self.allContentTypeParametersNames = &allContentTypeParametersNames;
    return self;
}

mailcore::AbstractPart * cast(CAbstractPart part){
    return reinterpret_cast<mailcore::AbstractPart*>(part.nativeInstance);
}

void deleteCAbstractPart(CAbstractPart self){
    C_SAFE_RELEASE(self);
}

struct CAbstractPart partForContentID(struct CAbstractPart self, const UChar* contentID){
    return newCAbstractPart(cast(self)->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

struct CAbstractPart partForUniqueID(struct CAbstractPart self, const UChar* uniqueID){
    return newCAbstractPart(cast(self)->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

void setContentTypeParameterValue(struct CAbstractPart self, const UChar* value, const UChar* name){
    cast(self)->setContentTypeParameter(mailcore::String::stringWithCharacters(value), mailcore::String::stringWithCharacters(name));
}

void removeContentTypeParameterForName(struct CAbstractPart self, const UChar* name){
    cast(self)->removeContentTypeParameter(mailcore::String::stringWithCharacters(name));
}

const UChar* contentTypeParameterValueForName(struct CAbstractPart self, const UChar* name){
    return cast(self)->contentTypeParameterValueForName(mailcore::String::stringWithCharacters(name))->unicodeCharacters();
}

CArray allContentTypeParametersNames(struct CAbstractPart self){
    return newCArray(cast(self)->allContentTypeParametersNames());
}

CAbstractPart castFromCObject(CObject obj) {
    return newCAbstractPart((mailcore::AbstractPart*) obj.nativeInstance);
}

CObject castToCObject(struct CAbstractPart self) {
    return newCObject((mailcore::Object*) self.nativeInstance);
}


