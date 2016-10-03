#ifndef MAILCORE_C_OPERATION_H
#define MAILCORE_C_OPERATION_H

#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus

namespace mailcore {
    class Operation;
}

class COperationCompletionCallback;

extern "C" {
#endif
    
    typedef void (^COperationCompletionBlock)();
    
    struct COperation {
#ifdef __cplusplus
        mailcore::Operation *               instance;
        COperationCompletionCallback*       _callback;
#else
        void*                               instance;
        void*                               _callback;
#endif
        
        struct COperation    (*setCompletionBlock)(struct COperation self, COperationCompletionBlock block);
        bool    (*isCanceled)(struct COperation self);
        bool    (*shouldRunWhenCancelled)(struct COperation self);
        void    (*setShouldRunWhenCancelled)(struct COperation self, bool shouldRunWhenCancelled);
        void    (*cancel)(struct COperation self);
        void    (*start)(struct COperation self);
    };
    typedef struct COperation COperation;
    
    void deleteCOperation(COperation self);

#ifdef __cplusplus
}

COperation newCOperation(mailcore::Operation *operation);
#endif

#endif
