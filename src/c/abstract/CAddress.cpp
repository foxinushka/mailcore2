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

CAddress CAddress_new_WithDisplayName(MailCoreString displayName, MailCoreString mailbox){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithDisplayName(displayName.instance, mailbox.instance);
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithMailbox(MailCoreString mailbox){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithMailbox(mailbox.instance);
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithRFC822String(MailCoreString RFC822String){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithRFC822String(RFC822String.instance);
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CAddress CAddress_new_WithNonEncodedRFC822String(MailCoreString nonEncodedRFC822String){
    CAddress self = CAddress_new();
    C_SAFE_RELEASE(self.instance);
    self.instance = mailcore::Address::addressWithNonEncodedRFC822String(nonEncodedRFC822String.instance);
    if (self.instance == NULL) {
        return self;
    }
    self.instance->retain();
    return self;
}

CArray CAddresses_WithRFC822String(MailCoreString string){
    return CArray_new(mailcore::Address::addressesWithRFC822String(string.instance));
}

CArray CAddresses_WithNonEncodedRFC822String(MailCoreString string){
    return CArray_new(mailcore::Address::addressesWithNonEncodedRFC822String(string.instance));
}

MailCoreString CAddress_RFC822String(struct CAddress self){
    return MailCoreString_new(self.instance->RFC822String());
}

MailCoreString CAddress_nonEncodedRFC822String(struct CAddress self){
    return MailCoreString_new(self.instance->nonEncodedRFC822String());
}

CAddress CAddress_new_WithCObject(CObject obj) {
    return CAddress_new(reinterpret_cast<mailcore::Address*>(obj.instance));
}

CObject CAddress_castToCObject(struct CAddress self) {
    return CObject_new(reinterpret_cast<mailcore::Object*>(self.instance));
}



