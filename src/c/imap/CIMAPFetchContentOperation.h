#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H

#include <MailCore/CBase.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFetchContentOperation {
        ref self;
    };
    typedef struct CIMAPFetchContentOperation CIMAPFetchContentOperation;

    void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation self);

#ifdef __cplusplus
}
#endif

#endif
