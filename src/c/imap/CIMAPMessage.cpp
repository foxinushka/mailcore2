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
C_SYNTHESIZE_MAILCORE_OBJ(CAbstractPart, CAbstractPart_new, setMainPart, mainPart)
C_SYNTHESIZE_ARRAY(setGmailLabels, gmailLabels)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailMessageID, gmailMessageID)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailThreadID, gmailThreadID)

CIMAPMessage CIMAPMessage_new(mailcore::IMAPMessage *msg) {
    CIMAPMessage self;
    self.abstractMessage = CAbstractMessage_new(msg);
    self.instance = msg;
    return self;
}

void CIMAPMessage_release(CIMAPMessage self) {

}

CAbstractPart CIMAPMessage_partForPartID(struct CIMAPMessage self, const UChar* partID) {
    return CAbstractPart_new(self.instance->partForPartID(mailcore::String::stringWithCharacters(partID)));
}

const UChar* CIMAPMessage_htmlRendering(struct CIMAPMessage self, const UChar* folder, CAbstractMessageRendererCallback rendererCallback) {
    return self.instance->htmlRendering(new mailcore::String(folder), (mailcore::HTMLRendererIMAPCallback*) rendererCallback.callbackBridge)->unicodeCharacters();
}

CIMAPMessage CIMAPMessage_castFromCObject(CObject obj) {
    return CIMAPMessage_new((mailcore::IMAPMessage*) obj.instance);
}

CObject CIMAPMessage_castToCObject(struct CIMAPMessage self) {
    return CObject_new(self.instance);
}
