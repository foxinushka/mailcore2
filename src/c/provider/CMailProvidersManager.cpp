#include <MailCore/MCCore.h>
#include "CMailProvidersManager.h"
#include "CBase+Private.h"

#define nativeType mailcore::MailProvidersManager
#define structName CMailProvidersManager

struct CMailProvidersManager CMailProvidersManager_shared() {
    CMailProvidersManager self;
    self.instance = mailcore::MailProvidersManager::sharedManager();
    return self;
}

C_SYNTHESIZE_FUNC_WITH_OBJ(CMailProvider, providerForEmail, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CMailProvider, providerForMX, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CMailProvider, providerForIdentifier, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_VOID(registerProvidersWithFilename, MailCoreString)
