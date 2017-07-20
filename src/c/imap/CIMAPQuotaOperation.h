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
    };
    typedef struct CIMAPQuotaOperation CIMAPQuotaOperation;
    
    uint32_t    CIMAPQuotaOperation_usage(struct CIMAPQuotaOperation self)
                CF_SWIFT_NAME(CIMAPQuotaOperation.usage(self:));
    
    uint32_t    CIMAPQuotaOperation_limit(struct CIMAPQuotaOperation self)
                CF_SWIFT_NAME(CIMAPQuotaOperation.limit(self:));
    
    void        CIMAPQuotaOperation_release(CIMAPQuotaOperation self)
                CF_SWIFT_NAME(CIMAPQuotaOperation.result(self:));
    
#ifdef __cplusplus
}

CIMAPQuotaOperation CIMAPQuotaOperation_new(mailcore::IMAPQuotaOperation *operation);
#endif

#endif /* CIMAPQuotaOperation_hpp */
