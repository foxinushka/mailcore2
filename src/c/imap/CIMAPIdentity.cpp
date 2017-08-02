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

MailCoreString CIMAPIdentity_infoForKey(struct CIMAPIdentity self, MailCoreString key) {
    return MailCoreString_new(self.instance->infoForKey(key.instance));
}

void CIMAPIdentity_setInfoForKey(struct CIMAPIdentity self, MailCoreString value, MailCoreString key) {
    self.instance->setInfoForKey(key.instance, value.instance);
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

CIMAPIdentity CIMAPIdentity_new(MailCoreString vendor, MailCoreString name, MailCoreString version) {
    CIMAPIdentity self = CIMAPIdentity_new(new mailcore::IMAPIdentity());
    CIMAPIdentity_setVendor(self, vendor);
    CIMAPIdentity_setName(self, name);
    CIMAPIdentity_setVersion(self, version);
    return self;
}

void CIMAPIdentity_release(CIMAPIdentity self) {
    C_SAFE_RELEASE(self.instance);
}
