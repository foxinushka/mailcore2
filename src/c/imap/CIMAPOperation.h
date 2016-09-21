#ifndef MAILCORE_CIMAP_OPERATION_H
#define MAILCORE_CIMAP_OPERATION_H

#include <MailCore/CBase.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPOperation {
        ref self;
    };
    typedef struct CIMAPOperation CIMAPOperation;
    
    void deleteCIMAPOperation(CIMAPOperation self);

#ifdef __cplusplus
}
#endif
#endif
