#include <MailCore/MCCore.h>
#include "CAddress.h"
#include "CBase+Private.h"

#define nativeType mailcore::Address
#define structName CAddress

C_SYNTHESIZE_STRING(setDisplayName, displayName);
C_SYNTHESIZE_STRING(setMailbox, mailbox);

const UChar* RFC822String(struct CAddress self);
const UChar* nonEncodedRFC822String(struct CAddress self);
CObject castToCObject(struct CAddress self);

CAddress newCAddress(mailcore::Address *address){
    CAddress self;
    self.instance = address;
    self.instance->retain();
    
    self.displayName = &displayName;
    self.setDisplayName = &setDisplayName;
    self.mailbox = &mailbox;
    self.setMailbox = &setMailbox;
    self.RFC822String = &RFC822String;
    self.nonEncodedRFC822String = &nonEncodedRFC822String;

    self.castToCObject = &castToCObject;
    
    return self;
}

CAddress newCAddress(){
    return newCAddress(new mailcore::Address());
}

void deleteCAddress(CAddress self){
    C_SAFE_RELEASE(self);
}

CAddress CaddressWithDisplayName(const UChar* displayName, const UChar* mailbox){
    CAddress self = newCAddress();
    C_SAFE_RELEASE(self);
    self.instance = mailcore::Address::addressWithDisplayName(mailcore::String::stringWithCharacters(displayName), mailcore::String::stringWithCharacters(mailbox));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CaddressWithMailbox(const UChar* mailbox){
    CAddress self = newCAddress();
    C_SAFE_RELEASE(self);
    self.instance = mailcore::Address::addressWithMailbox(mailcore::String::stringWithCharacters(mailbox));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CaddressWithRFC822String(const UChar* RFC822String){
    CAddress self = newCAddress();
    C_SAFE_RELEASE(self);
    self.instance = mailcore::Address::addressWithRFC822String(mailcore::String::stringWithCharacters(RFC822String));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CaddressWithNonEncodedRFC822String(const UChar* nonEncodedRFC822String){
    CAddress self = newCAddress();
    C_SAFE_RELEASE(self);
    self.instance = mailcore::Address::addressWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(nonEncodedRFC822String));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CArray CaddressesWithRFC822String(const UChar* string){
    return newCArray(mailcore::Address::addressesWithRFC822String(mailcore::String::stringWithCharacters(string)));
}

CArray CaddressesWithNonEncodedRFC822String(const UChar* string){
    return newCArray(mailcore::Address::addressesWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(string)));
}

const UChar* RFC822String(struct CAddress self){
    return self.instance->RFC822String()->unicodeCharacters();
}

const UChar* nonEncodedRFC822String(struct CAddress self){
    return self.instance->nonEncodedRFC822String()->unicodeCharacters();
}

CAddress castCAddress(CObject obj) {
    return newCAddress((mailcore::Address*) obj.instance);
}

CObject castToCObject(struct CAddress self) {
    return newCObject((mailcore::Object*) self.instance);
}



