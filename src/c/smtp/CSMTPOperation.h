#ifndef CSMTPOperation_h
#define CSMTPOperation_h

#include "COperation.h"
#include "MailCoreString.h"

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
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CSMTPOperation)
    
    C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CSMTPOperation, ErrorCode, error)
    C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CSMTPOperation, MailCoreString, lastSMTPResponse)
    C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CSMTPOperation, int, lastSMTPResponseCode)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPOperation, CSMTPOperation, setProgressBlocks, CProgressBlock, const void*)
    
    CMAILCORE_EXPORT void       CSMTPOperation_retain(CSMTPOperation operation)
                                CF_SWIFT_NAME(CSMTPOperation.retain(self:));
    
    CMAILCORE_EXPORT void       CSMTPOperation_release(CSMTPOperation operation)
                                CF_SWIFT_NAME(CSMTPOperation.release(self:));
    
#ifdef __cplusplus
}

CSMTPOperation CSMTPOperation_new(mailcore::SMTPOperation* operation);
#endif

#endif /* CSMTPOperation_h */
