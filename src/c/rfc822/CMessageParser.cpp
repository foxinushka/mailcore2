#include "CMessageParser.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>
#include <MailCore/MCDefines.h>
#include <MailCore/MCAttachment.h>
#include <MailCore/MCMessageHeader.h>
#include <MailCore/MCHTMLRenderer.h>
#include <MailCore/MCHTMLBodyRendererTemplateCallback.h>

#include "CData.h"
#include "CAbstractMessageRendererCallback.h"
#include "CAbstractMessageRendererCallbackWrapper.h"

#define nativeType mailcore::MessageParser
#define structName CMessageParser

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

CMessageParser CMessageParser_init(CData data) {
    return CMessageParser_new(new mailcore::MessageParser(data.instance));
}

C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, mainPart)
C_SYNTHESIZE_FUNC_WITH_OBJ(CData, data)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, htmlBodyRendering)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, plainTextRendering)
C_SYNTHESIZE_FUNC_WITH_OBJ(CDictionary, serializable)

MailCoreString CMessageParser_plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace) {
    return MailCoreString_new(self.instance->plainTextBodyRendering(stripWhitespace));
}

MailCoreString CMessageParser_htmlRendering(struct CMessageParser self, struct CAbstractMessageRendererCallback htmlCallback)
{
    return MailCoreString_new(self.instance->htmlRendering(static_cast<mailcore::HTMLRendererTemplateCallback*>(htmlCallback.callbackBridge)));
}
