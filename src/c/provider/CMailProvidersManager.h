#ifndef MAILCORE_CMAIL_PROVIDERS_MANAGER_H
#define MAILCORE_CMAIL_PROVIDERS_MANAGER_H

#include "stdint.h"
#include "CBase.h"
#include "CMailProvider.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class MailProvidersManager;
}

extern "C" {
#endif
    
    typedef struct CMailProvidersManager {
#ifdef __cplusplus
        mailcore::MailProvidersManager*  instance;
#else
        void*                           instance;
#endif
    } CMailProvidersManager;
    
    struct CMailProvidersManager    CMailProvidersManager_shared();
    
    CMailProvider   CMailProvidersManager_providerForEmail(struct CMailProvidersManager self, MailCoreString email)
                    CF_SWIFT_NAME(CMailProvidersManager.provider(self:forEmail:));
    
    CMailProvider   CMailProvidersManager_providerForMX(struct CMailProvidersManager self, MailCoreString hostname)
                    CF_SWIFT_NAME(CMailProvidersManager.provider(self:forMX:));
    
    CMailProvider   CMailProvidersManager_providerForIdentifier(struct CMailProvidersManager self, MailCoreString identifier)
                    CF_SWIFT_NAME(CMailProvidersManager.provider(self:forIdentifier:));
    
#ifdef __cplusplus
}
#endif

#endif
