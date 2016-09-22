#ifndef MAILCORE_CADDRESS_H
#define MAILCORE_CADDRESS_H

#include "stdint.h"

#include <MailCore/CBase.h>
#include <MailCore/CArray.h>

#ifdef __cplusplus
extern "C" {
#endif

    struct CAddress {
        ref nativeInstance;
        
        const UChar*    (*displayName)(struct CAddress* self);
        void            (*setDisplayName)(struct CAddress* self, const UChar* displayName);
        const UChar*    (*mailbox)(struct CAddress* self);
        void            (*setMailbox)(struct CAddress* self, const UChar* mailbox);
        const UChar*    (*RFC822String)(struct CAddress* self);
        const UChar*    (*nonEncodedRFC822String)(struct CAddress* self);
    };
    typedef struct CAddress CAddress;
    
    CAddress    addressWithDisplayName(const UChar* displayName, const UChar* mailbox);
    CAddress    addressWithMailbox(const UChar* mailbox);
    CAddress    addressWithRFC822String(const UChar* RFC822String);
    CAddress    addressWithNonEncodedRFC822String(const UChar* nonEncodedRFC822String);
    CArray      addressesWithRFC822String(const UChar* string);
    CArray      addressesWithNonEncodedRFC822String(const UChar* string);

    void deleteCAddress(CAddress *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAddress newCAddress(mailcore::Address *address);
mailcore::Address * cast(CAddress *address);
#endif

#endif
