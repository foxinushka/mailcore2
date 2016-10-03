#ifndef CIMAPIdleOperation_h
#define CIMAPIdleOperation_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CIMAPBaseOperation.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPIdleOperation;
}

extern "C" {
#endif
    
    struct CIMAPIdleOperation {
        CIMAPBaseOperation  operation;
#ifdef __cplusplus
        mailcore::IMAPIdleOperation*    instance;
#else
        void*                           instance;
#endif

        void    (*interruptIdle)(struct CIMAPIdleOperation self);
    };
    typedef struct CIMAPIdleOperation CIMAPIdleOperation;
    
#ifdef __cplusplus
}

CIMAPIdleOperation newCIMAPIdleOperation(mailcore::IMAPIdleOperation *operation);
#endif

#endif /* CIMAPIdleOperation_h */
