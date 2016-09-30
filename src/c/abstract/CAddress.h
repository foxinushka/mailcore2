#ifndef MAILCORE_CADDRESS_H
#define MAILCORE_CADDRESS_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CAddress {
        ref nativeInstance;
        
        bool            (*isNull)(struct CAddress self);
        
        const UChar*    (*displayName)(struct CAddress self);
        void            (*setDisplayName)(struct CAddress self, const UChar* displayName);
        const UChar*    (*mailbox)(struct CAddress self);
        void            (*setMailbox)(struct CAddress self, const UChar* mailbox);
        const UChar*    (*RFC822String)(struct CAddress self);
        const UChar*    (*nonEncodedRFC822String)(struct CAddress self);
        CObject         (*castToCObject)(struct CAddress self);
    };
    typedef struct CAddress CAddress;
    
    CAddress    CaddressWithDisplayName(const UChar* displayName, const UChar* mailbox);
    CAddress    CaddressWithMailbox(const UChar* mailbox);
    CAddress    CaddressWithRFC822String(const UChar* RFC822String);
    CAddress    CaddressWithNonEncodedRFC822String(const UChar* nonEncodedRFC822String);
    CArray      CaddressesWithRFC822String(const UChar* string);
    CArray      CaddressesWithNonEncodedRFC822String(const UChar* string);

    CAddress newCAddress();
    CAddress castCAddress(CObject obj);
    void deleteCAddress(CAddress self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAddress newCAddress(mailcore::Address *address);
mailcore::Address* cast(CAddress address);
#endif

#endif
