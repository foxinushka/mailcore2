#ifndef CSMTPSession_h
#define CSMTPSession_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "time.h"
#include "CAddress.h"
#include "CArray.h"
#include "CSMTPOperation.h"

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
    
    const UChar*        CSMTPSession_hostname(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.hostname(self:));

    unsigned int        CSMTPSession_port(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.port(self:));

    const UChar*        CSMTPSession_username(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.username(self:));

    const UChar*        CSMTPSession_password(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.password(self:));

    const UChar*        CSMTPSession_OAuth2Token(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.OAuth2Token(self:));

    AuthType            CSMTPSession_authType(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.authType(self:));

    ConnectionType      CSMTPSession_connectionType(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.connectionType(self:));

    time_t              CSMTPSession_timeout(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.timeout(self:));

    bool                CSMTPSession_isCheckCertificateEnabled(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.isCheckCertificateEnabled(self:));

    bool                CSMTPSession_useHeloIPEnabled(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.useHeloIPEnabled(self:));

    bool                CSMTPSession_isOperationQueueRunning(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.isOperationQueueRunning(self:));
    
    dispatch_queue_t    CSMTPSession_dispatchQueue(struct CSMTPSession self)
                        CF_SWIFT_NAME(CSMTPSession.dispatchQueue(self:));
    
    ConnectionLogger    CSMTPSession_connectionLogger(struct CSMTPSession self)
                        CF_SWIFT_NAME(getter:CSMTPSession.connectionLogger(self:));
    
    OperationQueueRunningChangeBlock    CSMTPSession_operationQueueRunningChangeBlock(struct CSMTPSession self)
                                        CF_SWIFT_NAME(getter:CSMTPSession.operationQueueRunningChangeBlock(self:));


    
    void                CSMTPSession_setHostname(struct CSMTPSession self, const UChar *hostname)
                        CF_SWIFT_NAME(setter:CSMTPSession.hostname(self:newValue:));

    void                CSMTPSession_setPort(struct CSMTPSession self, unsigned int port)
                        CF_SWIFT_NAME(setter:CSMTPSession.port(self:newValue:));

    void                CSMTPSession_setUsername(struct CSMTPSession self, const UChar *username)
                        CF_SWIFT_NAME(setter:CSMTPSession.username(self:newValue:));

    void                CSMTPSession_setPassword(struct CSMTPSession self, const UChar *password)
                        CF_SWIFT_NAME(setter:CSMTPSession.password(self:newValue:));

    void                CSMTPSession_setOAuth2Token(struct CSMTPSession self, const UChar *token)
                        CF_SWIFT_NAME(setter:CSMTPSession.OAuth2Token(self:newValue:));

    void                CSMTPSession_setAuthType(struct CSMTPSession self, AuthType authType)
                        CF_SWIFT_NAME(setter:CSMTPSession.authType(self:newValue:));

    void                CSMTPSession_setConnectionType(struct CSMTPSession self, ConnectionType connectionType)
                        CF_SWIFT_NAME(setter:CSMTPSession.connectionType(self:newValue:));

    void                CSMTPSession_setTimeout(struct CSMTPSession self, time_t timeout)
                        CF_SWIFT_NAME(setter:CSMTPSession.timeout(self:newValue:));

    void                CSMTPSession_setCheckCertificateEnabled(struct CSMTPSession self, bool checkCertificateEnabled)
                        CF_SWIFT_NAME(setter:CSMTPSession.isCheckCertificateEnabled(self:newValue:));

    void                CSMTPSession_setUseHeloIPEnabled(struct CSMTPSession self, bool useHeloIPEnabled)
                        CF_SWIFT_NAME(setter:CSMTPSession.useHeloIPEnabled(self:newValue:));
    
    void                CSMTPSession_setConnectionLogger(struct CSMTPSession self, ConnectionLogger logger)
                        CF_SWIFT_NAME(setter:CSMTPSession.connectionLogger(self:newValue:));

    void                CSMTPSession_setOperationQueueRunningChangeBlock(struct CSMTPSession self, OperationQueueRunningChangeBlock logger)
                        CF_SWIFT_NAME(setter:CSMTPSession.operationQueueRunningChangeBlock(self:newValue:));
    
    void                CSMTPSession_setDispatchQueue(struct CSMTPSession self, dispatch_queue_t queue)
                        CF_SWIFT_NAME(CSMTPSession.setDispatchQueue(self:newValue:));
    
    

    void                CSMTPSession_cancelAllOperations(struct CSMTPSession self)
                        CF_SWIFT_NAME(CSMTPSession.cancelAllOperations(self:));
    
    CSMTPOperation      CSMTPSession_loginOperation(struct CSMTPSession self)
                        CF_SWIFT_NAME(CSMTPSession.loginOperation(self:));

    CSMTPOperation      CSMTPSession_sendOperationWithData(struct CSMTPSession self, const char* messageDataBytes, unsigned int messageDataLenght)
                        CF_SWIFT_NAME(CSMTPSession.sendOperationWithData(self:messageDataBytes:messageDataLenght:));

    CSMTPOperation      CSMTPSession_sendOperationWithDataAndFromAndRecipients(struct CSMTPSession self, const char* messageDataBytes,
                                                                               unsigned int messageDataLenght, CAddress from , CArray recipients)
                        CF_SWIFT_NAME(CSMTPSession.sendOperationWithDataAndFromAndRecipients(self:messageDataBytes:messageDataLenght:from:recipients:));

    CSMTPOperation      CSMTPSession_sendOperationWithContentsOfFile(struct CSMTPSession self, const UChar* path,  CAddress from,  CArray recipients)
                        CF_SWIFT_NAME(CSMTPSession.sendOperationWithContentsOfFile(self:path:from:recipients:));

    CSMTPOperation      CSMTPSession_checkAccountOperationWithFrom(struct CSMTPSession self, CAddress from)
                        CF_SWIFT_NAME(CSMTPSession.checkAccountOperationWithFrom(self:from:));

    CSMTPOperation      CSMTPSession_noopOperation(struct CSMTPSession self)
                        CF_SWIFT_NAME(CSMTPSession.noopOperation(self:));

    
    CSMTPSession        CSMTPSession_new()
                        CF_SWIFT_NAME(CSMTPSession.init());

    void                CSMTPSession_release(CSMTPSession self)
                        CF_SWIFT_NAME(CSMTPSession.release(self:));
    
#ifdef __cplusplus
}
#endif


#endif /* CSMTPSession_h */
