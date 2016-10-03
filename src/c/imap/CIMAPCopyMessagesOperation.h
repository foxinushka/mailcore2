#ifndef MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPCopyMessagesOperation;
}

extern "C" {
#endif
    
    struct CIMAPCopyMessagesOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPCopyMessagesOperation*    instance;
#else
        void*                                   instance;
#endif
        
        CDictionary (*uidMapping)(struct CIMAPCopyMessagesOperation self);
    };
    typedef struct CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation;

    void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation self);

#ifdef __cplusplus
}

CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *operation);
#endif

#endif
