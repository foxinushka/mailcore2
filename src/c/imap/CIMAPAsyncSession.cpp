#include <MailCore/MCAsync.h>
#ifdef __ANDROID__
#include <MailCore/MCOperationQueueCallback.h>
#else
#include "MCOperationQueueCallback.h"
#endif

#include "CIMAPAsyncSession.h"
#include "CIMAPAppendMessageOperation.h"
#include "CIMAPCopyMessagesOperation.h"
#include "CIMAPFetchContentOperation.h"
#include "CIMAPFolderInfoOperation.h"
#include "CIMAPFolderStatusOperation.h"
#include "CIMAPSearchOperation.h"

#include "CBase+Private.h"

#define nativeType mailcore::IMAPAsyncSession
#define structName CIMAPAsyncSession

C_SYNTHESIZE_STRING(setHostname, hostname)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setPort, port)
C_SYNTHESIZE_STRING(setUsername, username)
C_SYNTHESIZE_STRING(setPassword, password)
C_SYNTHESIZE_ENUM(ConnectionType, mailcore::ConnectionType, setConnectionType, connectionType)
C_SYNTHESIZE_SCALAR(time_t, time_t, setTimeout, timeout)
C_SYNTHESIZE_BOOL(setCheckCertificateEnabled, isCheckCertificateEnabled)
C_SYNTHESIZE_STRING(setOAuth2Token, OAuth2Token)
C_SYNTHESIZE_ENUM(CAuthType, mailcore::AuthType, setAuthType, authType)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setMaximumConnections, maximumConnections)
C_SYNTHESIZE_BOOL(setAllowsFolderConcurrentAccessEnabled, allowsFolderConcurrentAccessEnabled)
C_SYNTHESIZE_MAILCORE_OBJ(CIMAPNamespace, CIMAPNamespace_new, setDefaultNamespace, defaultNamespace)
C_SYNTHESIZE_MAILCORE_OBJ(CIMAPIdentity, CIMAPIdentity_new, setClientIdentity, clientIdentity)
C_SYNTHESIZE_SCALAR(dispatch_queue_t, dispatch_queue_t, setDispatchQueue, dispatchQueue)

typedef ConnectionLogger CConnectionLogger;

class CIMAPCallbackBridge : public mailcore::Object, public mailcore::ConnectionLogger, public mailcore::OperationQueueCallback {
public:
    CIMAPCallbackBridge()
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
    
    CConnectionLogger mLogger = NULL;
    OperationQueueRunningChangeBlock mQueueRunningChangeBlock = NULL;
};

void CIMAPAsyncSession_setConnectionLogger(struct CIMAPAsyncSession self, ConnectionLogger logger) {
    self._callback->mLogger = logger;
    if (logger != NULL) {
        self.instance->setConnectionLogger(self._callback);
    }
    else {
        self.instance->setConnectionLogger(NULL);
    }
}

CIMAPIdentity CIMAPAsyncSession_serverIdentity(struct CIMAPAsyncSession self) {
    return CIMAPIdentity_new(self.instance->serverIdentity());
}

bool CIMAPAsyncSession_isVoIPEnabled(struct CIMAPAsyncSession self) {
    return self.instance->isVoIPEnabled();
}

bool CIMAPAsyncSession_isIdleEnabled(struct CIMAPAsyncSession self) {
    return self.instance->isIdleEnabled();
}

bool CIMAPAsyncSession_isOperationQueueRunning(struct CIMAPAsyncSession self) {
    return self.instance->isOperationQueueRunning();
}

void CIMAPAsyncSession_cancelAllOperations(struct CIMAPAsyncSession self) {
    return self.instance->cancelAllOperations();
}

CIMAPBaseOperation CIMAPAsyncSession_subscribeFolderOperation(struct CIMAPAsyncSession self, MailCoreString folder) {
    return CIMAPBaseOperation_new(self.instance->subscribeFolderOperation(folder.instance));
}

CIMAPBaseOperation CIMAPAsyncSession_unsubscribeFolderOperation(struct CIMAPAsyncSession self, MailCoreString folder) {
    return CIMAPBaseOperation_new(self.instance->unsubscribeFolderOperation(folder.instance));
}

CIMAPBaseOperation CIMAPAsyncSession_renameFolderOperation(struct CIMAPAsyncSession self, MailCoreString folder, MailCoreString otherName) {
    return CIMAPBaseOperation_new(self.instance->renameFolderOperation(folder.instance, otherName.instance));
}

CIMAPFetchFoldersOperation CIMAPAsyncSession_fetchSubscribedFoldersOperation(struct CIMAPAsyncSession self) {
    return CIMAPFetchFoldersOperation_new(self.instance->fetchSubscribedFoldersOperation());
}

CIMAPFetchNamespaceOperation CIMAPAsyncSession_fetchNamespace(struct CIMAPAsyncSession self) {
    return CIMAPFetchNamespaceOperation_new(self.instance->fetchNamespaceOperation());
}

CIMAPFetchContentToFileOperation CIMAPAsyncSession_fetchMessageAttachmentToFileOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t uid, MailCoreString partID, Encoding encoding, MailCoreString filename, bool urgent){
    return CIMAPFetchContentToFileOperation_new(self.instance->fetchMessageAttachmentToFileByUIDOperation(folder.instance, uid, partID.instance, ((mailcore::Encoding) encoding), filename.instance, urgent));
}

CIMAPCustomCommandOperation CIMAPAsyncSession_customCommandOperation(struct CIMAPAsyncSession self, MailCoreString command) {
    return CIMAPCustomCommandOperation_new(self.instance->customCommand(command.instance, false));
}

CIMAPBaseOperation CIMAPAsyncSession_connectOperation (struct CIMAPAsyncSession self) {
    return CIMAPBaseOperation_new(self.instance->connectOperation());
}

CIMAPBaseOperation CIMAPAsyncSession_disconnectOperation(CIMAPAsyncSession self){
    return CIMAPBaseOperation_new(self.instance->disconnectOperation());
}

CIMAPBaseOperation CIMAPAsyncSession_noopOperation(CIMAPAsyncSession self){
    return CIMAPBaseOperation_new(self.instance->noopOperation());
}

CIMAPCheckAccountOperation CIMAPAsyncSession_checkAccountOperation(CIMAPAsyncSession self){
    return CIMAPCheckAccountOperation_new(self.instance->checkAccountOperation());
}

CIMAPCapabilityOperation CIMAPAsyncSession_capabilityOperation(CIMAPAsyncSession self){
    return CIMAPCapabilityOperation_new(self.instance->capabilityOperation());
}

CIMAPFetchFoldersOperation CIMAPAsyncSession_fetchAllFoldersOperation(CIMAPAsyncSession self){
    return CIMAPFetchFoldersOperation_new(self.instance->fetchAllFoldersOperation());
}

CIMAPBaseOperation CIMAPAsyncSession_expungeOperation(CIMAPAsyncSession self, MailCoreString folder){
    return CIMAPBaseOperation_new(self.instance->expungeOperation(folder.instance));
}

CIMAPBaseOperation CIMAPAsyncSession_createFolderOperation(CIMAPAsyncSession self, MailCoreString folder){
    return CIMAPBaseOperation_new(self.instance->createFolderOperation(folder.instance));
}

CIMAPBaseOperation CIMAPAsyncSession_deleteFolderOperation(CIMAPAsyncSession self, MailCoreString folder){
    return CIMAPBaseOperation_new(self.instance->deleteFolderOperation(folder.instance));
}

CIMAPBaseOperation CIMAPAsyncSession_storeFlagsByUIDOperation(CIMAPAsyncSession self, MailCoreString folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, CMessageFlag flags, CArray customFlags){
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByUIDOperation(folder.instance, 
        set.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeFlagsByNumberOperation(struct CIMAPAsyncSession self, MailCoreString folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CMessageFlag flags, CArray customFlags) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByNumberOperation(folder.instance,
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeLabelsByUIDOperation(struct CIMAPAsyncSession self, MailCoreString folder, CIndexSet uids, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByUIDOperation(folder.instance,
        uids.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeLabelsByNumberOperation(struct CIMAPAsyncSession self, MailCoreString folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByNumberOperation(folder.instance,
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPAppendMessageOperation CIMAPAsyncSession_appendMessageOperation(CIMAPAsyncSession self, MailCoreString folder, MailCoreString messagePath, CMessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(folder.instance, messagePath.instance, static_cast<mailcore::MessageFlag>(flags), array.instance);
    return CIMAPAppendMessageOperation_new(imapOperation);
}

CIMAPAppendMessageOperation CIMAPAsyncSession_appendMessageOperationWithData(CIMAPAsyncSession self, MailCoreString folder, CData messageData, CMessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(folder.instance,
                                                                                                messageData.instance,
                                                                                                static_cast<mailcore::MessageFlag>(flags), array.instance);
    return CIMAPAppendMessageOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_fetchMessagesByNumberOperation(CIMAPAsyncSession self, MailCoreString folder, CIMAPMessagesRequestKind kind, CIndexSet numbers){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByNumberOperation(folder.instance,
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), numbers.instance);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_fetchMessagesByUIDOperation(CIMAPAsyncSession self, MailCoreString folder, CIMAPMessagesRequestKind kind, CIndexSet uids){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByUIDOperation(folder.instance,
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_syncMessagesByUIDOperation(CIMAPAsyncSession self, MailCoreString folder, CIMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->syncMessagesByUIDOperation(folder.instance,
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance, modSeq);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageByUIDOperation(CIMAPAsyncSession self, MailCoreString folder, uint32_t uid, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByUIDOperation(folder.instance, uid, urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageByNumberOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t uid, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByNumberOperation(folder.instance, uid, urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession self, MailCoreString folder, uint32_t uid, MailCoreString partID, Encoding encoding, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByUIDOperation(folder.instance,
        uid, partID.instance, static_cast<mailcore::Encoding>(encoding), urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageAttachmentByNumberOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t number, MailCoreString partID, Encoding encoding, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByNumberOperation(folder.instance,
        number, partID.instance, static_cast<mailcore::Encoding>(encoding), urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPSearchOperation CIMAPAsyncSession_searchOperationWithExpression(CIMAPAsyncSession self, MailCoreString folder, CIMAPSearchExpression expression){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(folder.instance, expression.instance);
    return CIMAPSearchOperation_new(imapOperation);
}

CIMAPSearchOperation CIMAPAsyncSession_searchOperation(CIMAPAsyncSession self, MailCoreString folder, IMAPSearchKind kind, MailCoreString str){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(folder.instance, 
        static_cast<mailcore::IMAPSearchKind>(kind), str.instance);
    return CIMAPSearchOperation_new(imapOperation);
}

CIMAPCopyMessagesOperation CIMAPAsyncSession_copyMessagesOperation(CIMAPAsyncSession self, MailCoreString folder, CIndexSet uids,MailCoreString destFolder){
    mailcore::IMAPCopyMessagesOperation *imapOperation = self.instance->copyMessagesOperation(folder.instance, 
        uids.instance, destFolder.instance);
    return CIMAPCopyMessagesOperation_new(imapOperation);
}

CIMAPFolderInfoOperation CIMAPAsyncSession_folderInfoOperation(CIMAPAsyncSession self, MailCoreString folder){
    return CIMAPFolderInfoOperation_new(self.instance->folderInfoOperation(folder.instance));
}

CIMAPFolderStatusOperation CIMAPAsyncSession_folderStatusOperation(CIMAPAsyncSession self, MailCoreString folder){
    mailcore::IMAPFolderStatusOperation *imapOperation = self.instance->folderStatusOperation(folder.instance);
    return CIMAPFolderStatusOperation_new(imapOperation);
}

CIMAPIdleOperation CIMAPAsyncSession_idleOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t lastKnownUID){
    return CIMAPIdleOperation_new(self.instance->idleOperation(folder.instance, lastKnownUID));
}

CIMAPMoveMessagesOperation CIMAPAsyncSession_moveMessagesOperation(struct CIMAPAsyncSession self, MailCoreString folder, CIndexSet uids, MailCoreString destFolder) {
    return CIMAPMoveMessagesOperation_new(self.instance->moveMessagesOperation(folder.instance, uids.instance, destFolder.instance));
}

CIMAPFetchParsedContentOperation CIMAPAsyncSession_fetchParsedMessageOperationByUIDOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t uid, bool urgent) {
    return CIMAPFetchParsedContentOperation_new(self.instance->fetchParsedMessageByUIDOperation(folder.instance, uid));
}

CIMAPFetchParsedContentOperation CIMAPAsyncSession_fetchParsedMessageOperationByNumberOperation(struct CIMAPAsyncSession self, MailCoreString folder, uint32_t number, bool urgent) {
    return CIMAPFetchParsedContentOperation_new(self.instance->fetchParsedMessageByNumberOperation(folder.instance, number));
}
CIMAPMessageRenderingOperation CIMAPAsyncSession_htmlRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, MailCoreString folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->htmlRenderingOperation(message.instance, folder.instance));
}

CIMAPIdentityOperation CIMAPAsyncSession_identityOperationWithClientIdentity(struct CIMAPAsyncSession self, CIMAPIdentity identity) {
    return CIMAPIdentityOperation_new(self.instance->identityOperation(identity.instance));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_htmlBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, MailCoreString folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->htmlBodyRenderingOperation(message.instance, folder.instance));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_plainTextRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, MailCoreString folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->plainTextRenderingOperation(message.instance, folder.instance));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_plainTextBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, MailCoreString folder, bool stripWhitespace) {
    return CIMAPMessageRenderingOperation_new(self.instance->plainTextBodyRenderingOperation(message.instance, folder.instance, stripWhitespace));
}

CIMAPQuotaOperation CIMAPAsyncSession_quotaOperation(struct CIMAPAsyncSession self) {
    return CIMAPQuotaOperation_new(self.instance->quotaOperation());
}

CIMAPAsyncSession CIMAPAsyncSession_new(){
    CIMAPAsyncSession session;
    session.instance = new mailcore::IMAPAsyncSession();
    session._callback = new CIMAPCallbackBridge();
    session.instance->setOperationQueueCallback(session._callback);
    return session;
}

void CIMAPAsyncSession_release(CIMAPAsyncSession session){
    session.instance->setConnectionLogger(NULL);
    session.instance->setOperationQueueCallback(NULL);
    C_SAFE_RELEASE(session._callback);
    session.instance->release();
}


