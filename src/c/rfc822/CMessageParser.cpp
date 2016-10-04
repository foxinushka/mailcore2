#include "CMessageParser.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::MessageParser
#define structName CMessageParser

CAbstractPart   mainPart(struct CMessageParser self);
CData           data(struct CMessageParser self);
const UChar*    htmlBodyRendering(struct CMessageParser self);
const UChar*    plainTextRendering(struct CMessageParser self);
const UChar*    plainTextBodyRendering(struct CMessageParser self);
const UChar*    plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace);

CMessageParser newCMessageParser(mailcore::MessageParser *parser) {
    CMessageParser self;
    self.abstractMessage = newCAbstractMessage(parser);
    self.instance = parser;
    
    self.data = &data;
    self.mainPart = &mainPart;
    self.htmlBodyRendering = &htmlBodyRendering;
    self.plainTextRendering = &plainTextRendering;
    self.plainTextBodyRendering = &plainTextBodyRendering;
    self.plainTextBodyRenderingAndStripWhitespace = &plainTextBodyRenderingAndStripWhitespace;
    
    return self;
}

CMessageParser newCMessageParser(const char* bytes, unsigned int length) {
    return newCMessageParser(new mailcore::MessageParser(new mailcore::Data(bytes, length)));
}

CAbstractPart mainPart(struct CMessageParser self) {
    return newCAbstractPart(self.instance->mainPart());
}

CData data(struct CMessageParser self) {
    return newCData(self.instance->data());
}

const UChar* htmlBodyRendering(struct CMessageParser self) {
    return self.instance->htmlBodyRendering()->unicodeCharacters();
}

const UChar* plainTextRendering(struct CMessageParser self) {
    return self.instance->plainTextRendering()->unicodeCharacters();
}

const UChar* plainTextBodyRendering(struct CMessageParser self) {
    return self.instance->plainTextBodyRendering(true)->unicodeCharacters();
}

const UChar* plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace) {
    return self.instance->plainTextBodyRendering(stripWhitespace)->unicodeCharacters();
}
