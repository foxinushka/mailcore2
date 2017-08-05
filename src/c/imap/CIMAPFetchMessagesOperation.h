#ifndef MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CArray.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchMessagesOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchMessagesOperation, mailcore::IMAPFetchMessagesOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchMessagesOperation)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFetchMessagesOperation, CArray, extraHeaders, setExtraHeaders)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchMessagesOperation, CArray, messages)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchMessagesOperation, CIndexSet, vanishedMessages)

#ifdef __cplusplus
}
#endif

#endif
