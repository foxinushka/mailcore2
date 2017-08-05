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
    };
    typedef struct CIMAPBaseOperation CIMAPBaseOperation;
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPBaseOperation)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPBaseOperation, ErrorCode, error)
    C_SYNTHESIZE_FUNC_DEFINITION(CIMAPBaseOperation, CIMAPBaseOperation, setProgressBlocks, CIMAPProgressBlock, CIMAPProgressBlock, const void*)

    void                        CIMAPBaseOperation_release(CIMAPBaseOperation operation)
                                CF_SWIFT_NAME(CIMAPBaseOperation.release(self:));

#ifdef __cplusplus
}

CIMAPBaseOperation CIMAPBaseOperation_new(mailcore::IMAPOperation* operation);
#endif

#endif
