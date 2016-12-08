#ifndef CSMTPOperation_h
#define CSMTPOperation_h

#include "COperation.h"

#ifdef __cplusplus

namespace mailcore {
    class SMTPOperation;
}

class CSMTPOperationCallback;

#endif

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef void (*CProgressBlock)(const void* userInfo, unsigned int current, unsigned int maximum);
    typedef struct CSMTPSession CSMTPSession;
    
    struct CSMTPOperation {
#ifdef __cplusplus
        mailcore::SMTPOperation*                    instance;
        CSMTPOperationCallback*                     _callback;
#else
        void*                                       instance;
        void*                                       _callback;
#endif
        COperation                                  cOperation;
        
        ErrorCode                   (*error)(struct CSMTPOperation self);
        struct CSMTPOperation       (*setProgressBlocks)(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo);
        const UChar*                (*lastSMTPResponse)(struct CSMTPOperation self);
        int                         (*lastSMTPResponseCode)(struct CSMTPOperation self);
    };
    typedef struct CSMTPOperation CSMTPOperation;
    
    void deleteCSMTPOperation(CSMTPOperation operation);
    
#ifdef __cplusplus
}

CSMTPOperation newCSMTPOperation(mailcore::SMTPOperation* operation);
#endif

#endif /* CSMTPOperation_h */
