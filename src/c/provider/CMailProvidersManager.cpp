#include <MailCore/MCCore.h>
#include "CMailProvidersManager.h"
#include "CBase+Private.h"

struct CMailProvidersManager CMailProvidersManager_shared() {
    CMailProvidersManager self;
    self.instance = mailcore::MailProvidersManager::sharedManager();
    return self;
}

CMailProvider CMailProvidersManager_providerForEmail(struct CMailProvidersManager self, MailCoreString email) {
    return CMailProvider_new(self.instance->providerForEmail(email.instance));
}

CMailProvider   CMailProvidersManager_providerForMX(struct CMailProvidersManager self, MailCoreString hostname) {
    return CMailProvider_new(self.instance->providerForMX(hostname.instance));
}

CMailProvider   CMailProvidersManager_providerForIdentifier(struct CMailProvidersManager self, MailCoreString identifier) {
    return CMailProvider_new(self.instance->providerForIdentifier(identifier.instance));
}
