#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H

#include "CIMAPBaseOperation.h"

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
        
        CData (*data)(struct CIMAPFetchContentOperation self);
    };
    typedef struct CIMAPFetchContentOperation CIMAPFetchContentOperation;

    void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation self);

#ifdef __cplusplus
}

CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operation);
#endif

#endif
