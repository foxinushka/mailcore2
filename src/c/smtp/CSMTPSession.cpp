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

class CSMTPCallbackBridge : public mailcore::Object, public mailcore::ConnectionLogger, public mailcore::OperationQueueCallback {
public:
    CSMTPCallbackBridge(CConnectionLogger logger, CConnectionLoggerRelease releaseLoggerBlock)
    {
        this->mLogger = logger;
        this->mReleaseBlock = releaseLoggerBlock;
    }
    
    virtual void log(void * sender, mailcore::ConnectionLogType logType, mailcore::Data *data)
    {
        if (mLogger != NULL) {
            mLogger(sender, static_cast<ConnectionLogType>((int)logType), CData_new(data), mcoLogger);
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
    
    void releaseSwiftLogger() {
        this->mReleaseBlock(this->mcoLogger);
        this->mcoLogger = NULL;
    }
    
    CConnectionLogger mLogger;
    CConnectionLoggerRelease mReleaseBlock;
    void* mcoLogger = NULL;
    OperationQueueRunningChangeBlock mQueueRunningChangeBlock;
};

bool CSMTPSession_isOperationQueueRunning(struct CSMTPSession self) {
    return self.instance->isOperationQueueRunning();
}

void CSMTPSession_setConnectionLogger(struct CSMTPSession self, void* logger) {
    self._callback->releaseSwiftLogger();
    self._callback->mcoLogger = logger;
    if (logger != NULL) {
        self.instance->setConnectionLogger(self._callback);
    }
    else {
        self.instance->setConnectionLogger(NULL);
    }
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

C_SYNTHESIZE_FUNC_WITH_OBJ(CSMTPOperation, loginOperation)
C_SYNTHESIZE_FUNC_WITH_OBJ(CSMTPOperation, sendMessageOperation, CData)
C_SYNTHESIZE_FUNC_WITH_OBJ(CSMTPOperation, checkAccountOperation, CAddress)
C_SYNTHESIZE_FUNC_WITH_OBJ(CSMTPOperation, noopOperation)
C_SYNTHESIZE_FUNC_WITH_VOID(cancelAllOperations)

CSMTPOperation CSMTPSession_sendOperationWithDataAndFromAndRecipients(struct CSMTPSession self, CData messageData, CAddress from , CArray recipients) {
    return CSMTPOperation_new(self.instance->sendMessageOperation(from.instance, recipients.instance, messageData.instance));
}

CSMTPOperation CSMTPSession_sendOperationWithContentsOfFile(struct CSMTPSession self, MailCoreString path,  CAddress from,  CArray recipients) {
    return CSMTPOperation_new(self.instance->sendMessageOperation(from.instance, recipients.instance, path.instance));
}

CSMTPOperation CSMTPSession_checkAccountOperationWithFromAndTo(struct CSMTPSession self, CAddress from, CAddress to) {
    return CSMTPOperation_new(self.instance->checkAccountOperation(from.instance, to.instance));
}

CSMTPSession CSMTPSession_new(CConnectionLogger logger, CConnectionLoggerRelease releaseLoggerBlock) {
    CSMTPSession self;
    self.instance = new mailcore::SMTPAsyncSession();
    self._callback = new CSMTPCallbackBridge(logger, releaseLoggerBlock);
    return self;
}

void CSMTPSession_release(CSMTPSession self) {
    self._callback->releaseSwiftLogger();
    C_SAFE_RELEASE(self._callback);
    self.instance->setConnectionLogger(NULL);
    self.instance->release();
}

