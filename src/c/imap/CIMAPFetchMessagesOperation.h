#ifndef MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CArray.h"
#include "CIndexSet.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFetchMessagesOperation {
        CIMAPBaseOperation baseOperation;
        
        CArray      (*messages)(struct CIMAPFetchMessagesOperation self);
        CIndexSet   (*vanishedMessages)(struct CIMAPFetchMessagesOperation self);
        CArray      (*extraHeaders)(struct CIMAPFetchMessagesOperation self);
        void        (*setExtraHeaders)(struct CIMAPFetchMessagesOperation self, CArray array);
    };
    typedef struct CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation;

    void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operation);
mailcore::IMAPFetchMessagesOperation* cast(CIMAPFetchMessagesOperation self);
#endif

#endif
