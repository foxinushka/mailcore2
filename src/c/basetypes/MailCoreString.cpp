#include "MailCoreString.h"
#include <MailCore/MCCore.h>
#include "CData.h"

MailCoreString MailCoreString_new(const char* str, unsigned int length) {
    return MailCoreString_new(mailcore::String::stringWithCharacters((const UChar*)(str), length));
}

MailCoreString MailCoreString_new(mailcore::String *obj){
    MailCoreString self;
    self.instance = obj;
    return self;
}

void MailCoreString_release(MailCoreString self) {
    self.instance->release();
}

CObject MailCoreString_toCObject(MailCoreString self) {
    return CObject_new(self.instance);
}

MailCoreString MailCoreString_newWithCObject(struct CObject self) {
    return MailCoreString_new(reinterpret_cast<mailcore::String*>(self.instance));
}

const UChar* MailCoreString_unicodeCharacters(struct MailCoreString self) {
    return self.instance->unicodeCharacters();
}

unsigned int MailCoreString_length(struct MailCoreString self) {
    return self.instance->length();
}

MailCoreString CData_stringWithDetectedCharset(struct CData self, const char* charset) {
    return MailCoreString_new(self.instance->stringWithCharset(charset));
}


