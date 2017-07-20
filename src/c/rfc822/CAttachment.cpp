#include <MailCore/MCCore.h>
#include "CAttachment.h"
#include "CBase+Private.h"

#define nativeType mailcore::Attachment
#define structName CAttachment

CAttachment CAttachment_new(mailcore::Attachment *attachment){
    CAttachment self;
    self.abstractPart = CAbstractPart_new(attachment);
    self.instance = attachment;
    self.instance->release();
    return self;
}

const UChar* CAttachment_decodedString(struct CAttachment self) {
    return self.instance->description()->unicodeCharacters();
}

void CAttachment_setData(struct CAttachment self, const char* bytes, unsigned int length) {
    self.instance->setData(new mailcore::Data(bytes, length));
}

const UChar* CAttachment_mimeTypeForFilename(const UChar* filename) {
    return mailcore::Attachment::mimeTypeForFilename(new mailcore::String(filename))->unicodeCharacters();
}

CAttachment CAttachment_WithContentsOfFile(const UChar* filename) {
    return CAttachment_new(mailcore::Attachment::attachmentWithContentsOfFile(new mailcore::String(filename)));
}

CAttachment CAttachment_WithData(const char* bytes, unsigned int length, const UChar* filename) {
    return CAttachment_new(mailcore::Attachment::attachmentWithData(new mailcore::String(filename), new mailcore::Data(bytes, length)));
}

CAttachment CAttachment_WithHTMLString(const UChar* htmlString) {
    return CAttachment_new(mailcore::Attachment::attachmentWithHTMLString(new mailcore::String(htmlString)));
}

CAttachment CAttachment_WithRFC822Message(const char* bytes, unsigned int length) {
    return CAttachment_new(mailcore::Attachment::attachmentWithRFC822Message(new mailcore::Data(bytes, length)));
}

CAttachment CAttachment_WithText(const UChar* text) {
    return CAttachment_new(mailcore::Attachment::attachmentWithText(new mailcore::String(text)));
}


