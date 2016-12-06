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
    
    struct CIMAPFetchNamespaceOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchNamespaceOperation*      instance;
#else
        void*                                       instance;
#endif
        
        CDictionary (*namespaces)(struct CIMAPFetchNamespaceOperation self);
        
    };
    typedef struct CIMAPFetchNamespaceOperation CIMAPFetchNamespaceOperation;
    
    void deleteCIMAPFetchNamespaceOperation(CIMAPFetchNamespaceOperation self);
    
#ifdef __cplusplus
}

CIMAPFetchNamespaceOperation newCIMAPFetchNamespaceOperation(mailcore::IMAPFetchNamespaceOperation *operation);
#endif

#endif /* CIMAPFetchNamespaceOperation_hpp */
