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
    
    void                CAttachment_setData(struct CAttachment self, const char* bytes, unsigned int length)
                        CF_SWIFT_NAME(CAttachment.setData(self:bytes:length:));
    
    const UChar*        CAttachment_decodedString(struct CAttachment self)
                        CF_SWIFT_NAME(CAttachment.decodedString(self:));
    
    const UChar*        CAttachment_mimeTypeForFilename(const UChar* filename)
                        CF_SWIFT_NAME(CAttachment.mimeType(forFilename:));
    
    CAttachment         CAttachment_WithContentsOfFile(const UChar* filename)
                        CF_SWIFT_NAME(CAttachment.init(contentsOfFile:));
    
    CAttachment         CAttachment_WithData(const char* bytes, unsigned int length, const UChar* filename)
                        CF_SWIFT_NAME(CAttachment.init(dataBytes:length:filename:));
    
    CAttachment         CAttachment_WithHTMLString(const UChar* htmlString)
                        CF_SWIFT_NAME(CAttachment.init(htmlString:));
    
    CAttachment         CAttachment_WithRFC822Message(const char* bytes, unsigned int length)
                        CF_SWIFT_NAME(CAttachment.init(RFC822MessageBytes:length:));
    
    CAttachment         CAttachment_WithText(const UChar* text)
                        CF_SWIFT_NAME(CAttachment.init(text:));
    
#ifdef __cplusplus
}

CAttachment CAttachment_new(mailcore::Attachment *attachment);
#endif

#endif /* CAttachment_h */
