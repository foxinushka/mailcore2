#include <MailCore/MCCore.h>
#include "CNetService.h"
#include "CBase+Private.h"

#define nativeType mailcore::NetService
#define structName CNetService

C_SYNTHESIZE_STRING(setHostname, hostname);
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setPort, port);
C_SYNTHESIZE_ENUM(ConnectionType, mailcore::ConnectionType, setConnectionType, connectionType);

CNetService CNetService_new(mailcore::NetService *netService) {
    CNetService self;
    self.instance = netService;
    self.instance->release();
    return self;
}

MailCoreString CNetService_normalizedHostnameWithEmail(struct CNetService self, MailCoreString email) {
    return MailCoreString_new(self.instance->normalizedHostnameWithEmail(email.instance));
}

CNetService CNetService_fromCObject(CObject objc) {
    return CNetService_new(reinterpret_cast<mailcore::NetService*>(objc.instance));
}

CObject CNetService_toCObject(CNetService self) {
    return CObject_new(reinterpret_cast<mailcore::Object*>(self.instance));
}
