#include <MailCore/MCAsyncSMTP.h>
#ifdef __ANDROID__
#include <MailCore/MCOperationQueueCallback.h>
#else
#include "MCOperationQueueCallback.h"
#endif


#include "CSMTPSession.h"
#include "CBase+Private.h"
#include "CSMTPOperation.h"

#define nativeType mailcore::SMTPAsyncSession
#define structName CSMTPSession

C_SYNTHESIZE_STRING(setHostname, hostname)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setPort, port)
C_SYNTHESIZE_STRING(setUsername, username)
C_SYNTHESIZE_STRING(setPassword, password)
C_SYNTHESIZE_ENUM(ConnectionType, mailcore::ConnectionType, setConnectionType, connectionType)
C_SYNTHESIZE_SCALAR(time_t, time_t, setTimeout, timeout)
C_SYNTHESIZE_BOOL(setCheckCertificateEnabled, isCheckCertificateEnabled)
C_SYNTHESIZE_STRING(setOAuth2Token, OAuth2Token)
C_SYNTHESIZE_ENUM(AuthType, mailcore::AuthType, setAuthType, authType)
C_SYNTHESIZE_BOOL(setUseHeloIPEnabled, useHeloIPEnabled)

bool isOperationQueueRunning(struct CSMTPSession self);

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
    COperationQueueRunningChangeBlock mQueueRunningChangeBlock;
};

CSMTPSession newCSMTPSession() {
    CSMTPSession self;
    self.instance = new mailcore::SMTPAsyncSession();
    self._callback = new CSMTPCallbackBridge();
    
    self.hostname = &hostname;
    self.port = &port;
    self.username = &username;
    self.password = &password;
    self.OAuth2Token = &OAuth2Token;
    self.authType = &authType;
    self.connectionType = &connectionType;
    self.timeout = &timeout;
    self.isCheckCertificateEnabled = &isCheckCertificateEnabled;
    self.useHeloIPEnabled = &useHeloIPEnabled;
    self.isOperationQueueRunning = &isOperationQueueRunning;
    self.setHostname = &setHostname;
    self.setPort = &setPort;
    self.setUsername = &setUsername;
    self.setPassword = &setPassword;
    self.setOAuth2Token = &setOAuth2Token;
    self.setAuthType = &setAuthType;
    self.setConnectionType = &setConnectionType;
    self.setTimeout = &setTimeout;
    self.setCheckCertificateEnabled = &setCheckCertificateEnabled;
    self.setUseHeloIPEnabled = &setUseHeloIPEnabled;
    
    return self;
}

void deleteCSMTPSession(CSMTPSession self) {
    C_SAFE_RELEASE(self._callback);
    self.instance->setConnectionLogger(NULL);
    self.instance->release();
}

bool isOperationQueueRunning(struct CSMTPSession self) {
    return self.instance->isOperationQueueRunning();
}

void setConnectionLogger(struct CSMTPSession self, CConnectionLogger logger) {
    self._callback->mLogger = logger;
    if (logger != NULL) {
        self.instance->setConnectionLogger(self._callback);
    }
    else {
        self.instance->setConnectionLogger(NULL);
    }
}

void setOperationQueueRunningChangeBlock(struct CSMTPSession self, COperationQueueRunningChangeBlock queueRunningChangeBlock) {
    self._callback->mQueueRunningChangeBlock = queueRunningChangeBlock;
    if (queueRunningChangeBlock != NULL) {
        self.instance->setOperationQueueCallback(self._callback);
    }
    else {
        self.instance->setOperationQueueCallback(NULL);
    }
}

CSMTPOperation loginOperation(struct CSMTPSession self) {
    return newCSMTPOperation(self.instance->loginOperation());
}

CSMTPOperation sendOperationWithData(struct CSMTPSession self, char* messageDataBytes, unsigned int messageDataLenght){
    return newCSMTPOperation(self.instance->sendMessageOperation(new mailcore::Data(messageDataBytes, messageDataLenght)));
}

CSMTPOperation sendOperationWithDataAndForm(struct CSMTPSession self, char* messageDataBytes, unsigned int messageDataLenght, CAddress from , CArray recipients) {
    return newCSMTPOperation(self.instance->sendMessageOperation(from.instance, recipients.instance, new mailcore::Data(messageDataBytes, messageDataLenght)));
}

CSMTPOperation sendOperationWithContentsOfFile(struct CSMTPSession self, const UChar* path,  CAddress from,  CArray recipients) {
    return newCSMTPOperation(self.instance->sendMessageOperation(from.instance, recipients.instance, new mailcore::String(path)));
}

CSMTPOperation checkAccountOperationWithFrom(struct CSMTPSession self, CAddress from) {
    return newCSMTPOperation(self.instance->checkAccountOperation(from.instance));
}

CSMTPOperation noopOperation(struct CSMTPSession self) {
    return newCSMTPOperation(self.instance->noopOperation());
}

