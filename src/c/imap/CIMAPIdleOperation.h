#ifndef CIMAPIdleOperation_h
#define CIMAPIdleOperation_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CIMAPBaseOperation.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPIdleOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPIdleOperation, mailcore::IMAPIdleOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPIdleOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdleOperation, void, interruptIdle)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPIdleOperation_h */
