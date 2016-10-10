#include "CIMAPMessage.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPMessage
#define structName CIMAPMessage

C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUid, uid)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setSequenceNumber, sequenceNumber)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setSize, size)
C_SYNTHESIZE_ENUM(MessageFlag, mailcore::MessageFlag, setFlags, flags)
C_SYNTHESIZE_ENUM(MessageFlag, mailcore::MessageFlag, setOriginalFlags, originalFlags)
C_SYNTHESIZE_ARRAY(setCustomFlags, customFlags)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setModSeqValue, modSeqValue)
C_SYNTHESIZE_MAILCORE_OBJ(CAbstractPart, newCAbstractPart, mailcore::AbstractPart, setMainPart, mainPart)
C_SYNTHESIZE_ARRAY(setGmailLabels, gmailLabels)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailMessageID, gmailMessageID)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailThreadID, gmailThreadID)

CAbstractPart partForPartID(struct CIMAPMessage self, const UChar* partID);
CObject       castToCObject(struct CIMAPMessage self);
const UChar*  htmlRendering(struct CIMAPMessage self, const UChar* folder, CAbstractMessageRendererCallback rendererCallback);

CIMAPMessage newCIMAPMessage(mailcore::IMAPMessage *msg) {
    CIMAPMessage self;
    self.abstractMessage = newCAbstractMessage(msg);
    self.instance = msg;
    
    self.uid = &uid;
    self.setUid = &setUid;
    self.sequenceNumber = &sequenceNumber;
    self.setSequenceNumber = &setSequenceNumber;
    self.size = &size;
    self.setSize = &setSize;
    self.flags = &flags;
    self.setFlags = &setFlags;
    self.originalFlags = &originalFlags;
    self.setOriginalFlags = &setOriginalFlags;
    self.customFlags = &customFlags;
    self.setCustomFlags = &setCustomFlags;
    self.modSeqValue = &modSeqValue;
    self.setModSeqValue = &setModSeqValue;
    self.mainPart = &mainPart;
    self.setMainPart = &setMainPart;
    self.gmailLabels = &gmailLabels;
    self.setGmailLabels = &setGmailLabels;
    self.gmailMessageID = &gmailMessageID;
    self.setGmailMessageID = &setGmailMessageID;
    self.gmailThreadID = &gmailThreadID;
    self.setGmailThreadID = &setGmailThreadID;
    self.partForPartID = &partForPartID;
    self.htmlRendering = &htmlRendering;

    self.castToCObject = &castToCObject;
    
    return self;
}

void deleteCIMAPMessage(CIMAPMessage self) {

}

CAbstractPart partForPartID(struct CIMAPMessage self, const UChar* partID) {
    return newCAbstractPart(self.instance->partForPartID(mailcore::String::stringWithCharacters(partID)));
}

const UChar* htmlRendering(struct CIMAPMessage self, const UChar* folder, CAbstractMessageRendererCallback rendererCallback) {
    return self.instance->htmlRendering(new mailcore::String(folder), (mailcore::HTMLRendererIMAPCallback*) rendererCallback.callbackBridge)->unicodeCharacters();
}

CIMAPMessage castCIMAPMessage(CObject obj) {
    return newCIMAPMessage((mailcore::IMAPMessage*) obj.instance);
}

CObject castToCObject(struct CIMAPMessage self) {
    return newCObject(self.instance);
}
