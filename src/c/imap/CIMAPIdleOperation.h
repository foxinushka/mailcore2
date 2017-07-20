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
    };
    typedef struct CIMAPIdleOperation CIMAPIdleOperation;
    
    void        CIMAPIdleOperation_interruptIdle(struct CIMAPIdleOperation self)
                CF_SWIFT_NAME(CIMAPIdleOperation.interruptIdle(self:));
    
#ifdef __cplusplus
}

CIMAPIdleOperation CIMAPIdleOperation_new(mailcore::IMAPIdleOperation *operation);
#endif

#endif /* CIMAPIdleOperation_h */
