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

PartType    partType(struct CAbstractPart *self);
void        setPartType(struct CAbstractPart *self, PartType type);
bool        isInlineAttachment(struct CAbstractPart *self);
void        setInlineAttachment(struct CAbstractPart *self, bool isInlineAttachment);
bool        isAttachment(struct CAbstractPart *self);
void        setAttachment(struct CAbstractPart *self, bool isAttachment);

struct CAbstractPart    partForContentID(struct CAbstractPart *self, const UChar* contentID);
struct CAbstractPart    partForUniqueID(struct CAbstractPart *self, const UChar* uniqueID);
void                    setContentTypeParameterValue(struct CAbstractPart *self, const UChar* value, const UChar* name);
void                    removeContentTypeParameterForName(struct CAbstractPart *self, const UChar* name);
const UChar*            contentTypeParameterValueForName(struct CAbstractPart *self, const UChar* name);
CArray                  allContentTypeParametersNames(struct CAbstractPart *self);

CAbstractPart newCAbstractPart(mailcore::AbstractPart *part){
    CAbstractPart self;
    if (part != NULL) {
        part->retain();
    }
    self.nativeInstance = reinterpret_cast<void *>(part);
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

//TODO: delete
mailcore::AbstractPart * cast(CAbstractPart *part){
    return reinterpret_cast<mailcore::AbstractPart*>(part->nativeInstance);
}

mailcore::AbstractPart * cast(CAbstractPart part){
    return reinterpret_cast<mailcore::AbstractPart*>(part.nativeInstance);
}

extern "C" void deleteCAbstractPart(CAbstractPart *self){
    if (C_NATIVE_INSTANCE != NULL) {
        C_NATIVE_INSTANCE->release();
    }
}

PartType partType(struct CAbstractPart *self){
    return static_cast<PartType>((int)C_NATIVE_INSTANCE->partType());
}

void setPartType(struct CAbstractPart *self, PartType type){
    C_NATIVE_INSTANCE->setPartType(static_cast<mailcore::PartType>((int)type));
}

struct CAbstractPart partForContentID(struct CAbstractPart *self, const UChar* contentID){
    return newCAbstractPart(C_NATIVE_INSTANCE->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

struct CAbstractPart partForUniqueID(struct CAbstractPart *self, const UChar* uniqueID){
    return newCAbstractPart(C_NATIVE_INSTANCE->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

void setContentTypeParameterValue(struct CAbstractPart *self, const UChar* value, const UChar* name){
    C_NATIVE_INSTANCE->setContentTypeParameter(mailcore::String::stringWithCharacters(value), mailcore::String::stringWithCharacters(name));
}

void removeContentTypeParameterForName(struct CAbstractPart *self, const UChar* name){
    C_NATIVE_INSTANCE->removeContentTypeParameter(mailcore::String::stringWithCharacters(name));
}

const UChar* contentTypeParameterValueForName(struct CAbstractPart *self, const UChar* name){
    return C_NATIVE_INSTANCE->contentTypeParameterValueForName(mailcore::String::stringWithCharacters(name))->unicodeCharacters();
}

CArray allContentTypeParametersNames(struct CAbstractPart *self){
    return newCArray2(C_NATIVE_INSTANCE->allContentTypeParametersNames());
}


