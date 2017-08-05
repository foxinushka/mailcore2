#include <MailCore/MCCore.h>
#include "CNetService.h"
#include "CBase+Private.h"

#define nativeType mailcore::NetService
#define structName CNetService

C_SYNTHESIZE_STRING(setHostname, hostname);
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setPort, port);
C_SYNTHESIZE_ENUM(ConnectionType, mailcore::ConnectionType, setConnectionType, connectionType);
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, normalizedHostnameWithEmail, MailCoreString)

