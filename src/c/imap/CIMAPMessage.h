#ifndef CIMAPMessage_h
#define CIMAPMessage_h

#include "stdint.h"

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPMessage {
        CAbstractMessage abstractMessage;
        
        uint32_t        (*uid)(struct CIMAPMessage *self);
        void            (*setUid)(struct CIMAPMessage *self, uint32_t uid);
        uint32_t        (*sequenceNumber)(struct CIMAPMessage *self);
        void            (*setSequenceNumber)(struct CIMAPMessage *self, uint32_t sequenceNumber);
        uint32_t        (*size)(struct CIMAPMessage *self);
        void            (*setSize)(struct CIMAPMessage *self, uint32_t size);
        MessageFlag     (*flags)(struct CIMAPMessage *self);
        void            (*setFlags)(struct CIMAPMessage *self, MessageFlag flags);
        MessageFlag     (*originalFlags)(struct CIMAPMessage *self);
        void            (*setOriginalFlags)(struct CIMAPMessage *self, MessageFlag originalFlags);
        CArray          (*customFlags)(struct CIMAPMessage *self);
        void            (*setCustomFlags)(struct CIMAPMessage *self, CArray *customFlags);
        uint64_t        (*modSeqValue)(struct CIMAPMessage *self);
        void            (*setModSeqValue)(struct CIMAPMessage *self, uint64_t modSeqValue);
        CAbstractPart   (*mainPart)(struct CIMAPMessage *self);
        void            (*setMainPart)(struct CIMAPMessage *self, CAbstractPart mainPart);
        CArray          (*gmailLabels)(struct CIMAPMessage *self);
        void            (*setGmailLabels)(struct CIMAPMessage *self, CArray *gmailLabels);
        uint64_t        (*gmailMessageID)(struct CIMAPMessage *self);
        void            (*setGmailMessageID)(struct CIMAPMessage *self, uint64_t gmailMessageID);
        uint64_t        (*gmailThreadID)(struct CIMAPMessage *self);
        void            (*setGmailThreadID)(struct CIMAPMessage *self, uint64_t gmailThreadID);
        
        CAbstractPart   (*partForPartID)(struct CIMAPMessage *self, const UChar* partID);
        
    };
    typedef struct CIMAPMessage CIMAPMessage;
    
    void deleteCIMAPMessage(CIMAPMessage *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPMessage newCIMAPMessage(mailcore::IMAPMessage *msg);
mailcore::IMAPMessage * cast(CIMAPMessage *self);
#endif

#endif /* CIMAPMessage_h */
