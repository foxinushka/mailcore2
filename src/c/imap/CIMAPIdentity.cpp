#include "CIMAPIdentity.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPIdentity
#define structName CIMAPIdentity

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STRING(setVendor, vendor);
C_SYNTHESIZE_STRING(setName, name);
C_SYNTHESIZE_STRING(setVersion, version);

C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, allInfoKeys)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, infoForKey, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_VOID(setInfoForKey, MailCoreString, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_VOID(removeAllInfos)

CIMAPIdentity   CIMAPIdentity_init() {
    return CIMAPIdentity_new(new mailcore::IMAPIdentity());
}
