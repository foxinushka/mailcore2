#ifndef MAILCORE_CABSTRACT_PART_H
#define MAILCORE_CABSTRACT_PART_H

#include "stdint.h"

#include <MailCore/CBase.h>
#include <MailCore/CArray.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef enum {
        // Used for a single part.
        // The part will be a MCOAbstractPart.
        PartTypeSingle,
        
        // Used for a message part (MIME type: message/rfc822).
        // The part will be a MCOAbstractMessagePart.
        // It's when a message is sent as attachment of an other message.
        PartTypeMessage,
        
        // Used for a multipart, multipart/mixed.
        // The part will be a MCOAbstractMultipart.
        PartTypeMultipartMixed,
        
        // Used for a multipart, multipart/related.
        // The part will be a MCOAbstractMultipart.
        PartTypeMultipartRelated,
        
        // Used for a multipart, multipart/alternative.
        // The part will be a MCOAbstractMultipart.
        PartTypeMultipartAlternative,
        
        // Used for a signed message, multipart/signed.
        // The part will be a MCOAbstractMultipart.
        PartTypeMultipartSigned,
    }PartType;

    struct CAbstractPart {
        ref nativeInstance;
        
        PartType        (*partType)(struct CAbstractPart *self);
        void            (*setPartType)(struct CAbstractPart *self, PartType type);
        const UChar*    (*filename)(struct CAbstractPart *self);
        void            (*setFilename)(struct CAbstractPart *self, const UChar* filename);
        const UChar*    (*mimeType)(struct CAbstractPart *self);
        void            (*setMimeType)(struct CAbstractPart *self, const UChar* mimeType);
        const UChar*    (*charset)(struct CAbstractPart *self);
        void            (*setCharset)(struct CAbstractPart *self, const UChar* charset);
        const UChar*    (*uniqueID)(struct CAbstractPart *self);
        void            (*setUniqueID)(struct CAbstractPart *self, const UChar* uniqueID);
        const UChar*    (*contentID)(struct CAbstractPart *self);
        void            (*setContentID)(struct CAbstractPart *self, const UChar* contentID);
        const UChar*    (*contentLocation)(struct CAbstractPart *self);
        void            (*setContentLocation)(struct CAbstractPart *self, const UChar* contentLocation);
        const UChar*    (*contentDescriprion)(struct CAbstractPart *self);
        void            (*setContentDescription)(struct CAbstractPart *self, const UChar* contentDescription);
        bool            (*isInlineAttachment)(struct CAbstractPart *self);
        void            (*setInlineAttachment)(struct CAbstractPart *self, bool isInlineAttachment);
        bool            (*isAttachment)(struct CAbstractPart *self);
        void            (*setAttachment)(struct CAbstractPart *self, bool isAttachment);
        
        struct CAbstractPart    (*partForContentID)(struct CAbstractPart *self, const UChar* contentID);
        struct CAbstractPart    (*partForUniqueID)(struct CAbstractPart *self, const UChar* uniqueID);
        
        void                    (*setContentTypeParameterValue)(struct CAbstractPart *self, const UChar* value, const UChar* name);
        void                    (*removeContentTypeParameterForName)(struct CAbstractPart *self, const UChar* name);
        const UChar*             (*contentTypeParameterValueForName)(struct CAbstractPart *self, const UChar* name);
        CArray                  (*allContentTypeParametersNames)(struct CAbstractPart *self);
        
    };
    typedef struct CAbstractPart CAbstractPart;
    
    void deleteCAbstractPart(CAbstractPart *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAbstractPart newCAbstractPart(mailcore::AbstractPart *part);
mailcore::AbstractPart * cast(CAbstractPart *part);
#endif

#endif
