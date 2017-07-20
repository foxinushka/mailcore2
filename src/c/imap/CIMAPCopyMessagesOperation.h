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
    };
    typedef struct CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation;
    
    CDictionary     CIMAPCopyMessagesOperation_uidMapping(struct CIMAPCopyMessagesOperation self)
                    CF_SWIFT_NAME(CIMAPCopyMessagesOperation.uidMapping(self:));
    
    void            CIMAPCopyMessagesOperation_release(CIMAPCopyMessagesOperation self)
                    CF_SWIFT_NAME(CIMAPCopyMessagesOperation.release(self:));

#ifdef __cplusplus
}

CIMAPCopyMessagesOperation CIMAPCopyMessagesOperation_new(mailcore::IMAPCopyMessagesOperation *operation);
#endif

#endif
