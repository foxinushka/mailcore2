#include "CIMAPIdleOperation.h"
#include <MailCore/MCAsync.h>
#include "CBase+Private.h"

#define nativeType mailcore::IMAPIdleOperation
#define structName CIMAPIdleOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()
C_SYNTHESIZE_FUNC_WITH_VOID(interruptIdle)
