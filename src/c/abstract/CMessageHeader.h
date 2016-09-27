#ifndef MAILCORE_CMESSAGE_HEADER_H
#define MAILCORE_CMESSAGE_HEADER_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CMessageHeader {
        ref nativeInstance;
        
        const UChar*    (*messageID)(struct CMessageHeader *self);
        void            (*setMessageID)(struct CMessageHeader *self, const UChar* messageID);
        CArray          (*references)(struct CMessageHeader *self);
        void            (*setReferences)(struct CMessageHeader *self, CArray *cArray);
        CArray          (*inReplyTo)(struct CMessageHeader *self);
        void            (*setInReplyTo)(struct CMessageHeader *self, CArray *cArray);
        CArray          (*to)(struct CMessageHeader *self);
        void            (*setTo)(struct CMessageHeader *self, CArray *cArray);
        CArray          (*cc)(struct CMessageHeader *self);
        void            (*setCc)(struct CMessageHeader *self, CArray *cArray);
        CArray          (*bcc)(struct CMessageHeader *self);
        void            (*setBcc)(struct CMessageHeader *self, CArray *cArray);
        CArray          (*replyTo)(struct CMessageHeader *self);
        void            (*setReplyTo)(struct CMessageHeader *self, CArray *cArray);
        const UChar*    (*subject)(struct CMessageHeader *self);
        void            (*setSubject)(struct CMessageHeader *self, const UChar* subject);
        const UChar*    (*userAgent)(struct CMessageHeader *self);
        void            (*setUserAgent)(struct CMessageHeader *self, const UChar* userAgent);
        
        bool                    (*isMessageIDAutoGenerated)(struct CMessageHeader *self);
        void                    (*setExtraHeaderValue)(struct CMessageHeader *self, const UChar* value, const UChar* name);
        void                    (*removeExtraHeaderForName)(struct CMessageHeader *self, const UChar* name);
        const UChar*            (*extraHeaderValueForName)(struct CMessageHeader *self, const UChar* name);
        CArray                  (*allExtraHeadersNames)(struct CMessageHeader *self);
        const UChar*            (*extractedSubject)(struct CMessageHeader *self);
        const UChar*            (*partialExtractedSubject)(struct CMessageHeader *self);
        void                    (*importHeadersData)(struct CMessageHeader *self, const char *bytes, unsigned int length);
        struct CMessageHeader   (*replyHeaderWithExcludedRecipients)(struct CMessageHeader *self, CArray * /* MCOAddress */excludedRecipients);
        struct CMessageHeader   (*replyAllHeaderWithExcludedRecipients)(struct CMessageHeader *self, CArray * /* MCOAddress */excludedRecipients);
        struct CMessageHeader   (*forwardHeader)(struct CMessageHeader *self);
    };
    typedef struct CMessageHeader CMessageHeader;
    CMessageHeader newCMessageHeader();
    void deleteCMessageHeader(CMessageHeader *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CMessageHeader newCMessageHeader(mailcore::MessageHeader *header);
mailcore::MessageHeader* cast(CMessageHeader *self);
#endif

#endif
