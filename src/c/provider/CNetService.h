#ifndef MAILCORE_CNET_SERVICE_H
#define MAILCORE_CNET_SERVICE_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CMessageConstants.h"

#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class NetService;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CNetService, mailcore::NetService)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CNetService)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CNetService, unsigned int, port, setPort)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CNetService, MailCoreString, hostname, setHostname)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CNetService, ConnectionType, connectionType, setConnectionType)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CNetService, MailCoreString, normalizedHostnameWithEmail, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif
