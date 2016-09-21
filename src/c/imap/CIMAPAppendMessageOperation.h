#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H

#include <MailCore/CBase.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPAppendMessageOperation {
        ref self;
    };
    typedef struct CIMAPAppendMessageOperation CIMAPAppendMessageOperation;

    void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation self);

#ifdef __cplusplus
}
#endif

#endif
