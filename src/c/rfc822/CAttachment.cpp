#include <MailCore/MCCore.h>
#include "CAttachment.h"
#include "CBase+Private.h"

#define nativeType mailcore::Attachment
#define structName CAttachment

const UChar* decodedString(struct CAttachment self);
void         setData(struct CAttachment self, const char* bytes, unsigned int length);

CAttachment newCAttachment(mailcore::Attachment *attachment){
    CAttachment self;
    self.abstractPart = newCAbstractPart(attachment);
    self.instance = attachment;
    self.instance->release();
    
    self.decodedString = &decodedString;
    
    return self;
}

const UChar* decodedString(struct CAttachment self) {
    return self.instance->description()->unicodeCharacters();
}

void setData(struct CAttachment self, const char* bytes, unsigned int length) {
    self.instance->setData(new mailcore::Data(bytes, length));
}

const UChar* CmimeTypeForFilename(const UChar* filename) {
    return mailcore::Attachment::mimeTypeForFilename(new mailcore::String(filename))->unicodeCharacters();
}

CAttachment CattachmentWithContentsOfFile(const UChar* filename) {
    return newCAttachment(mailcore::Attachment::attachmentWithContentsOfFile(new mailcore::String(filename)));
}

CAttachment CattachmentWithData(const char* bytes, unsigned int length, const UChar* filename) {
    return newCAttachment(mailcore::Attachment::attachmentWithData(new mailcore::String(filename), new mailcore::Data(bytes, length)));
}

CAttachment CattachmentWithHTMLString(const UChar* htmlString) {
    return newCAttachment(mailcore::Attachment::attachmentWithHTMLString(new mailcore::String(htmlString)));
}

CAttachment CattachmentWithRFC822Message(const char* bytes, unsigned int length) {
    return newCAttachment(mailcore::Attachment::attachmentWithRFC822Message(new mailcore::Data(bytes, length)));
}

CAttachment CattachmentWithText(const UChar* text) {
    return newCAttachment(mailcore::Attachment::attachmentWithText(new mailcore::String(text)));
}


