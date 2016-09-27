#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessage
#define structName CAbstractMessage

CMessageHeader  header(struct CAbstractMessage* self);
void            setHeader(struct CAbstractMessage* self, CMessageHeader* header);
CAbstractPart   partForContentID(struct CAbstractMessage* self, const UChar* contentID);
CAbstractPart   partForUniqueID(struct CAbstractMessage* self, const UChar* uniqueID);
CArray          attachments(struct CAbstractMessage* self);
CArray          htmlInlineAttachments(struct CAbstractMessage* self);
CArray          requiredPartsForRendering(struct CAbstractMessage* self);

CAbstractMessage newCAbstractMessage(mailcore::AbstractMessage *address){
    CAbstractMessage self;
    self.nativeInstance = address;
    address->retain();
    
    self.header = &header;
    self.setHeader = &setHeader;
    self.partForContentID = &partForContentID;
    self.partForUniqueID = &partForUniqueID;
    self.attachments = &attachments;
    self.htmlInlineAttachments = &htmlInlineAttachments;
    self.requiredPartsForRendering = &requiredPartsForRendering;

    return self;
}

extern "C" void deleteCAbstractMessage(CAbstractMessage *self){
    C_NATIVE_INSTANCE->release();
}

CMessageHeader header(struct CAbstractMessage* self){
    return newCMessageHeader(C_NATIVE_INSTANCE->header());
}

void setHeader(struct CAbstractMessage* self, CMessageHeader* header){
    C_NATIVE_INSTANCE->setHeader(cast(header));
}

CAbstractPart partForContentID(struct CAbstractMessage* self, const UChar* contentID){
    return newCAbstractPart(C_NATIVE_INSTANCE->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

CAbstractPart partForUniqueID(struct CAbstractMessage* self, const UChar* uniqueID){
    return newCAbstractPart(C_NATIVE_INSTANCE->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

CArray attachments(struct CAbstractMessage* self){
    return newCArray2(C_NATIVE_INSTANCE->attachments());
}

CArray htmlInlineAttachments(struct CAbstractMessage* self){
    return newCArray2(C_NATIVE_INSTANCE->htmlInlineAttachments());
}

CArray requiredPartsForRendering(struct CAbstractMessage* self){
    return newCArray2(C_NATIVE_INSTANCE->requiredPartsForRendering());
}




