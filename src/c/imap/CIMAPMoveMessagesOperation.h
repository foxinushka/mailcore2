#ifndef CIMAPMoveMessagesOperation_hpp
#define CIMAPMoveMessagesOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMoveMessagesOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPMoveMessagesOperation, mailcore::IMAPMoveMessagesOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMoveMessagesOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMoveMessagesOperation, CDictionary, uidMapping)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMoveMessagesOperation_hpp */
