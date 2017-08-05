#include "CIMAPQuotaOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPQuotaOperation
#define structName CIMAPQuotaOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_FUNC_WITH_SCALAR(uint32_t, usage)
C_SYNTHESIZE_FUNC_WITH_SCALAR(uint32_t, limit)
