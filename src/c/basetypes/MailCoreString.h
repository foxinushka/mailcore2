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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(MailCoreString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(MailCoreString, MailCoreString, stringWithCharacters, const char*, unsigned int)

    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(MailCoreString, const UChar*, unicodeCharacters)
    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(MailCoreString, unsigned int, length)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, MailCoreString, mUTF7DecodedString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, MailCoreString, mUTF7EncodedString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(MailCoreString, bool, isEqual, MailCoreString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CData, MailCoreString, stringWithDetectedCharset, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CData, MailCoreString, charsetWithFilteredHTML, bool)
    
#ifdef __cplusplus
}
#endif

#endif
