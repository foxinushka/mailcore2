#ifndef CIMAPMessage_h
#define CIMAPMessage_h

#include "stdint.h"

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAbstractMessageRendererCallback.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessage;
}

extern "C" {
#endif
    
    struct CIMAPMessage {
#ifdef __cplusplus
        mailcore::IMAPMessage*  instance;
#else
        void*                   instance;
#endif
        CAbstractMessage abstractMessage;
    };
    typedef struct CIMAPMessage CIMAPMessage;
    
    uint32_t        CIMAPMessage_uid(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.uid(self:));

    void            CIMAPMessage_setUid(struct CIMAPMessage self, uint32_t uid)
                    CF_SWIFT_NAME(setter:CIMAPMessage.uid(self:newValue:));

    uint32_t        CIMAPMessage_sequenceNumber(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.sequenceNumber(self:));

    void            CIMAPMessage_setSequenceNumber(struct CIMAPMessage self, uint32_t sequenceNumber)
                    CF_SWIFT_NAME(setter:CIMAPMessage.sequenceNumber(self:newValue:));

    uint32_t        CIMAPMessage_size(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.size(self:));

    void            CIMAPMessage_setSize(struct CIMAPMessage self, uint32_t size)
                    CF_SWIFT_NAME(setter:CIMAPMessage.size(self:newValue:));

    CMessageFlag     CIMAPMessage_flags(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.flags(self:));

    void            CIMAPMessage_setFlags(struct CIMAPMessage self, CMessageFlag flags)
                    CF_SWIFT_NAME(setter:CIMAPMessage.flags(self:newValue:));

    CMessageFlag     CIMAPMessage_originalFlags(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.originalFlags(self:));

    void            CIMAPMessage_setOriginalFlags(struct CIMAPMessage self, CMessageFlag originalFlags)
                    CF_SWIFT_NAME(setter:CIMAPMessage.originalFlags(self:newValue:));

    CArray          CIMAPMessage_customFlags(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.customFlags(self:));

    void            CIMAPMessage_setCustomFlags(struct CIMAPMessage self, CArray customFlags)
                    CF_SWIFT_NAME(setter:CIMAPMessage.customFlags(self:newValue:));

    uint64_t        CIMAPMessage_modSeqValue(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.modSeqValue(self:));

    void            CIMAPMessage_setModSeqValue(struct CIMAPMessage self, uint64_t modSeqValue)
                    CF_SWIFT_NAME(setter:CIMAPMessage.modSeqValue(self:newValue:));

    CAbstractPart   CIMAPMessage_mainPart(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.mainPart(self:));

    void            CIMAPMessage_setMainPart(struct CIMAPMessage self, CAbstractPart mainPart)
                    CF_SWIFT_NAME(setter:CIMAPMessage.mainPart(self:newValue:));

    CArray          CIMAPMessage_gmailLabels(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.gmailLabels(self:));

    void            CIMAPMessage_setGmailLabels(struct CIMAPMessage self, CArray gmailLabels)
                    CF_SWIFT_NAME(setter:CIMAPMessage.gmailLabels(self:newValue:));

    uint64_t        CIMAPMessage_gmailMessageID(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.gmailMessageID(self:));

    void            CIMAPMessage_setGmailMessageID(struct CIMAPMessage self, uint64_t gmailMessageID)
                    CF_SWIFT_NAME(setter:CIMAPMessage.gmailMessageID(self:newValue:));

    uint64_t        CIMAPMessage_gmailThreadID(struct CIMAPMessage self)
                    CF_SWIFT_NAME(getter:CIMAPMessage.gmailThreadID(self:));

    void            CIMAPMessage_setGmailThreadID(struct CIMAPMessage self, uint64_t gmailThreadID)
                    CF_SWIFT_NAME(setter:CIMAPMessage.gmailThreadID(self:newValue:));

    CAbstractPart   CIMAPMessage_partForPartID(struct CIMAPMessage self, MailCoreString partID)
                    CF_SWIFT_NAME(CIMAPMessage.partForPartID(self:partID:));

    MailCoreString    CIMAPMessage_htmlRendering(struct CIMAPMessage self, MailCoreString folder, CAbstractMessageRendererCallback rendererCallback)
                    CF_SWIFT_NAME(CIMAPMessage.htmlRendering(self:folder:rendererCallback:));

    CObject         CIMAPMessage_castToCObject(struct CIMAPMessage self)
                    CF_SWIFT_NAME(CIMAPMessage.castToCObject(self:));
    
    CIMAPMessage    CIMAPMessage_castFromCObject(CObject obj)
                    CF_SWIFT_NAME(CIMAPMessage.init(cobject:));

    void            CIMAPMessage_release(CIMAPMessage self)
                    CF_SWIFT_NAME(CIMAPMessage.release(self:));
    
    CIMAPMessage    CIMAPMessage_new();
    
#ifdef __cplusplus
}

CIMAPMessage CIMAPMessage_new(mailcore::IMAPMessage *msg);
#endif

#endif /* CIMAPMessage_h */
