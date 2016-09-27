#ifndef CIMAPIdleOperation_h
#define CIMAPIdleOperation_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CIMAPBaseOperation.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPIdleOperation {
        CIMAPBaseOperation  operation;

        void    (*interruptIdle)(struct CIMAPIdleOperation *self);
    };
    typedef struct CIMAPIdleOperation CIMAPIdleOperation;
    
    void deleteCIMAPIdleOperation(CIMAPIdleOperation *self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPIdleOperation newCIMAPIdleOperation(mailcore::IMAPIdleOperation *operation);
#endif

#endif /* CIMAPIdleOperation_h */
