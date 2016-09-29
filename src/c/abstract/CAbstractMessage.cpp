#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessage
#define structName CAbstractMessage

CMessageHeader  header(struct CAbstractMessage self);
void            setHeader(struct CAbstractMessage self, CMessageHeader header);
CAbstractPart   partForContentID(struct CAbstractMessage self, const UChar* contentID);
CAbstractPart   partForUniqueID(struct CAbstractMessage self, const UChar* uniqueID);
CArray          attachments(struct CAbstractMessage self);
CArray          htmlInlineAttachments(struct CAbstractMessage self);
CArray          requiredPartsForRendering(struct CAbstractMessage self);

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

mailcore::AbstractMessage* cast(CAbstractMessage self) {
    return reinterpret_cast<mailcore::AbstractMessage*>(self.nativeInstance);
}

void deleteCAbstractMessage(CAbstractMessage self){
    cast(self)->release();
}

CMessageHeader header(CAbstractMessage self){
    return newCMessageHeader(cast(self)->header());
}

void setHeader(CAbstractMessage self, CMessageHeader header){
    cast(self)->setHeader(cast(header));
}

CAbstractPart partForContentID(CAbstractMessage self, const UChar* contentID){
    return newCAbstractPart(cast(self)->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

CAbstractPart partForUniqueID(CAbstractMessage self, const UChar* uniqueID){
    return newCAbstractPart(cast(self)->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

CArray attachments(CAbstractMessage self){
    return newCArray(cast(self)->attachments());
}

CArray htmlInlineAttachments(CAbstractMessage self){
    return newCArray(cast(self)->htmlInlineAttachments());
}

CArray requiredPartsForRendering(CAbstractMessage self){
    return newCArray(cast(self)->requiredPartsForRendering());
}




