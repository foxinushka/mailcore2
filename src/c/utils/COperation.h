#ifndef MAILCORE_C_OPERATION_H
#define MAILCORE_C_OPERATION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct COperation {
        ref     self;
        ref     inheritor;
        ref     _callback;
        bool    _started;
        void    (*_operationCompleted)(struct COperation *self);
        bool    (*isCanceled)(struct COperation *self);
        void    (*cancel)(struct COperation *self);
        void    (*start)(struct COperation *self);
        
        // virtual
        void    (*operationCompleted)(struct COperation *self);
    };
    typedef struct COperation COperation;

    COperation initCOperation(/*mailcore::Operation*/ref operation);
    void deleteCOperation(COperation self);

#ifdef __cplusplus
}
#endif

#endif
