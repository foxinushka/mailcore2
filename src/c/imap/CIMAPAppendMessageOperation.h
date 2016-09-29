#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H

#include "CIMAPBaseOperation.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPAppendMessageOperation {
        CIMAPBaseOperation baseOperation;
        
        void        (*setDate)(struct CIMAPAppendMessageOperation self, time_t date);
        time_t      (*date)(struct CIMAPAppendMessageOperation self);
        uint32_t    (*createdUID)(struct CIMAPAppendMessageOperation self);
    };
    typedef struct CIMAPAppendMessageOperation CIMAPAppendMessageOperation;

    void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation self);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCAsync.h>

CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *operation);
mailcore::IMAPAppendMessageOperation* cast(CIMAPAppendMessageOperation self);
#endif

#endif
