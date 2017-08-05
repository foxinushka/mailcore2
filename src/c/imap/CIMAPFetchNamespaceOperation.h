#ifndef CIMAPFetchNamespaceOperation_hpp
#define CIMAPFetchNamespaceOperation_hpp

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchNamespaceOperation;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFetchNamespaceOperation, mailcore::IMAPFetchNamespaceOperation)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFetchNamespaceOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPFetchNamespaceOperation, CDictionary, namespaces)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFetchNamespaceOperation_hpp */
