#ifndef MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H
#define MAILCORE_CIMAP_APPEND_MESSAGE_OPERATION_H

#include "CIMAPBaseOperation.h"
#include "stdint.h"
#include "time.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPAppendMessageOperation;
}

extern "C" {
#endif
    
    struct CIMAPAppendMessageOperation {
        CIMAPBaseOperation baseOperation;
#ifdef __cplusplus
        mailcore::IMAPAppendMessageOperation*   instance;
#else
        void*                                   instance;
#endif
        
        void        (*setDate)(struct CIMAPAppendMessageOperation self, time_t date);
        time_t      (*date)(struct CIMAPAppendMessageOperation self);
        uint32_t    (*createdUID)(struct CIMAPAppendMessageOperation self);
    };
    typedef struct CIMAPAppendMessageOperation CIMAPAppendMessageOperation;

    void deleteIMAPAppendMessageOperation(CIMAPAppendMessageOperation self);

#ifdef __cplusplus
}

CIMAPAppendMessageOperation newIMAPAppendMessageOperation(mailcore::IMAPAppendMessageOperation *operation);
#endif

#endif
