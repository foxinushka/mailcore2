#include "MailCoreString.h"
#include <MailCore/MCCore.h>
#include <MailCore/MCLibetpan.h>

#include "CData.h"

#include "CBase+Private.h"
#include "time.h"

#define nativeType mailcore::String
#define structName MailCoreString

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

MailCoreString MailCoreString_stringWithCharacters(const char* str, unsigned int length) {
    return MailCoreString_new(mailcore::String::stringWithCharacters((const UChar*)(str), length));
}

C_SYNTHESIZE_FUNC_WITH_SCALAR(const UChar*, unicodeCharacters)
C_SYNTHESIZE_FUNC_WITH_SCALAR(unsigned int, length)

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, mUTF7DecodedString)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, mUTF7EncodedString)
C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, bool, isEqual, MailCoreString)

bool MailCoreString_isEqual(struct MailCoreString self, MailCoreString other) {
    return self.instance->isEqual(other.instance);
}

MailCoreString CData_stringWithDetectedCharset(struct CData self, MailCoreString charset) {
    return MailCoreString_new(self.instance->stringWithDetectedCharset(charset.instance, false));
}

MailCoreString CData_charsetWithFilteredHTML(struct CData self, bool filterHTML) {
    return MailCoreString_new(self.instance->charsetWithFilteredHTML(filterHTML));
}

extern "C" {

    time_t MailCoreTimestampFromDate(struct mailimf_date_time * date_time) {
        return mailcore::timestampFromDate(date_time);
    }
    
    time_t MailCoreTimestampFromIMAPDate(struct mailimap_date_time * imap_date) {
        return mailcore::timestampFromIMAPDate(imap_date);
    }
    
}


