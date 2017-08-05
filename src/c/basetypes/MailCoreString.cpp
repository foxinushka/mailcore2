#include "MailCoreString.h"
#include <MailCore/MCCore.h>
#include "CData.h"

#include "CBase+Private.h"

#define nativeType mailcore::String
#define structName MailCoreString

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

MailCoreString MailCoreString_stringWithCharacters(const char* str, unsigned int length) {
    return MailCoreString_new(mailcore::String::stringWithCharacters((const UChar*)(str), length));
}

C_SYNTHESIZE_FUNC_WITH_SCALAR(const UChar*, unicodeCharacters)
C_SYNTHESIZE_FUNC_WITH_SCALAR(unsigned int, length)

MailCoreString CData_stringWithDetectedCharset(struct CData self, MailCoreString charset) {
    return MailCoreString_new(self.instance->stringWithDetectedCharset(charset.instance, false));
}


