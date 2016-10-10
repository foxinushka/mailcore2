#ifndef CSMTPSession_h
#define CSMTPSession_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "time.h"
#include "CAddress.h"
#include "CArray.h"
#include "CSMTPOperation.h"

#ifdef __ANDROID__
#else
#include <dispatch/dispatch.h>
#endif

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
        
        const UChar*    (*hostname)(struct CSMTPSession self);
        unsigned int    (*port)(struct CSMTPSession self);
        const UChar*    (*username)(struct CSMTPSession self);
        const UChar*    (*password)(struct CSMTPSession self);
        const UChar*    (*OAuth2Token)(struct CSMTPSession self);
        AuthType        (*authType)(struct CSMTPSession self);
        ConnectionType  (*connectionType)(struct CSMTPSession self);
        time_t          (*timeout)(struct CSMTPSession self);
        bool            (*isCheckCertificateEnabled)(struct CSMTPSession self);
        bool            (*useHeloIPEnabled)(struct CSMTPSession self);
        bool            (*isOperationQueueRunning)(struct CSMTPSession self);
        
#ifdef __ANDROID__
#else
        dispatch_queue_t    (*dispatchQueue)(struct CSMTPSession self);
        void                (*setDispatchQueue)(struct CSMTPSession self, dispatch_queue_t queue);
#endif
        
        void    (*setHostname)(struct CSMTPSession self, const UChar *hostname);
        void    (*setPort)(struct CSMTPSession self, unsigned int port);
        void    (*setUsername)(struct CSMTPSession self, const UChar *username);
        void    (*setPassword)(struct CSMTPSession self, const UChar *password);
        void    (*setOAuth2Token)(struct CSMTPSession self, const UChar *token);
        void    (*setAuthType)(struct CSMTPSession self, AuthType authType);
        void    (*setConnectionType)(struct CSMTPSession self, ConnectionType connectionType);
        void    (*setTimeout)(struct CSMTPSession self, time_t timeout);
        void    (*setCheckCertificateEnabled)(struct CSMTPSession self, bool checkCertificateEnabled);
        void    (*setUseHeloIPEnabled)(struct CSMTPSession self, bool useHeloIPEnabled);
        
        void    (*setConnectionLogger)(struct CSMTPSession self, ConnectionLogger logger);
        void    (*setOperationQueueRunningChangeBlock)(struct CSMTPSession self, OperationQueueRunningChangeBlock logger);
        void    (*cancelAllOperations)(struct CSMTPSession self);
        
        CSMTPOperation (*loginOperation)(struct CSMTPSession self);
        CSMTPOperation (*sendOperationWithData)(struct CSMTPSession self, const char* messageDataBytes, unsigned int messageDataLenght);
        CSMTPOperation (*sendOperationWithDataAndFromAndRecipients)(struct CSMTPSession self, const char* messageDataBytes, unsigned int messageDataLenght, CAddress from , CArray recipients);
        CSMTPOperation (*sendOperationWithContentsOfFile)(struct CSMTPSession self, const UChar* path,  CAddress from,  CArray recipients);
        CSMTPOperation (*checkAccountOperationWithFrom)(struct CSMTPSession self, CAddress from);
        CSMTPOperation (*noopOperation)(struct CSMTPSession self);
        
    };
    typedef struct CSMTPSession CSMTPSession;
    
    CSMTPSession newCSMTPSession();
    void deleteCSMTPSession(CSMTPSession self);
    
#ifdef __cplusplus
}
#endif


#endif /* CSMTPSession_h */
