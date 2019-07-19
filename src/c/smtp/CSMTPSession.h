#ifndef CSMTPSession_h
#define CSMTPSession_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "time.h"
#include "CAddress.h"
#include "CArray.h"
#include "CSMTPOperation.h"

#include "MailCoreString.h"

#include <dispatch/dispatch.h>

#ifdef __cplusplus

namespace mailcore {
    class SMTPAsyncSession;
}

class CSMTPCallbackBridge;

extern "C" {
#endif
    
    struct CSMTPSession {
#ifdef __cplusplus
        mailcore::SMTPAsyncSession*     instance;
        CSMTPCallbackBridge*            _callback;
#else
        void*                           instance;
        void*                           _callback;
#endif
    };
    typedef struct CSMTPSession CSMTPSession;
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, hostname, setHostname)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, unsigned int, port, setPort)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, username, setUsername)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, password, setPassword)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, OAuth2Token, setOAuth2Token)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, CAuthType, authType, setAuthType)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, ConnectionType, connectionType, setConnectionType)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, time_t, timeout, setTimeout)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, isCheckCertificateEnabled, setCheckCertificateEnabled)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, useHeloIPEnabled, setUseHeloIPEnabled)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, isOperationQueueRunning, setOperationQueueRunning)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, setConnectionLogger, void*)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, dispatch_queue_t, dispatchQueue)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, setDispatchQueue, dispatch_queue_t)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, OperationQueueRunningChangeBlock, operationQueueRunningChangeBlock, setOperationQueueRunningChangeBlock)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, cancelAllOperations)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, loginOperation)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendMessageOperation, CData)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendOperationWithDataAndFromAndRecipients, CData, CAddress, CArray)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendOperationWithContentsOfFile, MailCoreString, CAddress, CArray)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, checkAccountOperation, CAddress)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, checkAccountOperationWithFromAndTo, CAddress, CAddress)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, noopOperation)

    
    CMAILCORE_EXPORT CSMTPSession   CSMTPSession_new(CConnectionLogger logger, CConnectionLoggerRelease releaseLoggerBlock);

    CMAILCORE_EXPORT void           CSMTPSession_release(CSMTPSession self)
                                    CF_SWIFT_NAME(CSMTPSession.release(self:));
    
#ifdef __cplusplus
}
#endif


#endif /* CSMTPSession_h */
