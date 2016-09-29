#ifndef MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_COPY_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CDictionary.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPCopyMessagesOperation {
        CIMAPBaseOperation baseOperation;
        
        CDictionary (*uidMapping)(struct CIMAPCopyMessagesOperation self);
    };
    typedef struct CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation;

    void deleteCIMAPCopyMessagesOperation(CIMAPCopyMessagesOperation self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPCopyMessagesOperation newCIMAPCopyMessagesOperation(mailcore::IMAPCopyMessagesOperation *operation);
mailcore::IMAPCopyMessagesOperation * cast(CIMAPCopyMessagesOperation self);
#endif

#endif
