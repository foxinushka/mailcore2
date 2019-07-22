#ifndef CIMAPQuotaOperation_hpp
#define CIMAPQuotaOperation_hpp

#include "CIMAPBaseOperation.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPQuotaOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPQuotaOperation, mailcore::IMAPQuotaOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPQuotaOperation)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPQuotaOperation, uint32_t, usage)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPQuotaOperation, uint32_t, limit)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPQuotaOperation_hpp */
