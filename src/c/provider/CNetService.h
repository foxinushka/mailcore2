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
    
    typedef struct CNetService {
#ifdef __cplusplus
        mailcore::NetService*           instance;
#else
        void*                           instance;
#endif
    } CNetService;
    
    unsigned int        CNetService_port(struct CNetService self)
                        CF_SWIFT_NAME(getter:CNetService.port(self:));
    
    void                CNetService_setPort(struct CNetService self, unsigned int port)
                        CF_SWIFT_NAME(setter:CNetService.port(self:newValue:));
    
    MailCoreString        CNetService_hostname(struct CNetService self)
                        CF_SWIFT_NAME(getter:CNetService.hostname(self:));
    
    void                CNetService_setHostname(struct CNetService self, MailCoreString hostname)
                        CF_SWIFT_NAME(setter:CNetService.hostname(self:newValue:));
    
    MailCoreString        CNetService_normalizedHostnameWithEmail(struct CNetService self, MailCoreString email)
                        CF_SWIFT_NAME(CNetService.normalizedHostname(self:email:));
    
    ConnectionType      CNetService_connectionType(struct CNetService self)
                        CF_SWIFT_NAME(getter:CNetService.connectionType(self:));
    
    void                CNetService_setConnectionType(struct CNetService self, ConnectionType newValue)
                        CF_SWIFT_NAME(setter:CNetService.connectionType(self:newValue:));
    
    CNetService         CNetService_fromCObject(CObject objc)
                        CF_SWIFT_NAME(CNetService.init(cobject:));
    
    CObject             CNetService_toCObject(CNetService self)
                        CF_SWIFT_NAME(CNetService.toCObject(self:));
    
#ifdef __cplusplus
}
                                            
    CNetService CNetService_new(mailcore::NetService *netService);
#endif

#endif
