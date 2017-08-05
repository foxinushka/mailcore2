#ifndef CIMAPCheckAccountOperation_hpp
#define CIMAPCheckAccountOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCheckAccountOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPCheckAccountOperation, mailcore::IMAPCheckAccountOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPCheckAccountOperation)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPCheckAccountOperation, MailCoreString, loginResponse)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPCheckAccountOperation, CData, loginUnparsedResponseData)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPCheckAccountOperation_hpp */
