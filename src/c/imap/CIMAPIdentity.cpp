#include "CIMAPIdentity.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPIdentity
#define structName CIMAPIdentity

C_SYNTHESIZE_STRING(setVendor, vendor);
C_SYNTHESIZE_STRING(setName, name);
C_SYNTHESIZE_STRING(setVersion, version);

CArray CIMAPIdentity_allInfoKeys(struct CIMAPIdentity self) {
    return CArray_new(self.instance->allInfoKeys());
}

const UChar* CIMAPIdentity_infoForKey(struct CIMAPIdentity self, const UChar* key) {
    return self.instance->infoForKey(new mailcore::String(key))->unicodeCharacters();
}

void CIMAPIdentity_setInfoForKey(struct CIMAPIdentity self, const UChar* value, const UChar* key) {
    self.instance->setInfoForKey(new mailcore::String(key), new mailcore::String(value));
}

void CIMAPIdentity_removeAllInfos(struct CIMAPIdentity self){
    self.instance->removeAllInfos();
}


CIMAPIdentity CIMAPIdentity_new(mailcore::IMAPIdentity *folder) {
    CIMAPIdentity self;
    folder->retain();
    self.instance = folder;
    return self;
}

CIMAPIdentity CIMAPIdentity_new(const UChar* vendor, const UChar* name, const UChar* version) {
    CIMAPIdentity self = CIMAPIdentity_new(new mailcore::IMAPIdentity());
    CIMAPIdentity_setVendor(self, vendor);
    CIMAPIdentity_setName(self, name);
    CIMAPIdentity_setVersion(self, version);
    return self;
}

void CIMAPIdentity_release(CIMAPIdentity self) {
    C_SAFE_RELEASE(self.instance);
}
