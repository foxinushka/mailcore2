#include "CMessageParser.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#include "MCDefines.h"
#include "MCAttachment.h"
#include "MCMessageHeader.h"
#include "MCHTMLRenderer.h"
#include "MCHTMLBodyRendererTemplateCallback.h"
#include "CData.h"

#include "CAbstractMessageRendererCallback.h"

#define nativeType mailcore::MessageParser
#define structName CMessageParser

CMessageParser CMessageParser_new(mailcore::MessageParser *parser) {
    CMessageParser self;
    self.abstractMessage = CAbstractMessage_new(parser);
    self.instance = parser;
    return self;
}

CMessageParser CMessageParser_new(CData data) {
    return CMessageParser_new(new mailcore::MessageParser(data.instance));
}

CAbstractPart CMessageParser_mainPart(struct CMessageParser self) {
    return CAbstractPart_new(self.instance->mainPart());
}

CData CMessageParser_data(struct CMessageParser self) {
    return CData_new(self.instance->data());
}

MailCoreString CMessageParser_htmlBodyRendering(struct CMessageParser self) {
    return MailCoreString_new(self.instance->htmlBodyRendering());
}

MailCoreString CMessageParser_plainTextRendering(struct CMessageParser self) {
    return MailCoreString_new(self.instance->plainTextRendering());
}

MailCoreString CMessageParser_plainTextBodyRendering(struct CMessageParser self) {
    return MailCoreString_new(self.instance->plainTextBodyRendering(true));
}

MailCoreString CMessageParser_plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace) {
    return MailCoreString_new(self.instance->plainTextBodyRendering(stripWhitespace));
}

MailCoreString CMessageParser_htmlRendering(struct CMessageParser self, struct CAbstractMessageRendererCallback htmlCallback)
{
    return MailCoreString_new(self.instance->htmlRendering(reinterpret_cast<mailcore::HTMLRendererTemplateCallback*>(htmlCallback.callbackBridge)));
}
