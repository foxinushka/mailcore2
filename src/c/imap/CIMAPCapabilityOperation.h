#ifndef CIMAPCapabilityOperation_hpp
#define CIMAPCapabilityOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCapabilityOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPCapabilityOperation, mailcore::IMAPCapabilityOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPCapabilityOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPCapabilityOperation, CIndexSet, capabilities)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPCapabilityOperation_hpp */
