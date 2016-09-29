#ifndef MAILCORE_CIMAP_BASE_OPERATION_H
#define MAILCORE_CIMAP_BASE_OPERATION_H

#include "COperation.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (^CIMAPProgressBlock)(unsigned int current, unsigned int maximum);
    
    typedef struct CIMAPAsyncSession CIMAPAsyncSession;
    
    struct CIMAPBaseOperation {
        COperation                                  cOperation;
        /*CIMAPBaseOperationIMAPCallback*/ref       _callback;
        
        ErrorCode   (*error)(struct CIMAPBaseOperation self);
        void        (*setProgressBlocks)(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock);
    };
    typedef struct CIMAPBaseOperation CIMAPBaseOperation;

    void deleteCIMAPBaseOperation(CIMAPBaseOperation *operation);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPBaseOperation newCIMAPBaseOperation(mailcore::IMAPOperation* operation);
mailcore::IMAPOperation* cast(CIMAPBaseOperation self);
#endif

#endif
