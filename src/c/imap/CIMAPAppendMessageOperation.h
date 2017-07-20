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
    };
    typedef struct CIMAPAppendMessageOperation CIMAPAppendMessageOperation;
    
    void        CIMAPAppendMessageOperation_setDate(struct CIMAPAppendMessageOperation self, time_t date)
                CF_SWIFT_NAME(setter:CIMAPAppendMessageOperation.date(self:newValue:));
    
    time_t      CIMAPAppendMessageOperation_date(struct CIMAPAppendMessageOperation self)
                CF_SWIFT_NAME(getter:CIMAPAppendMessageOperation.date(self:));
    
    uint32_t    CIMAPAppendMessageOperation_createdUID(struct CIMAPAppendMessageOperation self)
                CF_SWIFT_NAME(CIMAPAppendMessageOperation.createdUID(self:));
    
    void        CIMAPAppendMessageOperation_release(CIMAPAppendMessageOperation self)
                CF_SWIFT_NAME(CIMAPAppendMessageOperation.release(self:));

#ifdef __cplusplus
}

CIMAPAppendMessageOperation CIMAPAppendMessageOperation_new(mailcore::IMAPAppendMessageOperation *operation);
#endif

#endif
