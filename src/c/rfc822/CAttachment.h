#ifndef CAttachment_h
#define CAttachment_h

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class Attachment;
}

extern "C" {
#endif
    
    
    struct CAttachment {
#ifdef __cplusplus
        mailcore::Attachment*           instance;
#else
        void*                           instance;
#endif
        CAbstractPart abstractPart;
        
    };
    typedef struct CAttachment CAttachment;
    
    CData               CAttachment_data(struct CAttachment self)
                        CF_SWIFT_NAME(getter:CAttachment.data(self:));
    
    void                CAttachment_setData(struct CAttachment self, CData data)
                        CF_SWIFT_NAME(setter:CAttachment.data(self:newValue:));
    
    MailCoreString      CAttachment_decodedString(struct CAttachment self)
                        CF_SWIFT_NAME(CAttachment.decodedString(self:));
    
    MailCoreString      CAttachment_mimeTypeForFilename(MailCoreString filename)
                        CF_SWIFT_NAME(CAttachment.mimeType(forFilename:));
    
    CAttachment         CAttachment_WithContentsOfFile(MailCoreString filename)
                        CF_SWIFT_NAME(CAttachment.init(contentsOfFile:));
    
    CAttachment         CAttachment_WithData(CData data, MailCoreString filename)
                        CF_SWIFT_NAME(CAttachment.init(data:filename:));
    
    CAttachment         CAttachment_WithHTMLString(MailCoreString htmlString)
                        CF_SWIFT_NAME(CAttachment.init(htmlString:));
    
    CAttachment         CAttachment_WithRFC822Message(CData data)
                        CF_SWIFT_NAME(CAttachment.init(RFC822MessageData:));
    
    CAttachment         CAttachment_WithText(MailCoreString text)
                        CF_SWIFT_NAME(CAttachment.init(text:));
    
#ifdef __cplusplus
}

CAttachment CAttachment_new(mailcore::Attachment *attachment);
#endif

#endif /* CAttachment_h */
