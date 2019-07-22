#ifndef MAILCORE_C_OPERATION_H
#define MAILCORE_C_OPERATION_H

#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"
#include "CData.h"

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
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(COperation)
    
    // TODO: should be property, but swift doesn;t recognize dispatch_queue_t <--> DispatchQueue bridging
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, dispatch_queue_t, callbackDispatchQueue)
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, void, setCallbackDispatchQueue, dispatch_queue_t)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(COperation, bool, shouldRunWhenCancelled, setShouldRunWhenCancelled)
    
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, COperation, setCompletionBlock, COperationCompletionBlock, const void*)
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, COperation, clearCompletionBlock)
    
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, bool, isCancelled)
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, void, cancel)
    C_SYNTHESIZE_FUNC_DEFINITION(COperation, void, start)
    
    CMAILCORE_EXPORT void   COperation_retain(COperation self)
                            CF_SWIFT_NAME(COperation.retain(self:));
    
    CMAILCORE_EXPORT void   COperation_release(COperation self)
                            CF_SWIFT_NAME(COperation.release(self:));
    
    CMAILCORE_EXPORT int    COperation_retainCount(COperation self)
                            CF_SWIFT_NAME(COperation.retainCount(self:));;

#ifdef __cplusplus
}

COperation COperation_new(mailcore::Operation *operation);
#endif

#endif
