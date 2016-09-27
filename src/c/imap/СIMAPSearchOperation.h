#ifndef MAILCORE_СIMAP_SEARCH_OPERATION_H
#define MAILCORE_СIMAP_SEARCH_OPERATION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPSearchOperation {
        ref self;
    };
    typedef struct CIMAPSearchOperation CIMAPSearchOperation;

    void deleteCIMAPSearchOperation(CIMAPSearchOperation self);

#ifdef __cplusplus
}
#endif

#endif
