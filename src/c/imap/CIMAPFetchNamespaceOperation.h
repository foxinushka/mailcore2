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
    };
    typedef struct CIMAPFetchNamespaceOperation CIMAPFetchNamespaceOperation;
    
    CDictionary     CIMAPFetchNamespaceOperation_namespaces(struct CIMAPFetchNamespaceOperation self)
                    CF_SWIFT_NAME(CIMAPFetchNamespaceOperation.namespaces(self:));
    
    void            CIMAPFetchNamespaceOperation_release(CIMAPFetchNamespaceOperation self)
                    CF_SWIFT_NAME(CIMAPFetchNamespaceOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPFetchNamespaceOperation CIMAPFetchNamespaceOperation_new(mailcore::IMAPFetchNamespaceOperation *operation);
#endif

#endif /* CIMAPFetchNamespaceOperation_hpp */
