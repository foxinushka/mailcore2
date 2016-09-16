#ifndef MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H

#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPCopyMessagesOperation {
        ref self;
    };
    typedef struct CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation;

    CIMAPCopyMessagesOperation wrapCIMAPCopyMessagesOperation(ref operation);
    void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation self);

#ifdef __cplusplus
}
#endif

#endif