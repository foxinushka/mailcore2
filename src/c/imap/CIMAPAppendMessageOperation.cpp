#include "CIMAPAppendMessageOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPAppendMessageOperation
#define structName CIMAPAppendMessageOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_SCALAR(time_t, time_t, setDate, date)
C_SYNTHESIZE_FUNC_WITH_SCALAR(uint32_t, createdUID)
