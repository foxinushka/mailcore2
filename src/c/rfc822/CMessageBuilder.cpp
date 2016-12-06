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

void            addAttachment(struct CMessageBuilder self, CAttachment attachment);
void            addRelatedAttachment(struct CMessageBuilder self, CAttachment attachment);
CData           data(struct CMessageBuilder self);
CData           dataForEncryption(struct CMessageBuilder self);
ErrorCode       writeToFile(struct CMessageBuilder self, const UChar* filename);
CData           openPGPSignedMessageDataWithSignatureData(struct CMessageBuilder self, const char* bytes, unsigned int length);
CData           openPGPEncryptedMessageDataWithEncryptedData(struct CMessageBuilder self, const char* bytes, unsigned int length);
const UChar*    htmlBodyRendering(struct CMessageBuilder self);
const UChar*    plainTextRendering(struct CMessageBuilder self);
const UChar*    plainTextBodyRendering(struct CMessageBuilder self);
const UChar*    plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace);

CMessageBuilder newCMessageBuilder() {
    return newCMessageBuilder(new mailcore::MessageBuilder());
}

CMessageBuilder newCMessageBuilder(mailcore::MessageBuilder *builder) {
    CMessageBuilder self;
    self.abstractMessage = newCAbstractMessage(builder);
    self.instance = builder;
    
    self.htmlBody = &htmlBody;
    self.textBody = &textBody;
    self.attachments = &attachments;
    self.relatedAttachments = &relatedAttachments;
    self.boundaryPrefix = &boundaryPrefix;
    self.setHTMLBody = &setHTMLBody;
    self.setTextBody = &setTextBody;
    self.setAttachments = &setAttachments;
    self.setRelatedAttachments = &setRelatedAttachments;
    self.setBoundaryPrefix = &setBoundaryPrefix;
    self.addAttachment = &addAttachment;
    self.addRelatedAttachment = &addRelatedAttachment;
    self.data = &data;
    self.dataForEncryption = &dataForEncryption;
    self.writeToFile = &writeToFile;
    self.openPGPSignedMessageDataWithSignatureData = &openPGPSignedMessageDataWithSignatureData;
    self.openPGPEncryptedMessageDataWithEncryptedData = &openPGPEncryptedMessageDataWithEncryptedData;
    self.htmlBodyRendering = &htmlBodyRendering;
    self.plainTextRendering = &plainTextRendering;
    self.plainTextBodyRendering = &plainTextBodyRendering;
    self.plainTextBodyRenderingAndStripWhitespace = &plainTextBodyRenderingAndStripWhitespace;
    
    return self;
}

void addAttachment(struct CMessageBuilder self, CAttachment attachment) {
    self.instance->addAttachment(attachment.instance);
}

void addRelatedAttachment(struct CMessageBuilder self, CAttachment attachment) {
    self.instance->addRelatedAttachment(attachment.instance);
}

CData data(struct CMessageBuilder self) {
    return newCData(self.instance->data());
}

CData dataForEncryption(struct CMessageBuilder self) {
    return newCData(self.instance->dataForEncryption());
}

ErrorCode writeToFile(struct CMessageBuilder self, const UChar* filename) {
    return static_cast<ErrorCode>((int)self.instance->writeToFile(new mailcore::String(filename)));
}

CData openPGPSignedMessageDataWithSignatureData(struct CMessageBuilder self, const char* bytes, unsigned int length) {
    return newCData(self.instance->openPGPSignedMessageDataWithSignatureData(new mailcore::Data(bytes, length)));
}

CData openPGPEncryptedMessageDataWithEncryptedData(struct CMessageBuilder self, const char* bytes, unsigned int length) {
    return newCData(self.instance->openPGPEncryptedMessageDataWithEncryptedData(new mailcore::Data(bytes, length)));
}

const UChar* htmlBodyRendering(struct CMessageBuilder self) {
    return self.instance->htmlBodyRendering()->unicodeCharacters();
}

const UChar* plainTextRendering(struct CMessageBuilder self) {
    return self.instance->plainTextRendering()->unicodeCharacters();
}

const UChar* plainTextBodyRendering(struct CMessageBuilder self) {
    return self.instance->plainTextBodyRendering(true)->unicodeCharacters();
}

const UChar* plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace) {
    return self.instance->plainTextBodyRendering(stripWhitespace)->unicodeCharacters();
}





