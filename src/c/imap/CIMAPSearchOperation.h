#ifndef MAILCORE_СIMAP_SEARCH_OPERATION_H
#define MAILCORE_СIMAP_SEARCH_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIndexSet.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPSearchOperation;
}

extern "C" {
#endif
    
    struct CIMAPSearchOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPSearchOperation*  instance;
#else
        void*                           instance;
#endif
    };
    typedef struct CIMAPSearchOperation CIMAPSearchOperation;
    
    CIndexSet   CIMAPSearchOperation_uids(struct CIMAPSearchOperation self)
                CF_SWIFT_NAME(CIMAPSearchOperation.uids(self:));

    void        CIMAPSearchOperation_release(CIMAPSearchOperation self)
                CF_SWIFT_NAME(CIMAPSearchOperation.release(self:));
    
#ifdef __cplusplus
}

CIMAPSearchOperation CIMAPSearchOperation_new(mailcore::IMAPSearchOperation *operation);
#endif

#endif
