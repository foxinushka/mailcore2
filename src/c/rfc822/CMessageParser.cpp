#include "CMessageParser.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::MessageParser
#define structName CMessageParser

CMessageParser CMessageParser_new(mailcore::MessageParser *parser) {
    CMessageParser self;
    self.abstractMessage = CAbstractMessage_new(parser);
    self.instance = parser;
    return self;
}

CMessageParser CMessageParser_new(const char* bytes, unsigned int length) {
    return CMessageParser_new(new mailcore::MessageParser(new mailcore::Data(bytes, length)));
}

CAbstractPart CMessageParser_mainPart(struct CMessageParser self) {
    return CAbstractPart_new(self.instance->mainPart());
}

CData CMessageParser_data(struct CMessageParser self) {
    return CData_new(self.instance->data());
}

const UChar* CMessageParser_htmlBodyRendering(struct CMessageParser self) {
    return self.instance->htmlBodyRendering()->unicodeCharacters();
}

const UChar* CMessageParser_plainTextRendering(struct CMessageParser self) {
    return self.instance->plainTextRendering()->unicodeCharacters();
}

const UChar* CMessageParser_plainTextBodyRendering(struct CMessageParser self) {
    return self.instance->plainTextBodyRendering(true)->unicodeCharacters();
}

const UChar* CMessageParser_plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace) {
    return self.instance->plainTextBodyRendering(stripWhitespace)->unicodeCharacters();
}
