#include "CIMAPIdentity.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPIdentity
#define structName CIMAPIdentity

C_SYNTHESIZE_STRING(setVendor, vendor);
C_SYNTHESIZE_STRING(setName, name);
C_SYNTHESIZE_STRING(setVersion, version);

CArray allInfoKeys(struct CIMAPIdentity self) {
    return newCArray(self.instance->allInfoKeys());
}

const UChar* infoForKey(struct CIMAPIdentity self, const UChar* key) {
    return self.instance->infoForKey(new mailcore::String(key))->unicodeCharacters();
}

void setInfoForKey(struct CIMAPIdentity self, const UChar* value, const UChar* key) {
    self.instance->setInfoForKey(new mailcore::String(key), new mailcore::String(value));
}

void removeAllInfos(struct CIMAPIdentity self){
    self.instance->removeAllInfos();
}


CIMAPIdentity newCIMAPIdentity(mailcore::IMAPIdentity *folder) {
    CIMAPIdentity self;
    folder->retain();
    self.instance = folder;
    
    self.setVendor = &setVendor;
    self.vendor = &vendor;
    self.setName = &setName;
    self.name = &name;
    self.setVersion = &setVersion;
    self.version = &version;
    
    self.allInfoKeys = &allInfoKeys;
    self.infoForKey = &infoForKey;
    self.setInfoForKey = &setInfoForKey;
    self.removeAllInfos= &removeAllInfos;
    
    return self;
}

CIMAPIdentity newCIMAPIdentity(const UChar* vendor, const UChar* name, const UChar* version) {
    CIMAPIdentity self = newCIMAPIdentity(new mailcore::IMAPIdentity());
    self.setVendor(self, vendor);
    self.setName(self, name);
    self.setVersion(self, version);
    return self;
}

void deleteCIMAPIdentity(CIMAPIdentity self) {
    C_SAFE_RELEASE(self.instance);
}
