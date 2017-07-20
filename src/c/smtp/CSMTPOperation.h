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
    };
    typedef struct CSMTPOperation CSMTPOperation;
    
    ErrorCode                   CSMTPOperation_error(struct CSMTPOperation self)
                                CF_SWIFT_NAME(getter:CSMTPOperation.error(self:));
    
    struct CSMTPOperation       CSMTPOperation_setProgressBlocks(struct CSMTPOperation self, CProgressBlock progressBlock, const void* userInfo)
                                CF_SWIFT_NAME(CSMTPOperation.setProgressBlocks(self:block:userInfo:));
    
    const UChar*                CSMTPOperation_lastSMTPResponse(struct CSMTPOperation self)
                                CF_SWIFT_NAME(getter:CSMTPOperation.lastSMTPResponse(self:));
    
    int                         CSMTPOperation_lastSMTPResponseCode(struct CSMTPOperation self)
                                CF_SWIFT_NAME(getter:CSMTPOperation.lastSMTPResponseCode(self:));
    
    void                        CSMTPOperation_release(CSMTPOperation operation)
                                CF_SWIFT_NAME(CSMTPOperation.release(self:));
    
#ifdef __cplusplus
}

CSMTPOperation CSMTPOperation_new(mailcore::SMTPOperation* operation);
#endif

#endif /* CSMTPOperation_h */
