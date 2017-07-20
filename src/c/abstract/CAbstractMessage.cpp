#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessage
#define structName CAbstractMessage

CAbstractMessage CAbstractMessage_new(mailcore::AbstractMessage *msg){
    CAbstractMessage self;
    self.instance = msg;
    C_SAFE_RETAIN(self);
    return self;
}

void CAbstractMessage_release(CAbstractMessage self){
    C_SAFE_RELEASE(self.instance);
}

CMessageHeader CAbstractMessage_header(CAbstractMessage self){
    return CMessageHeader_new(self.instance->header());
}

void CAbstractMessage_setHeader(CAbstractMessage self, CMessageHeader header){
    self.instance->setHeader(header.instance);
}

CAbstractPart CAbstractMessage_partForContentID(CAbstractMessage self, const UChar* contentID){
    return CAbstractPart_new(self.instance->partForContentID(mailcore::String::stringWithCharacters(contentID)));
}

CAbstractPart CAbstractMessage_partForUniqueID(CAbstractMessage self, const UChar* uniqueID){
    return CAbstractPart_new(self.instance->partForUniqueID(mailcore::String::stringWithCharacters(uniqueID)));
}

CArray CAbstractMessage_attachments(CAbstractMessage self){
    return CArray_new(self.instance->attachments());
}

CArray CAbstractMessage_htmlInlineAttachments(CAbstractMessage self){
    return CArray_new(self.instance->htmlInlineAttachments());
}

CArray CAbstractMessage_requiredPartsForRendering(CAbstractMessage self){
    return CArray_new(self.instance->requiredPartsForRendering());
}




