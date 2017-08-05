#ifndef MAILCORE_СIMAP_SEARCH_OPERATION_H
#define MAILCORE_СIMAP_SEARCH_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPSearchOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPSearchOperation, mailcore::IMAPSearchOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPSearchOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPSearchOperation, CIndexSet, uids)
    
#ifdef __cplusplus
}
#endif

#endif
