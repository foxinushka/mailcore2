#include <MailCore/MCCore.h>
#include "CAddress.h"
#include "CBase+Private.h"

#define nativeType mailcore::Address
#define structName CAddress

C_SYNTHESIZE_STRING(setDisplayName, displayName);
C_SYNTHESIZE_STRING(setMailbox, mailbox);

CAddress CAddress_new(mailcore::Address *address){
    CAddress self;
    self.instance = address;
    self.instance->retain();
    return self;
}

CAddress CAddress_new(){
    return CAddress_new(new mailcore::Address());
}

void CAddress_release(CAddress self){
    C_SAFE_RELEASE(self.instance);
}

CAddress CAddress_new_WithDisplayName(const UChar* displayName, const UChar* mailbox){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithDisplayName(mailcore::String::stringWithCharacters(displayName), mailcore::String::stringWithCharacters(mailbox));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithMailbox(const UChar* mailbox){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithMailbox(mailcore::String::stringWithCharacters(mailbox));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithRFC822String(const UChar* RFC822String){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithRFC822String(mailcore::String::stringWithCharacters(RFC822String));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithNonEncodedRFC822String(const UChar* nonEncodedRFC822String){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(nonEncodedRFC822String));
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CArray CAddresses_WithRFC822String(const UChar* string){
    return CArray_new(mailcore::Address::addressesWithRFC822String(mailcore::String::stringWithCharacters(string)));
}

CArray CAddresses_WithNonEncodedRFC822String(const UChar* string){
    return CArray_new(mailcore::Address::addressesWithNonEncodedRFC822String(mailcore::String::stringWithCharacters(string)));
}

const UChar* CAddress_RFC822String(struct CAddress self){
    return self.instance->RFC822String()->unicodeCharacters();
}

const UChar* CAddress_nonEncodedRFC822String(struct CAddress self){
    return self.instance->nonEncodedRFC822String()->unicodeCharacters();
}

CAddress CAddress_new_WithCObject(CObject obj) {
    return CAddress_new((mailcore::Address*) obj.instance);
}

CObject CAddress_castToCObject(struct CAddress self) {
    return CObject_new((mailcore::Object*) self.instance);
}



