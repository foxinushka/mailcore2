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
    };
    typedef struct CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation;

    CArray      CIMAPFetchMessagesOperation_messages(struct CIMAPFetchMessagesOperation self)
    			CF_SWIFT_NAME(CIMAPFetchMessagesOperation.messages(self:));

    CIndexSet   CIMAPFetchMessagesOperation_vanishedMessages(struct CIMAPFetchMessagesOperation self)
    			CF_SWIFT_NAME(CIMAPFetchMessagesOperation.vanishedMessages(self:));

    CArray      CIMAPFetchMessagesOperation_extraHeaders(struct CIMAPFetchMessagesOperation self)
    			CF_SWIFT_NAME(getter:CIMAPFetchMessagesOperation.extraHeaders(self:));

    void        CIMAPFetchMessagesOperation_setExtraHeaders(struct CIMAPFetchMessagesOperation self, CArray array)
    			CF_SWIFT_NAME(setter:CIMAPFetchMessagesOperation.extraHeaders(self:newValue:));


    void 		CIMAPFetchMessagesOperation_release(CIMAPFetchMessagesOperation self)
    			CF_SWIFT_NAME(CIMAPFetchMessagesOperation.release(self:));

#ifdef __cplusplus
}

CIMAPFetchMessagesOperation CIMAPFetchMessagesOperation_new(mailcore::IMAPFetchMessagesOperation *operation);
#endif

#endif
