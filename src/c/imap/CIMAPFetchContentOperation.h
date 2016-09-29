#ifndef MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H
#define MAILCORE_CIMAP_FETCH_CONTENT_OPERATION_H

#include "CIMAPBaseOperation.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPFetchContentOperation {
        CIMAPBaseOperation baseOperation;
        
        CData (*data)(struct CIMAPFetchContentOperation self);
    };
    typedef struct CIMAPFetchContentOperation CIMAPFetchContentOperation;

    void deleteCIMAPFetchContentOperation(CIMAPFetchContentOperation self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPFetchContentOperation newCIMAPFetchContentOperation(mailcore::IMAPFetchContentOperation *operation);
mailcore::IMAPFetchContentOperation* cast(CIMAPFetchContentOperation self);
#endif

#endif
