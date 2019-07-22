#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "stdint.h"
#include "time.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPAppendMessageOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPAppendMessageOperation, mailcore::IMAPAppendMessageOperation)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPAppendMessageOperation)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPAppendMessageOperation, time_t, date, setDate)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPAppendMessageOperation, uint32_t, createdUID)

#ifdef __cplusplus
}
#endif

#endif
