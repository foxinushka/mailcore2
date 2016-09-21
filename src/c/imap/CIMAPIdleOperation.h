#ifndef MAILCORE_CIMAP_IDLE_OPERATION_H
#define MAILCORE_CIMAP_IDLE_OPERATION_H

#include <MailCore/CMessageConstants.h>
#include <MailCore/CIMAPBaseOperation.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (^CIMAPIdleOperationCompletionType)(ErrorCode error);
    
    struct CIMAPIdleOperation {
        CIMAPBaseOperation                      ancestor;
        CIMAPIdleOperationCompletionType       _completionBlock;
        
        void (*start)(struct CIMAPIdleOperation *self, CIMAPIdleOperationCompletionType completionBlock);
        void (*cancel)(struct CIMAPIdleOperation *self);
        void (*interruptIdle)(struct CIMAPIdleOperation *self);
    };
    typedef struct CIMAPIdleOperation CIMAPIdleOperation;

    void deleteCIMAPIdleOperation(CIMAPIdleOperation *operation);

#ifdef __cplusplus
}
#endif

#endif
