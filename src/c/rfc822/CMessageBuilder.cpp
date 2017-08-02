#include "CMessageBuilder.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>
#include "CData.h"

#define nativeType mailcore::MessageBuilder
#define structName CMessageBuilder

C_SYNTHESIZE_STRING(setHTMLBody, htmlBody)
C_SYNTHESIZE_STRING(setTextBody, textBody)
C_SYNTHESIZE_ARRAY(setAttachments, attachments)
C_SYNTHESIZE_ARRAY(setRelatedAttachments, relatedAttachments)
C_SYNTHESIZE_STRING(setBoundaryPrefix, boundaryPrefix)

CMessageBuilder CMessageBuilder_new() {
    return CMessageBuilder_new(new mailcore::MessageBuilder());
}

CMessageBuilder CMessageBuilder_new(mailcore::MessageBuilder *builder) {
    CMessageBuilder self;
    self.abstractMessage = CAbstractMessage_new(builder);
    self.instance = builder;
    return self;
}

void CMessageBuilder_addAttachment(struct CMessageBuilder self, CAttachment attachment) {
    self.instance->addAttachment(attachment.instance);
}

void CMessageBuilder_addRelatedAttachment(struct CMessageBuilder self, CAttachment attachment) {
    self.instance->addRelatedAttachment(attachment.instance);
}

CData CMessageBuilder_data(struct CMessageBuilder self) {
    return CData_new(self.instance->data());
}

CData CMessageBuilder_dataForEncryption(struct CMessageBuilder self) {
    return CData_new(self.instance->dataForEncryption());
}

ErrorCode CMessageBuilder_writeToFile(struct CMessageBuilder self, MailCoreString filename) {
    return static_cast<ErrorCode>((int)self.instance->writeToFile(filename.instance));
}

CData CMessageBuilder_openPGPSignedMessageData(struct CMessageBuilder self, CData data) {
    return CData_new(self.instance->openPGPSignedMessageDataWithSignatureData(data.instance));
}

CData CMessageBuilder_openPGPEncryptedMessageData(struct CMessageBuilder self, CData data) {
    return CData_new(self.instance->openPGPEncryptedMessageDataWithEncryptedData(data.instance));
}

MailCoreString CMessageBuilder_htmlBodyRendering(struct CMessageBuilder self) {
    return MailCoreString_new(self.instance->htmlBodyRendering());
}

MailCoreString CMessageBuilder_plainTextRendering(struct CMessageBuilder self) {
    return MailCoreString_new(self.instance->plainTextRendering());
}

MailCoreString CMessageBuilder_plainTextBodyRendering(struct CMessageBuilder self) {
    return MailCoreString_new(self.instance->plainTextBodyRendering(true));
}

MailCoreString CMessageBuilder_plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace) {
    return MailCoreString_new(self.instance->plainTextBodyRendering(stripWhitespace));
}





