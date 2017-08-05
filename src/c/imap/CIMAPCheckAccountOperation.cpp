#include "CIMAPCheckAccountOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>
#include "CData.h"

#define nativeType mailcore::IMAPCheckAccountOperation
#define structName CIMAPCheckAccountOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, loginResponse)
C_SYNTHESIZE_FUNC_WITH_OBJ(CData, loginUnparsedResponseData)
