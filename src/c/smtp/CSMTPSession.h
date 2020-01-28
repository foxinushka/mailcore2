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
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, hostname, setHostname)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, unsigned int, port, setPort)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, username, setUsername)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, password, setPassword)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, MailCoreString, OAuth2Token, setOAuth2Token)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, CAuthType, authType, setAuthType)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, ConnectionType, connectionType, setConnectionType)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, time_t, timeout, setTimeout)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, isCheckCertificateEnabled, setCheckCertificateEnabled)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, useHeloIPEnabled, setUseHeloIPEnabled)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, bool, isOperationQueueRunning, setOperationQueueRunning)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, setConnectionLogger, void*)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, dispatch_queue_t, dispatchQueue)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, setDispatchQueue, dispatch_queue_t)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CSMTPSession, OperationQueueRunningChangeBlock, operationQueueRunningChangeBlock, setOperationQueueRunningChangeBlock)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, void, cancelAllOperations)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, loginOperation)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendMessageOperation, CData)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendOperationWithDataAndFromAndRecipients, CData, CAddress, CArray)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, sendOperationWithContentsOfFile, MailCoreString, CAddress, CArray)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, checkAccountOperation, CAddress)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, checkAccountOperationWithFromAndTo, CAddress, CAddress)
    C_SYNTHESIZE_FUNC_DEFINITION(CSMTPSession, CSMTPOperation, noopOperation)

    
    CMAILCORE_EXPORT CSMTPSession   CSMTPSession_new(CConnectionLogger logger, CConnectionLoggerRelease releaseLoggerBlock);

    CMAILCORE_EXPORT void           CSMTPSession_release(CSMTPSession self)
                                    CF_SWIFT_NAME(CSMTPSession.release(self:));
    
#ifdef __cplusplus
}
#endif


#endif /* CSMTPSession_h */
