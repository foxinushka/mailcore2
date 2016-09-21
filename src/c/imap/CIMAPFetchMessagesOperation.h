#ifndef MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H

#include <MailCore/CBase.h>

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFetchMessagesOperation {
        ref self;
    };
    typedef struct CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation;

    void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation self);

#ifdef __cplusplus
}
#endif

#endif
