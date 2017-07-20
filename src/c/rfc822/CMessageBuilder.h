#ifndef CMessageBuilder_h
#define CMessageBuilder_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAttachment.h"

#ifdef __cplusplus

namespace mailcore {
    class MessageBuilder;
}

extern "C" {
#endif
    
    struct CMessageBuilder {
#ifdef __cplusplus
        mailcore::MessageBuilder*   instance;
#else
        void*                       instance;
#endif
        CAbstractMessage abstractMessage;
    };
    typedef struct CMessageBuilder CMessageBuilder;
    
    const UChar*    CMessageBuilder_htmlBody(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.htmlBody(self:));

    const UChar*    CMessageBuilder_textBody(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.textBody(self:));

    CArray          CMessageBuilder_attachments(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.attachments(self:));

    CArray          CMessageBuilder_relatedAttachments(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.relatedAttachments(self:));

    const UChar*    CMessageBuilder_boundaryPrefix(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.boundaryPrefix(self:));

    void            CMessageBuilder_setHTMLBody(struct CMessageBuilder self, const UChar* htmlBody)
                    CF_SWIFT_NAME(setter:CMessageBuilder.htmlBody(self:newValue:));

    void            CMessageBuilder_setTextBody(struct CMessageBuilder self, const UChar* textBody)
                    CF_SWIFT_NAME(setter:CMessageBuilder.textBody(self:newValue:));

    void            CMessageBuilder_setAttachments(struct CMessageBuilder self, CArray attachments)
                    CF_SWIFT_NAME(setter:CMessageBuilder.attachments(self:newValue:));

    void            CMessageBuilder_setRelatedAttachments(struct CMessageBuilder self, CArray relatedAttachments)
                    CF_SWIFT_NAME(setter:CMessageBuilder.relatedAttachments(self:newValue:));

    void            CMessageBuilder_setBoundaryPrefix(struct CMessageBuilder self, const UChar* boundaryPrefix)
                    CF_SWIFT_NAME(setter:CMessageBuilder.boundaryPrefix(self:newValue:));

    void            CMessageBuilder_addAttachment(struct CMessageBuilder self, CAttachment attachment)
                    CF_SWIFT_NAME(CMessageBuilder.addAttachment(self:attachment:));

    void            CMessageBuilder_addRelatedAttachment(struct CMessageBuilder self, CAttachment attachment)
                    CF_SWIFT_NAME(CMessageBuilder.addRelatedAttachment(self:attachment:));

    CData           CMessageBuilder_data(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.data(self:));

    CData           CMessageBuilder_dataForEncryption(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.dataForEncryption(self:));

    ErrorCode       CMessageBuilder_writeToFile(struct CMessageBuilder self, const UChar* filename)
                    CF_SWIFT_NAME(CMessageBuilder.writeToFile(self:filename:));

    CData           CMessageBuilder_openPGPSignedMessageDataWithSignatureData(struct CMessageBuilder self, const char* bytes, unsigned int length)
                    CF_SWIFT_NAME(CMessageBuilder.openPGPSignedMessageDataWithSignatureData(self:bytes:length:));

    CData           CMessageBuilder_openPGPEncryptedMessageDataWithEncryptedData(struct CMessageBuilder self, const char* bytes, unsigned int length)
                    CF_SWIFT_NAME(CMessageBuilder.openPGPEncryptedMessageDataWithEncryptedData(self:bytes:length:));

    const UChar*    CMessageBuilder_htmlBodyRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.htmlBodyRendering(self:));

    const UChar*    CMessageBuilder_plainTextRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextRendering(self:));

    const UChar*    CMessageBuilder_plainTextBodyRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextBodyRendering(self:));

    const UChar*    CMessageBuilder_plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextBodyRenderingAndStripWhitespace(self:stripWhitespace:));

    
    CMessageBuilder CMessageBuilder_new()
                    CF_SWIFT_NAME(CMessageBuilder.init());
    
#ifdef __cplusplus
}

CMessageBuilder CMessageBuilder_new(mailcore::MessageBuilder *builder);
#endif

#endif /* CMessageBuilder_h */
