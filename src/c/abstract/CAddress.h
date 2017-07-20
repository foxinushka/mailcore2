#ifndef MAILCORE_CADDRESS_H
#define MAILCORE_CADDRESS_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class Address;
}

extern "C" {
#endif

    typedef struct CAddress {
#ifdef __cplusplus
        mailcore::Address*  instance;
#else
        void*               instance;
#endif       
    } CAddress;
    
    const UChar*    CAddress_displayName(struct CAddress self)
                    CF_SWIFT_NAME(getter:CAddress.displayName(self:));
    
    void            CAddress_setDisplayName(struct CAddress self, const UChar* displayName)
                    CF_SWIFT_NAME(setter:CAddress.displayName(self:newValue:));
    
    const UChar*    CAddress_mailbox(struct CAddress self)
                    CF_SWIFT_NAME(getter:CAddress.mailbox(self:));
    
    void            CAddress_setMailbox(struct CAddress self, const UChar* mailbox)
                    CF_SWIFT_NAME(setter:CAddress.mailbox(self:newValue:));
    
    const UChar*    CAddress_RFC822String(struct CAddress self)
                    CF_SWIFT_NAME(getter:CAddress.RFC822String(self:));
    
    const UChar*    CAddress_nonEncodedRFC822String(struct CAddress self)
                    CF_SWIFT_NAME(getter:CAddress.nonEncodedRFC822String(self:));
    
    CObject         CAddress_castToCObject(struct CAddress self)
                    CF_SWIFT_NAME(CAddress.castToCObject(self:));
    
    CAddress        CAddress_new_WithDisplayName(const UChar* displayName, const UChar* mailbox)
                    CF_SWIFT_NAME(CAddress.init(displayName:mailbox:));
    
    CAddress        CAddress_new_WithMailbox(const UChar* mailbox)
                    CF_SWIFT_NAME(CAddress.init(mailbox:));
    
    CAddress        CAddress_new_WithRFC822String(const UChar* RFC822String)
                    CF_SWIFT_NAME(CAddress.init(RFC822String:));
    
    CAddress        CAddress_new_WithNonEncodedRFC822String(const UChar* nonEncodedRFC822String)
                    CF_SWIFT_NAME(CAddress.init(nonEncodedRFC822String:));
    
    CAddress        CAddress_new_WithCObject(CObject obj)
                    CF_SWIFT_NAME(CAddress.init(cObject:));
    
    void            CAddress_release(CAddress self)
                    CF_SWIFT_NAME(CAddress.release(self:));
    
    CArray          CAddresses_WithRFC822String(const UChar* string)
                    CF_SWIFT_NAME(CAddress.addresses(RFC822String:));
    
    CArray          CAddresses_WithNonEncodedRFC822String(const UChar* string)
                    CF_SWIFT_NAME(CAddress.addresses(nonEncodedRFC822String:));
    
    CAddress        CAddress_new()
                    CF_SWIFT_NAME(CAddress.init());
    
#ifdef __cplusplus
}

CAddress CAddress_new(mailcore::Address *address);
#endif

#endif
