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
        
        CIndexSet (*uids)(struct CIMAPSearchOperation self);
    };
    typedef struct CIMAPSearchOperation CIMAPSearchOperation;
    
    void deleteCIMAPSearchOperation(CIMAPSearchOperation self);
    
#ifdef __cplusplus
}

CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *operation);
#endif

#endif
