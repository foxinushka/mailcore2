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
    
    ErrorCode                   CIMAPBaseOperation_error(struct CIMAPBaseOperation self)
                                CF_SWIFT_NAME(CIMAPBaseOperation.error(self:));
    
    struct CIMAPBaseOperation   CIMAPBaseOperation_setProgressBlocks(struct CIMAPBaseOperation self, CIMAPProgressBlock itemProgressBlock,
                                                     CIMAPProgressBlock bodyProgressBlock, const void* userInfo)
                                CF_SWIFT_NAME(CIMAPBaseOperation.setProgressBlocks(self:itemProgressBlock:bodyProgressBlock:userInfo:));

    void                        CIMAPBaseOperation_release(CIMAPBaseOperation operation)
                                CF_SWIFT_NAME(CIMAPBaseOperation.release(self:));

#ifdef __cplusplus
}

CIMAPBaseOperation CIMAPBaseOperation_new(mailcore::IMAPOperation* operation);
#endif

#endif
