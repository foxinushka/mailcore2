#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchContentOperation;
}

extern "C" {
#endif
    
    struct CIMAPFetchContentOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchContentOperation*    instance;
#else
        void*                                   instance;
#endif
    };
    typedef struct CIMAPFetchContentOperation CIMAPFetchContentOperation;
    
    CData   CIMAPFetchContentOperation_data(struct CIMAPFetchContentOperation self)
            CF_SWIFT_NAME(CIMAPFetchContentOperation.data(self:));
    
    void    CIMAPFetchContentOperation_release(CIMAPFetchContentOperation self)
            CF_SWIFT_NAME(CIMAPFetchContentOperation.release(self:));

#ifdef __cplusplus
}

CIMAPFetchContentOperation CIMAPFetchContentOperation_new(mailcore::IMAPFetchContentOperation *operation);
#endif

#endif
