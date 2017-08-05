#include "CIMAPFetchMessagesOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFetchMessagesOperation
#define structName CIMAPFetchMessagesOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_MAILCORE_OBJ(CArray, CArray_new, setExtraHeaders, extraHeaders)

C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, messages)
C_SYNTHESIZE_FUNC_WITH_OBJ(CIndexSet, vanishedMessages)
