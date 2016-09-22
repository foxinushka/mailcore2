#include <MailCore/MCCore.h>
#include "CAddress.h"
#include "CBase+Private.h"

#define nativeType mailcore::Address
#define structName CAddress

C_SYNTHESIZE_STRING(setDisplayName, displayName);
C_SYNTHESIZE_STRING(setMailbox, mailbox);

const UChar* RFC822String(struct CAddress* self);
const UChar* nonEncodedRFC822String(struct CAddress* self);

CAddress newCAddress(mailcore::Address *address){
    CAddress self;
    self.nativeInstance = address;
    address->retain();
    
    self.displayName = &displayName;
    self.setDisplayName = &setDisplayName;
    self.mailbox = &mailbox;
    self.setMailbox = &setMailbox;
    self.RFC822String = &RFC822String;
    self.nonEncodedRFC822String = &nonEncodedRFC822String;
    
    return self;
}

mailcore::Address * cast(CAddress *address){
    return reinterpret_cast<mailcore::Address*>(address->nativeInstance);
}

extern "C" CAddress newCAddress(){
    return newCAddress(new mailcore::Address());
}

extern "C" void deleteCAddress(CAddress *self){
    if (C_NATIVE_INSTANCE != NULL) {
        C_NATIVE_INSTANCE->release();
    }
}

extern "C" CAddress addressWithDisplayName(const UChar* displayName, const UChar* mailbox){
    CAddress address = newCAddress();
    deleteCAddress(&address);
    address.nativeInstance = mailcore::Address::addressWithDisplayName(mailcore::String::stringWithCharacters(displayName), mailcore::String::stringWithCharacters(mailbox));
    CAddress *self = &address;
    if (!C_NATIVE_INSTANCE) {
        //TODO: check this in Swift
        return address;
    }
    C_NATIVE_INSTANCE->retain();
    return address;
}

extern "C" CAddress addressWithMailbox(const UChar* mailbox){
    CAddress address = newCAddress();
    deleteCAddress(&address);
    address.nativeInstance = mailcore::Address::addressWithMailbox(mailcore::String::stringWithCharacters(mailbox));
    CAddress *self = &address;
    if (!C_NATIVE_INSTANCE) {
        //TODO: check this in Swift
        return address;
    }
    C_NATIVE_INSTANCE->retain();
    return address;
}

extern "C" CAddress addressWithRFC822String(const UChar* RFC822String){
    CAddress address = newCAddress();
    deleteCAddress(&address);
    address.nativeInstance = mailcore::Address::addressWithRFC822String(mailcore::String::stringWithCharacters(RFC822String));
    CAddress *self = &address;
    if (!C_NATIVE_INSTANCE) {
        //TODO: check this in Swift
        return address;
    }
    C_NATIVE_INSTANCE->retain();
    return address;
}

extern "C" CAddress addressWithNonEncodedRFC822String(const UChar* nonEncodedRFC822String){
    CAddress address = newCAddress();
    deleteCAddress(&address);
    address.nativeInstance = mailcore::Address::addressWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(nonEncodedRFC822String));
    CAddress *self = &address;
    if (!C_NATIVE_INSTANCE) {
        //TODO: check this in Swift
        return address;
    }
    C_NATIVE_INSTANCE->retain();
    return address;
}

extern "C" CArray addressesWithRFC822String(const UChar* string){
    return newCArray2(mailcore::Address::addressesWithRFC822String(mailcore::String::stringWithCharacters(string)));
}

extern "C" CArray addressesWithNonEncodedRFC822String(const UChar* string){
    return newCArray2(mailcore::Address::addressesWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(string)));
}

const UChar* RFC822String(struct CAddress* self){
    return C_NATIVE_INSTANCE->RFC822String()->unicodeCharacters();
}

const UChar* nonEncodedRFC822String(struct CAddress* self){
    return C_NATIVE_INSTANCE->nonEncodedRFC822String()->unicodeCharacters();
}



