#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPAppendMessageOperation {
        ref self;
    };
    typedef struct CIMAPAppendMessageOperation CIMAPAppendMessageOperation;

    CIMAPAppendMessageOperation wrapIMAPAppendMessageOperation(ref operation);
    void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation self);

#ifdef __cplusplus
}
#endif

#endif