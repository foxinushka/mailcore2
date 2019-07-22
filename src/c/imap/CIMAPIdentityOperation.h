#ifndef CIMAPIdentityOperation_hpp
#define CIMAPIdentityOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CIMAPIdentity.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPIdentityOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPIdentityOperation, mailcore::IMAPIdentityOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPIdentityOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPIdentityOperation, CIMAPIdentity, serverIdentity)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPIdentityOperation_hpp */
