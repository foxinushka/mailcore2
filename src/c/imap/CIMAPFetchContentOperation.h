#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchContentOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchContentOperation, mailcore::IMAPFetchContentOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchContentOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchContentOperation, CData, data)

#ifdef __cplusplus
}
#endif

#endif
