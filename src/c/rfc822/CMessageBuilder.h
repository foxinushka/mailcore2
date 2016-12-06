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
        
        const UChar*    (*htmlBody)(struct CMessageBuilder self);
        const UChar*    (*textBody)(struct CMessageBuilder self);
        CArray          (*attachments)(struct CMessageBuilder self);
        CArray          (*relatedAttachments)(struct CMessageBuilder self);
        const UChar*    (*boundaryPrefix)(struct CMessageBuilder self);
        
        void            (*setHTMLBody)(struct CMessageBuilder self, const UChar* htmlBody);
        void            (*setTextBody)(struct CMessageBuilder self, const UChar* textBody);
        void            (*setAttachments)(struct CMessageBuilder self, CArray attachments);
        void            (*setRelatedAttachments)(struct CMessageBuilder self, CArray relatedAttachments);
        void            (*setBoundaryPrefix)(struct CMessageBuilder self, const UChar* boundaryPrefix);
        
        void            (*addAttachment)(struct CMessageBuilder self, CAttachment attachment);
        void            (*addRelatedAttachment)(struct CMessageBuilder self, CAttachment attachment);
        CData           (*data)(struct CMessageBuilder self);
        CData           (*dataForEncryption)(struct CMessageBuilder self);
        ErrorCode       (*writeToFile)(struct CMessageBuilder self, const UChar* filename);
        CData           (*openPGPSignedMessageDataWithSignatureData)(struct CMessageBuilder self, const char* bytes, unsigned int length);
        CData           (*openPGPEncryptedMessageDataWithEncryptedData)(struct CMessageBuilder self, const char* bytes, unsigned int length);
        const UChar*    (*htmlBodyRendering)(struct CMessageBuilder self);
        const UChar*    (*plainTextRendering)(struct CMessageBuilder self);
        const UChar*    (*plainTextBodyRendering)(struct CMessageBuilder self);
        const UChar*    (*plainTextBodyRenderingAndStripWhitespace)(struct CMessageBuilder self, bool stripWhitespace);
    };
    typedef struct CMessageBuilder CMessageBuilder;
    
    CMessageBuilder newCMessageBuilder();
    
#ifdef __cplusplus
}

CMessageBuilder newCMessageBuilder(mailcore::MessageBuilder *builder);
#endif

#endif /* CMessageBuilder_h */
