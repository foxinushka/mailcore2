#include <MailCore/MCCore.h>
#include "CAttachment.h"
#include "CBase+Private.h"

#define nativeType mailcore::Attachment
#define structName CAttachment

C_SYNTHESIZE_MAILCORE_OBJ(CData, CData_new, setData, data);

CAttachment CAttachment_new(mailcore::Attachment *attachment){
    CAttachment self;
    self.abstractPart = CAbstractPart_new(attachment);
    self.instance = attachment;
    self.instance->release();
    return self;
}

MailCoreString CAttachment_decodedString(struct CAttachment self) {
    return MailCoreString_new(self.instance->description());
}

MailCoreString CAttachment_mimeTypeForFilename(MailCoreString filename) {
    return MailCoreString_new(mailcore::Attachment::mimeTypeForFilename(filename.instance));
}

CAttachment CAttachment_WithContentsOfFile(MailCoreString filename) {
    return CAttachment_new(mailcore::Attachment::attachmentWithContentsOfFile(filename.instance));
}

CAttachment CAttachment_WithData(CData data, MailCoreString filename) {
    return CAttachment_new(mailcore::Attachment::attachmentWithData(filename.instance, data.instance));
}

CAttachment CAttachment_WithHTMLString(MailCoreString htmlString) {
    return CAttachment_new(mailcore::Attachment::attachmentWithHTMLString(htmlString.instance));
}

CAttachment CAttachment_WithRFC822Message(CData data) {
    return CAttachment_new(mailcore::Attachment::attachmentWithRFC822Message(data.instance));
}

CAttachment CAttachment_WithText(MailCoreString text) {
    return CAttachment_new(mailcore::Attachment::attachmentWithText(text.instance));
}


