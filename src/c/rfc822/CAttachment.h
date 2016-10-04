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
        
        void                (*setData)(struct CAttachment self, const char* bytes, unsigned int length);
        const UChar*        (*decodedString)(struct CAttachment self);
        
    };
    typedef struct CAttachment CAttachment;
    
    const UChar* CmimeTypeForFilename(const UChar* filename);
    CAttachment CattachmentWithContentsOfFile(const UChar* filename);
    CAttachment CattachmentWithData(const char* bytes, unsigned int length, const UChar* filename);
    CAttachment CattachmentWithHTMLString(const UChar* htmlString);
    CAttachment CattachmentWithRFC822Message(const char* bytes, unsigned int length);
    CAttachment CattachmentWithText(const UChar* text);
    
#ifdef __cplusplus
}

CAttachment newCAttachment(mailcore::Attachment *attachment);
#endif

#endif /* CAttachment_h */
