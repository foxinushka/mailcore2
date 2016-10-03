#ifndef MAILCORE_CABSTRACT_MESSAGE_H
#define MAILCORE_CABSTRACT_MESSAGE_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessage;
}

extern "C" {
#endif
    
    struct CMessageHeader;
    struct CAbstractPart;
    
    struct CAbstractMessage {
#ifdef __cplusplus
        mailcore::AbstractMessage*  instance;
#else
        void*                       instance;
#endif
        
        struct CMessageHeader   (*header)(struct CAbstractMessage self);
        void                    (*setHeader)(struct CAbstractMessage self, struct CMessageHeader header);
        struct CAbstractPart    (*partForContentID)(struct CAbstractMessage self, const UChar* contentID);
        struct CAbstractPart    (*partForUniqueID)(struct CAbstractMessage self, const UChar* uniqueID);
        CArray                  (*attachments)(struct CAbstractMessage self);
        CArray                  (*htmlInlineAttachments)(struct CAbstractMessage self);
        CArray                  (*requiredPartsForRendering)(struct CAbstractMessage self);
    };
    typedef struct CAbstractMessage CAbstractMessage;
    
    void deleteCAbstractMessage(CAbstractMessage self);
    
#ifdef __cplusplus
}

CAbstractMessage newCAbstractMessage(mailcore::AbstractMessage *msg);
#endif

#endif
