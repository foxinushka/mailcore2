#ifndef CMessageBuilder_h
#define CMessageBuilder_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAttachment.h"

#include "MailCoreString.h"

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
    
    MailCoreString    CMessageBuilder_htmlBody(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.htmlBody(self:));

    MailCoreString    CMessageBuilder_textBody(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.textBody(self:));

    CArray          CMessageBuilder_attachments(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.attachments(self:));

    CArray          CMessageBuilder_relatedAttachments(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.relatedAttachments(self:));

    MailCoreString    CMessageBuilder_boundaryPrefix(struct CMessageBuilder self)
                    CF_SWIFT_NAME(getter:CMessageBuilder.boundaryPrefix(self:));

    void            CMessageBuilder_setHTMLBody(struct CMessageBuilder self, MailCoreString htmlBody)
                    CF_SWIFT_NAME(setter:CMessageBuilder.htmlBody(self:newValue:));

    void            CMessageBuilder_setTextBody(struct CMessageBuilder self, MailCoreString textBody)
                    CF_SWIFT_NAME(setter:CMessageBuilder.textBody(self:newValue:));

    void            CMessageBuilder_setAttachments(struct CMessageBuilder self, CArray attachments)
                    CF_SWIFT_NAME(setter:CMessageBuilder.attachments(self:newValue:));

    void            CMessageBuilder_setRelatedAttachments(struct CMessageBuilder self, CArray relatedAttachments)
                    CF_SWIFT_NAME(setter:CMessageBuilder.relatedAttachments(self:newValue:));

    void            CMessageBuilder_setBoundaryPrefix(struct CMessageBuilder self, MailCoreString boundaryPrefix)
                    CF_SWIFT_NAME(setter:CMessageBuilder.boundaryPrefix(self:newValue:));

    void            CMessageBuilder_addAttachment(struct CMessageBuilder self, CAttachment attachment)
                    CF_SWIFT_NAME(CMessageBuilder.addAttachment(self:attachment:));

    void            CMessageBuilder_addRelatedAttachment(struct CMessageBuilder self, CAttachment attachment)
                    CF_SWIFT_NAME(CMessageBuilder.addRelatedAttachment(self:attachment:));

    CData           CMessageBuilder_data(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.data(self:));

    CData           CMessageBuilder_dataForEncryption(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.dataForEncryption(self:));

    ErrorCode       CMessageBuilder_writeToFile(struct CMessageBuilder self, MailCoreString filename)
                    CF_SWIFT_NAME(CMessageBuilder.writeToFile(self:filename:));

    CData           CMessageBuilder_openPGPSignedMessageData(struct CMessageBuilder self, CData data)
                    CF_SWIFT_NAME(CMessageBuilder.openPGPSignedMessageData(self:signatureData:));

    CData           CMessageBuilder_openPGPEncryptedMessageData(struct CMessageBuilder self, CData data)
                    CF_SWIFT_NAME(CMessageBuilder.openPGPEncryptedMessageData(self:encryptedData:));

    MailCoreString    CMessageBuilder_htmlBodyRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.htmlBodyRendering(self:));

    MailCoreString    CMessageBuilder_plainTextRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextRendering(self:));

    MailCoreString    CMessageBuilder_plainTextBodyRendering(struct CMessageBuilder self)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextBodyRendering(self:));

    MailCoreString    CMessageBuilder_plainTextBodyRenderingAndStripWhitespace(struct CMessageBuilder self, bool stripWhitespace)
                    CF_SWIFT_NAME(CMessageBuilder.plainTextBodyRenderingAndStripWhitespace(self:stripWhitespace:));

    
    CMessageBuilder CMessageBuilder_new()
                    /*CF_SWIFT_NAME(CMessageBuilder.init())*/;
    
#ifdef __cplusplus
}

CMessageBuilder CMessageBuilder_new(mailcore::MessageBuilder *builder);
#endif

#endif /* CMessageBuilder_h */
