#ifndef MAILCORE_CMESSAGE_HEADER_H
#define MAILCORE_CMESSAGE_HEADER_H

#include "stdint.h"
#include <time.h>

#include "CBase.h"
#include "CArray.h"
#include "CAddress.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class MessageHeader;
}

extern "C" {
#endif

    struct CMessageHeader {
#ifdef __cplusplus
        mailcore::MessageHeader*    instance;
#else
        void*                       instance;
#endif

    };
    typedef struct CMessageHeader CMessageHeader;
    
    MailCoreString            CMessageHeader_messageID(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.messageID(self:));
    
    void                    CMessageHeader_setMessageID(struct CMessageHeader self, MailCoreString messageID)
                            CF_SWIFT_NAME(setter:CMessageHeader.messageID(self:newValue:));
    
    CArray                  CMessageHeader_references(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.references(self:));
    
    void                    CMessageHeader_setReferences(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.references(self:newValue:));
    
    CArray                  CMessageHeader_inReplyTo(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.inReplyTo(self:));
    
    void                    CMessageHeader_setInReplyTo(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.inReplyTo(self:newValue:));
    
    CArray                  CMessageHeader_to(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.to(self:));
    
    void                    CMessageHeader_setTo(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.to(self:newValue:));
    
    CArray                  CMessageHeader_cc(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.cc(self:));
    
    void                    CMessageHeader_setCc(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.cc(self:newValue:));
    
    CArray                  CMessageHeader_bcc(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.bcc(self:));
    
    void                    CMessageHeader_setBcc(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.bcc(self:newValue:));
    
    CArray                  CMessageHeader_replyTo(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.replyTo(self:));
    
    void                    CMessageHeader_setReplyTo(struct CMessageHeader self, CArray cArray)
                            CF_SWIFT_NAME(setter:CMessageHeader.replyTo(self:newValue:));
    
    MailCoreString            CMessageHeader_subject(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.subject(self:));
    
    void                    CMessageHeader_setSubject(struct CMessageHeader self, MailCoreString subject)
                            CF_SWIFT_NAME(setter:CMessageHeader.subject(self:newValue:));
    
    MailCoreString            CMessageHeader_userAgent(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.userAgent(self:));
    
    void                    CMessageHeader_setUserAgent(struct CMessageHeader self, MailCoreString userAgent)
                            CF_SWIFT_NAME(setter:CMessageHeader.userAgent(self:newValue:));
    
    time_t                  CMessageHeader_receivedDate(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.receivedDate(self:));
    
    void                    CMessageHeader_setReceivedDate(struct CMessageHeader self, time_t receivedDate)
                            CF_SWIFT_NAME(setter:CMessageHeader.receivedDate(self:newValue:));
    
    time_t                  CMessageHeader_date(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.date(self:));
    
    void                    CMessageHeader_setDate(struct CMessageHeader self, time_t date)
                            CF_SWIFT_NAME(setter:CMessageHeader.date(self:newValue:));
    
    CAddress                CMessageHeader_sender(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.sender(self:));
    
    void                    CMessageHeader_setSender(struct CMessageHeader self,  CAddress sender)
                            CF_SWIFT_NAME(setter:CMessageHeader.sender(self:newValue:));
    
    CAddress                CMessageHeader_from(struct CMessageHeader self)
                            CF_SWIFT_NAME(getter:CMessageHeader.from(self:));
    
    void                    CMessageHeader_setFrom(struct CMessageHeader self, CAddress from)
                            CF_SWIFT_NAME(setter:CMessageHeader.from(self:newValue:));
    
    bool                    CMessageHeader_isMessageIDAutoGenerated(struct CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.isMessageIDAutoGenerated(self:));
    
    void                    CMessageHeader_setExtraHeaderValue(struct CMessageHeader self, MailCoreString value, MailCoreString name)
                            CF_SWIFT_NAME(CMessageHeader.setExtraHeaderValue(self:value:name:));
    
    void                    CMessageHeader_removeExtraHeaderForName(struct CMessageHeader self, MailCoreString name)
                            CF_SWIFT_NAME(CMessageHeader.removeExtraHeaderForName(self:name:));
    
    MailCoreString          CMessageHeader_extraHeaderValueForName(struct CMessageHeader self, MailCoreString name)
                            CF_SWIFT_NAME(CMessageHeader.extraHeaderValueForName(self:name:));
    
    CArray                  CMessageHeader_allExtraHeadersNames(struct CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.allExtraHeadersNames(self:));
    
    MailCoreString            CMessageHeader_extractedSubject(struct CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.extractedSubject(self:));
    
    MailCoreString            CMessageHeader_partialExtractedSubject(struct CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.partialExtractedSubject(self:));
    
    void                    CMessageHeader_importHeadersData(struct CMessageHeader self, const char *bytes, unsigned int length)
                            CF_SWIFT_NAME(CMessageHeader.importHeadersData(self:bytes:length:));
    
    struct CMessageHeader   CMessageHeader_replyHeaderWithExcludedRecipients(struct CMessageHeader self, CArray /* MCOAddress */excludedRecipients)
                            CF_SWIFT_NAME(CMessageHeader.replyHeaderWithExcludedRecipients(self:excludedRecipients:));
    
    struct CMessageHeader   CMessageHeader_replyAllHeaderWithExcludedRecipients(struct CMessageHeader self, CArray /* MCOAddress */excludedRecipients)
                            CF_SWIFT_NAME(CMessageHeader.replyAllHeaderWithExcludedRecipients(self:excludedRecipients:));
    
    struct CMessageHeader   CMessageHeader_forwardHeader(struct CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.forwardHeader(self:));
    
    CMessageHeader          CMessageHeader_new()
                            /*CF_SWIFT_NAME(CMessageHeader.init())*/;
    
    void                    CMessageHeader_release(CMessageHeader self)
                            CF_SWIFT_NAME(CMessageHeader.release(self:));
    
#ifdef __cplusplus
}

CMessageHeader CMessageHeader_new(mailcore::MessageHeader *header);
#endif

#endif
