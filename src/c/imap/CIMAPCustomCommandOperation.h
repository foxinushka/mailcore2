#ifndef CIMAPCustomCommandOperation_hpp
#define CIMAPCustomCommandOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CBase.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCustomCommandOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPCustomCommandOperation, mailcore::IMAPCustomCommandOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPCustomCommandOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPCustomCommandOperation, MailCoreString, response)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPCustomCommandOperation_hpp */
