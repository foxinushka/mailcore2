#ifndef MAILCORE_C_OPERATION_H
#define MAILCORE_C_OPERATION_H

#include "CBase.h"
#include "CMessageConstants.h"

#include <dispatch/dispatch.h>

#ifdef __cplusplus

namespace mailcore {
    class Operation;
}

class COperationCompletionCallback;

extern "C" {
#endif
    
    typedef void (*COperationCompletionBlock)(const void* ref);
    
    typedef struct COperation {
#ifdef __cplusplus
        mailcore::Operation *               instance;
        COperationCompletionCallback*       _callback;
#else
        void*                               instance;
        void*                               _callback;
#endif
    } COperation;
    
    
    dispatch_queue_t    COperation_callbackDispatchQueue(struct COperation self)
                        CF_SWIFT_NAME(getter:COperation.callbackDispatchQueue(self:));
    
    void                COperation_setCallbackDispatchQueue(struct COperation self, dispatch_queue_t queue)
                        CF_SWIFT_NAME(setter:COperation.callbackDispatchQueue(self:newValue:));
    
    bool                COperation_shouldRunWhenCancelled(struct COperation self)
                        CF_SWIFT_NAME(getter:COperation.shouldRunWhenCancelled(self:));
    
    void                COperation_setShouldRunWhenCancelled(struct COperation self, bool shouldRunWhenCancelled)
                        CF_SWIFT_NAME(setter:COperation.shouldRunWhenCancelled(self:newValue:));
    
    struct COperation   COperation_setCompletionBlock(struct COperation self, COperationCompletionBlock block, const void* userInfo)
                        CF_SWIFT_NAME(COperation.setCompletionBlock(self:block:userInfo:));
    
    bool                COperation_isCanceled(struct COperation self)
                        CF_SWIFT_NAME(COperation.isCanceled(self:));
    
    void                COperation_cancel(struct COperation self)
                        CF_SWIFT_NAME(COperation.cancel(self:));
    
    void                COperation_start(struct COperation self)
                        CF_SWIFT_NAME(COperation.start(self:));
    
    void                COperation_release(COperation self)
                        CF_SWIFT_NAME(COperation.release(self:));

#ifdef __cplusplus
}

COperation COperation_new(mailcore::Operation *operation);
#endif

#endif
