#ifndef MAILCORE_СIMAP_SEARCH_OPERATION_H
#define MAILCORE_СIMAP_SEARCH_OPERATION_H

#include "CBase.h"
#include "CIMAPBaseOperation.h"
#include "CIndexSet.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPSearchOperation {
        CIMAPBaseOperation baseOperation;
        
        CIndexSet (*uids)(struct CIMAPSearchOperation self);
    };
    typedef struct CIMAPSearchOperation CIMAPSearchOperation;
    
    void deleteCIMAPSearchOperation(CIMAPSearchOperation self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

extern "C" CIMAPSearchOperation newCIMAPSearchOperation(mailcore::IMAPSearchOperation *operation);
mailcore::IMAPSearchOperation * cast(CIMAPSearchOperation self);
#endif

#endif
