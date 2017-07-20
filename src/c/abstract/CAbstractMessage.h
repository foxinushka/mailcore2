#ifndef MAILCORE_CABSTRACT_MESSAGE_H
#define MAILCORE_CABSTRACT_MESSAGE_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessage;
}

extern "C" {
#endif
    
    struct CAbstractMessage {
#ifdef __cplusplus
        mailcore::AbstractMessage*  instance;
#else
        void*                       instance;
#endif
    };
    typedef struct CAbstractMessage CAbstractMessage;
    
    struct CMessageHeader   CAbstractMessage_header(struct CAbstractMessage self)
                            CF_SWIFT_NAME(getter:CAbstractMessage.header(self:));
    
    void                    CAbstractMessage_setHeader(struct CAbstractMessage self, struct CMessageHeader header)
                            CF_SWIFT_NAME(setter:CAbstractMessage.header(self:newValue:));
    
    struct CAbstractPart    CAbstractMessage_partForContentID(struct CAbstractMessage self, const UChar* contentID)
                            CF_SWIFT_NAME(CAbstractMessage.part(self:forContentID:));
    
    struct CAbstractPart    CAbstractMessage_partForUniqueID(struct CAbstractMessage self, const UChar* uniqueID)
                            CF_SWIFT_NAME(CAbstractMessage.part(self:forUniqueID:));
    
    CArray                  CAbstractMessage_attachments(struct CAbstractMessage self)
                            CF_SWIFT_NAME(CAbstractMessage.attachments(self:));
    
    CArray                  CAbstractMessage_htmlInlineAttachments(struct CAbstractMessage self)
                            CF_SWIFT_NAME(CAbstractMessage.htmlInlineAttachments(self:));
    
    CArray                  CAbstractMessage_requiredPartsForRendering(struct CAbstractMessage self)
                            CF_SWIFT_NAME(CAbstractMessage.requiredPartsForRendering(self:));
    
    void                    CAbstractMessage_release(CAbstractMessage self)
                            CF_SWIFT_NAME(CAbstractMessage.release(self:));
    
#ifdef __cplusplus
}

CAbstractMessage CAbstractMessage_new(mailcore::AbstractMessage *msg);
#endif

#endif
