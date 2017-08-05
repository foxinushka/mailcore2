#include "CIMAPMessageRenderingOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPMessageRenderingOperation
#define structName CIMAPMessageRenderingOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, result)
