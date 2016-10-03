#ifndef MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H
#define MAILCORE_CIMAP_FETCH_MESSAGES_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "CArray.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFetchMessagesOperation;
}

extern "C" {
#endif
    
    struct CIMAPFetchMessagesOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPFetchMessagesOperation*   instance;
#else
        void*                                   instance;
#endif
        
        CArray      (*messages)(struct CIMAPFetchMessagesOperation self);
        CIndexSet   (*vanishedMessages)(struct CIMAPFetchMessagesOperation self);
        CArray      (*extraHeaders)(struct CIMAPFetchMessagesOperation self);
        void        (*setExtraHeaders)(struct CIMAPFetchMessagesOperation self, CArray array);
    };
    typedef struct CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation;

    void deleteCIMAPFetchMessagesOperation(CIMAPFetchMessagesOperation self);

#ifdef __cplusplus
}

CIMAPFetchMessagesOperation newCIMAPFetchMessagesOperation(mailcore::IMAPFetchMessagesOperation *operation);
#endif

#endif
