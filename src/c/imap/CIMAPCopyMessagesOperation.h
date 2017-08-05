#ifndef MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCopyMessagesOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPCopyMessagesOperation, mailcore::IMAPCopyMessagesOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPCopyMessagesOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPCopyMessagesOperation, CDictionary, uidMapping)

#ifdef __cplusplus
}
#endif

#endif
