#include "CMessageBuilder.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

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

ErrorCode CMessageBuilder_writeToFile(struct CMessageBuilder self, const UChar* filename) {
    return static_cast<ErrorCode>((int)self.instance->writeToFile(new mailcore::String(filename)));
}

CData CMessageBuilder_openPGPSignedMessageDataWithSignatureData(struct CMessageBuilder self, const char* bytes, unsigned int length) {
    return CData_new(self.instance->openPGPSignedMessageDataWithSignatureData(new mailcore::Data(bytes, length)));
}

CData CMessageBuilder_openPGPEncryptedMessageDataWithEncryptedData(struct CMessageBuilder self, const char* bytes, unsigned int length) {
    return CData_new(self.instance->openPGPEncryptedMessageDataWithEncryptedData(new mailcore::Data(bytes, length)));
}

const UChar* CMessageBuilder_htmlBodyRendering(struct CMessageBuilder self) {
    return self.instance->htmlBodyRendering()->unicodeCharacters();
}

const UChar* CMessageBuilder_plainTextRendering(struct CMessageBuilder self) {
    return self.instance->plainTextRendering()->unicodeCharacters();
}

const UChar* CMessageBuilder_plainTextBodyRendering(struct CMessageBuilder self) {
    return self.instance->plainTextBodyRendering(true)->unicodeCharacters();
}

const UChar* CMessageBuilder_plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace) {
    return self.instance->plainTextBodyRendering(stripWhitespace)->unicodeCharacters();
}





