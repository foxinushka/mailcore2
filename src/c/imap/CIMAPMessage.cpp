#include "CIMAPMessage.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>
#include "CAbstractMessageRendererCallbackWrapper.h"

#define nativeType mailcore::IMAPMessage
#define structName CIMAPMessage

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setUid, uid)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setSequenceNumber, sequenceNumber)
C_SYNTHESIZE_SCALAR(uint32_t, uint32_t, setSize, size)
C_SYNTHESIZE_ENUM(CMessageFlag, mailcore::MessageFlag, setFlags, flags)
C_SYNTHESIZE_ENUM(CMessageFlag, mailcore::MessageFlag, setOriginalFlags, originalFlags)
C_SYNTHESIZE_ARRAY(setCustomFlags, customFlags)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setModSeqValue, modSeqValue)
C_SYNTHESIZE_MAILCORE_OBJ(CAbstractPart, CAbstractPart_new, setMainPart, mainPart)
C_SYNTHESIZE_ARRAY(setGmailLabels, gmailLabels)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailMessageID, gmailMessageID)
C_SYNTHESIZE_SCALAR(uint64_t, uint64_t, setGmailThreadID, gmailThreadID)
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, partForPartID, MailCoreString)

MailCoreString CIMAPMessage_htmlRendering(struct CIMAPMessage self, MailCoreString folder, CAbstractMessageRendererCallback rendererCallback) {
    return MailCoreString_new(self.instance->htmlRendering(folder.instance, static_cast<mailcore::HTMLRendererIMAPCallback*>(rendererCallback.callbackBridge),  static_cast<mailcore::HTMLRendererTemplateCallback*>(rendererCallback.callbackBridge)));
}

CIMAPMessage CIMAPMessage_init() {
    return CIMAPMessage_new(new mailcore::IMAPMessage());
}
