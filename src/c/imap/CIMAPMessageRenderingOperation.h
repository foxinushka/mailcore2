#ifndef CIMAPMessageRenderingOperation_hpp
#define CIMAPMessageRenderingOperation_hpp

#include "CIMAPBaseOperation.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPMessageRenderingOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPMessageRenderingOperation, mailcore::IMAPMessageRenderingOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPMessageRenderingOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPMessageRenderingOperation, MailCoreString, result)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPMessageRenderingOperation_hpp */
