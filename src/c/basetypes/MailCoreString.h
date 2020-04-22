#ifndef MAILCORE_CSTRING_H
#define MAILCORE_CSTRING_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CData.h"

#ifdef __cplusplus

namespace  mailcore {
    class String;
}

extern "C" {
#endif
    
	C_SYNTHESIZE_STRUCT_DEFINITION(MailCoreString, mailcore::String)

	C_SYNTHESIZE_COBJECT_CAST_DEFINITION(MailCoreString)

	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(MailCoreString, MailCoreString, stringWithCharacters, const char*, unsigned int)

	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(MailCoreString, const UChar*, unicodeCharacters)
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(MailCoreString, unsigned int, length)

	C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, MailCoreString, mUTF7DecodedString)
	C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, MailCoreString, mUTF7EncodedString)

	C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, bool, isEqual, MailCoreString)

	C_SYNTHESIZE_FUNC_DEFINITION(CData, MailCoreString, stringWithDetectedCharset, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CData, MailCoreString, charsetWithFilteredHTML, bool)

#ifdef __cplusplus
}
#endif

#endif
