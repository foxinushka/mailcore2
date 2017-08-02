#include <MailCore/MCAsyncSMTP.h>
#ifdef __ANDROID__
#include <MailCore/MCOperationQueueCallback.h>
#else
#include "MCOperationQueueCallback.h"
#endif


#include "CSMTPSession.h"
#include "CSMTPOperation.h"

#define nativeType mailcore::SMTPAsyncSession
#define structName CSMTPSession

#include "CBase+Private.h"

C_SYNTHESIZE_STRING(setHostname, hostname)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setPort, port)
C_SYNTHESIZE_STRING(setUsername, username)
C_SYNTHESIZE_STRING(setPassword, password)
C_SYNTHESIZE_ENUM(ConnectionType, mailcore::ConnectionType, setConnectionType, connectionType)
C_SYNTHESIZE_SCALAR(time_t, time_t, setTimeout, timeout)
C_SYNTHESIZE_BOOL(setCheckCertificateEnabled, isCheckCertificateEnabled)
C_SYNTHESIZE_STRING(setOAuth2Token, OAuth2Token)
C_SYNTHESIZE_ENUM(CAuthType, mailcore::AuthType, setAuthType, authType)
C_SYNTHESIZE_BOOL(setUseHeloIPEnabled, useHeloIPEnabled)
C_SYNTHESIZE_SCALAR(dispatch_queue_t, dispatch_queue_t, setDispatchQueue, dispatchQueue)

#undef nativeType
#undef structName

typedef ConnectionLogger CConnectionLogger;

class CSMTPCallbackBridge : public mailcore::Object, public mailcore::ConnectionLogger, public mailcore::OperationQueueCallback {
public:
    CSMTPCallbackBridge()
    {
        
    }
    
    virtual void log(void * sender, mailcore::ConnectionLogType logType, mailcore::Data *data)
    {
        if (mLogger != NULL) {
            mLogger(sender, static_cast<ConnectionLogType>((int)logType), data->bytes(), data->length());
        }
    }
    
    virtual void queueStartRunning()
    {
        if (mQueueRunningChangeBlock != NULL) {
            mQueueRunningChangeBlock();
        }
    }
    
    virtual void queueStoppedRunning()
    {
        if (mQueueRunningChangeBlock != NULL) {
            mQueueRunningChangeBlock();
        }
    }
    
    CConnectionLogger mLogger;
    OperationQueueRunningChangeBlock mQueueRunningChangeBlock;
};

bool CSMTPSession_isOperationQueueRunning(struct CSMTPSession self) {
    return self.instance->isOperationQueueRunning();
}

void CSMTPSession_setConnectionLogger(struct CSMTPSession self, ConnectionLogger logger) {
    self._callback->mLogger = logger;
    if (logger != NULL) {
        self.instance->setConnectionLogger(self._callback);
    }
    else {
        self.instance->setConnectionLogger(NULL);
    }
}

ConnectionLogger CSMTPSession_connectionLogger(struct CSMTPSession self) {
    return self._callback->mLogger;
}

void CSMTPSession_setOperationQueueRunningChangeBlock(struct CSMTPSession self, OperationQueueRunningChangeBlock queueRunningChangeBlock) {
    self._callback->mQueueRunningChangeBlock = queueRunningChangeBlock;
    if (queueRunningChangeBlock != NULL) {
        self.instance->setOperationQueueCallback(self._callback);
    }
    else {
        self.instance->setOperationQueueCallback(NULL);
    }
}

OperationQueueRunningChangeBlock CSMTPSession_operationQueueRunningChangeBlock(struct CSMTPSession self) {
    return self._callback->mQueueRunningChangeBlock;
}

CSMTPOperation CSMTPSession_loginOperation(struct CSMTPSession self) {
    return CSMTPOperation_new(self.instance->loginOperation());
}

CSMTPOperation CSMTPSession_sendOperationWithData(struct CSMTPSession self, const char* messageDataBytes, unsigned int messageDataLenght){
    return CSMTPOperation_new(self.instance->sendMessageOperation(new mailcore::Data(messageDataBytes, messageDataLenght)));
}

CSMTPOperation CSMTPSession_sendOperationWithDataAndFromAndRecipients(struct CSMTPSession self, const char* messageDataBytes, unsigned int messageDataLenght, CAddress from , CArray recipients) {
    return CSMTPOperation_new(self.instance->sendMessageOperation(from.instance, recipients.instance, new mailcore::Data(messageDataBytes, messageDataLenght)));
}

CSMTPOperation CSMTPSession_sendOperationWithContentsOfFile(struct CSMTPSession self, MailCoreString path,  CAddress from,  CArray recipients) {
    return CSMTPOperation_new(self.instance->sendMessageOperation(from.instance, recipients.instance, path.instance));
}

CSMTPOperation CSMTPSession_checkAccountOperationWithFrom(struct CSMTPSession self, CAddress from) {
    return CSMTPOperation_new(self.instance->checkAccountOperation(from.instance));
}

CSMTPOperation CSMTPSession_checkAccountOperation(struct CSMTPSession self, CAddress from, CAddress to) {
    return CSMTPOperation_new(self.instance->checkAccountOperation(from.instance, to.instance));
}

CSMTPOperation CSMTPSession_noopOperation(struct CSMTPSession self) {
    return CSMTPOperation_new(self.instance->noopOperation());
}

void CSMTPSession_cancelAllOperations(struct CSMTPSession self) {
    self.instance->cancelAllOperations();
}

CSMTPSession CSMTPSession_new() {
    CSMTPSession self;
    self.instance = new mailcore::SMTPAsyncSession();
    self._callback = new CSMTPCallbackBridge();
    return self;
}

void CSMTPSession_release(CSMTPSession self) {
    C_SAFE_RELEASE(self._callback);
    self.instance->setConnectionLogger(NULL);
    self.instance->release();
}

