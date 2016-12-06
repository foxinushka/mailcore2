#ifndef MAILCORE_CIMAP_BASE_OPERATION_H
#define MAILCORE_CIMAP_BASE_OPERATION_H

#include "COperation.h"

#ifdef __cplusplus
class CIMAPBaseOperationIMAPCallback;

namespace mailcore {
    class IMAPOperation;
}

#endif

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (*CIMAPProgressBlock)(const void* userInfo, unsigned int current, unsigned int maximum);
    
    typedef struct CIMAPAsyncSession CIMAPAsyncSession;
    
    struct CIMAPBaseOperation {
#ifdef __cplusplus
        mailcore::IMAPOperation*                    instance;
        CIMAPBaseOperationIMAPCallback*             _callback;
#else
        void*                                       instance;
        void*                                       _callback;
#endif
        COperation                                  cOperation;
        
        ErrorCode                   (*error)(struct CIMAPBaseOperation self);
        struct CIMAPBaseOperation   (*setProgressBlocks)(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock, CIMAPProgressBlock bodyProgressBlock, const void* userInfo);
    };
    typedef struct CIMAPBaseOperation CIMAPBaseOperation;

    void deleteCIMAPBaseOperation(CIMAPBaseOperation operation);

#ifdef __cplusplus
}

CIMAPBaseOperation newCIMAPBaseOperation(mailcore::IMAPOperation* operation);
#endif

#endif
