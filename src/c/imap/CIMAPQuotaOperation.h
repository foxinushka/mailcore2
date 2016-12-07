#ifndef CIMAPQuotaOperation_hpp
#define CIMAPQuotaOperation_hpp

#include "CIMAPBaseOperation.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPQuotaOperation;
}

extern "C" {
#endif
    
    struct CIMAPQuotaOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPQuotaOperation*      instance;
#else
        void*                                           instance;
#endif
        
        uint32_t    (*usage)(struct CIMAPQuotaOperation self);
        uint32_t    (*limit)(struct CIMAPQuotaOperation self);
        
    };
    typedef struct CIMAPQuotaOperation CIMAPQuotaOperation;
    
    void deleteCIMAPQuotaOperation(CIMAPQuotaOperation self);
    
#ifdef __cplusplus
}

CIMAPQuotaOperation newCIMAPQuotaOperation(mailcore::IMAPQuotaOperation *operation);
#endif

#endif /* CIMAPQuotaOperation_hpp */
