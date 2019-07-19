#ifndef CIMAPFetchParsedContentOperation_hpp
#define CIMAPFetchParsedContentOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CMessageParser.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchParsedContentOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchParsedContentOperation, mailcore::IMAPFetchParsedContentOperation)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchParsedContentOperation)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchParsedContentOperation, CMessageParser, parser)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFetchParsedContentOperation_hpp */
