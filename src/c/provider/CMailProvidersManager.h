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
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CMailProvidersManager, CMailProvidersManager, shared)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CMailProvidersManager, CMailProvider, providerForEmail, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CMailProvidersManager, CMailProvider, providerForMX, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CMailProvidersManager, CMailProvider, providerForIdentifier, MailCoreString)
    C_SYNTHESIZE_FUNC_DEFINITION(CMailProvidersManager, void, registerProvidersWithFilename, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif
