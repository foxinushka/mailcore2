#ifndef MAILCORE_C_OPERATION_H
#define MAILCORE_C_OPERATION_H

#include "CBase.h"
#include "CMessageConstants.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (^COperationCompletionBlock)();
    
    struct COperation {
        ref     nativeInstance;
        ref     _callback;
        
        void    (*setCompletionBlock)(struct COperation self, COperationCompletionBlock block);
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
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

COperation newCOperation(mailcore::Operation *operation);
mailcore::Operation* cast(COperation self);
#endif

#endif
