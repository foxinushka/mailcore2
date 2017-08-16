#include <MailCore/MCCore.h>
#include "CMailProvider.h"
#include "CBase+Private.h"

#define nativeType mailcore::MailProvider
#define structName CMailProvider

C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, imapServices)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, smtpServices)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, identifier)
