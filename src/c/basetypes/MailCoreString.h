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
    
    struct MailCoreString {
#ifdef __cplusplus
        mailcore::String*   instance;
#else
        void*               instance;
#endif
    };
    typedef struct MailCoreString MailCoreString;

    
    void                MailCoreString_release(MailCoreString self)
                        CF_SWIFT_NAME(MailCoreString.release(self:));
    
    CObject             MailCoreString_toCObject(MailCoreString self)
                        CF_SWIFT_NAME(MailCoreString.toCObject(self:));
    
    MailCoreString      MailCoreString_newWithCObject(struct CObject cobject)
                        CF_SWIFT_NAME(MailCoreString.init(cobject:));
    
    MailCoreString      MailCoreString_new(const char* str, unsigned int length)
                        CF_SWIFT_NAME(MailCoreString.init(uchar:length:));
    
    const UChar*        MailCoreString_unicodeCharacters(struct MailCoreString self)
                        CF_SWIFT_NAME(getter:MailCoreString.unicodeCharacters(self:));
    
    unsigned int        MailCoreString_length(struct MailCoreString self)
                        CF_SWIFT_NAME(getter:MailCoreString.length(self:));
    
    MailCoreString      CData_stringWithDetectedCharset(struct CData data, const char* charset)
                        CF_SWIFT_NAME(CData.string(self:detectedCharset:));
    
#ifdef __cplusplus
}

MailCoreString MailCoreString_new(mailcore::String *obj);
#endif

#endif
