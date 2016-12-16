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
#include "СIMAPSearchOperation.h"

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
C_SYNTHESIZE_ENUM(AuthType, mailcore::AuthType, setAuthType, authType)
C_SYNTHESIZE_SCALAR(unsigned int, unsigned int, setMaximumConnections, maximumConnections)
C_SYNTHESIZE_BOOL(setAllowsFolderConcurrentAccessEnabled, allowsFolderConcurrentAccessEnabled)
C_SYNTHESIZE_MAILCORE_OBJ(CIMAPNamespace, newCIMAPNamespace, setDefaultNamespace, defaultNamespace)
C_SYNTHESIZE_MAILCORE_OBJ(CIMAPIdentity, newCIMAPIdentity, setClientIdentity, clientIdentity)
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

void setConnectionLogger(struct CIMAPAsyncSession self, ConnectionLogger logger) {
    self._callback->mLogger = logger;
    if (logger != NULL) {
        self.instance->setConnectionLogger(self._callback);
    }
    else {
        self.instance->setConnectionLogger(NULL);
    }
}

CIMAPIdentity serverIdentity(struct CIMAPAsyncSession self) {
    return newCIMAPIdentity(self.instance->serverIdentity());
}

bool isVoIPEnabled(struct CIMAPAsyncSession self) {
    return self.instance->isVoIPEnabled();
}

bool isIdleEnabled(struct CIMAPAsyncSession self) {
    return self.instance->isIdleEnabled();
}

bool isOperationQueueRunning(struct CIMAPAsyncSession self) {
    return self.instance->isOperationQueueRunning();
}

void cancelAllOperations(struct CIMAPAsyncSession self) {
    return self.instance->cancelAllOperations();
}

CIMAPBaseOperation subscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder) {
    return newCIMAPBaseOperation(self.instance->subscribeFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation unsubscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder) {
    return newCIMAPBaseOperation(self.instance->unsubscribeFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation renameFolderOperation(struct CIMAPAsyncSession self, const UChar *folder, const UChar *otherName) {
    return newCIMAPBaseOperation(self.instance->renameFolderOperation(new mailcore::String(folder), new mailcore::String(otherName)));
}

CIMAPFetchFoldersOperation fetchSubscribedFoldersOperation(struct CIMAPAsyncSession self) {
    return newCIMAPFetchFoldersOperation(self.instance->fetchSubscribedFoldersOperation());
}

CIMAPFetchNamespaceOperation fetchNamespace(struct CIMAPAsyncSession self) {
    return newCIMAPFetchNamespaceOperation(self.instance->fetchNamespaceOperation());
}

CIMAPFetchContentToFileOperation fetchMessageAttachmentToFileOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, const UChar* partID, Encoding encoding, const UChar* filename, bool urgent){
    return newCIMAPFetchContentToFileOperation(self.instance->fetchMessageAttachmentToFileByUIDOperation(new mailcore::String(folder), uid, new mailcore::String(partID), ((mailcore::Encoding) encoding), new mailcore::String(filename), urgent));
}

CIMAPCustomCommandOperation customCommandOperation(struct CIMAPAsyncSession self, const UChar *command) {
    return newCIMAPCustomCommandOperation(self.instance->customCommand(new mailcore::String(command), false));
}

CIMAPBaseOperation connectOperation (struct CIMAPAsyncSession self) {
    return newCIMAPBaseOperation(self.instance->connectOperation());
}

CIMAPBaseOperation disconnectOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->disconnectOperation());
}

CIMAPBaseOperation noopOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->noopOperation());
}

CIMAPCheckAccountOperation checkAccountOperation(CIMAPAsyncSession self){
    return newCIMAPCheckAccountOperation(self.instance->checkAccountOperation());
}

CIMAPCapabilityOperation capabilityOperation(CIMAPAsyncSession self){
    return newCIMAPCapabilityOperation(self.instance->capabilityOperation());
}

CIMAPFetchFoldersOperation fetchAllFoldersOperation(CIMAPAsyncSession self){
    return newCIMAPFetchFoldersOperation(self.instance->fetchAllFoldersOperation());
}

CIMAPBaseOperation expungeOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(self.instance->expungeOperation(mailcore::String::stringWithCharacters(folder)));
}

CIMAPBaseOperation createFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(self.instance->createFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation deleteFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(self.instance->deleteFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation storeFlagsByUIDOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags){
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByUIDOperation(new mailcore::String(folder), 
        set.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return newCIMAPBaseOperation(imapOperation);
}

CIMAPBaseOperation storeFlagsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByNumberOperation(new mailcore::String(folder),
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return newCIMAPBaseOperation(imapOperation);
}

CIMAPBaseOperation storeLabelsByUIDOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByUIDOperation(new mailcore::String(folder),
        uids.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return newCIMAPBaseOperation(imapOperation);
}

CIMAPBaseOperation storeLabelsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByNumberOperation(new mailcore::String(folder),
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return newCIMAPBaseOperation(imapOperation);
}

CIMAPAppendMessageOperation appendMessageOperation(CIMAPAsyncSession self, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(new mailcore::String(folder), 
        new mailcore::String(messagePath), static_cast<mailcore::MessageFlag>(flags), array.instance);
    return newIMAPAppendMessageOperation(imapOperation);
}

CIMAPAppendMessageOperation appendMessageOperationWithData(CIMAPAsyncSession self, const UChar *folder, CData messageData, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(new mailcore::String(folder),
                                                                                                new mailcore::Data(messageData.bytes, messageData.length),
                                                                                                static_cast<mailcore::MessageFlag>(flags), array.instance);
    return newIMAPAppendMessageOperation(imapOperation);
}

CIMAPFetchMessagesOperation fetchMessagesByNumberOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByNumberOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), numbers.instance);
    return newCIMAPFetchMessagesOperation(imapOperation);
}

CIMAPFetchMessagesOperation fetchMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance);
    return newCIMAPFetchMessagesOperation(imapOperation);
}

CIMAPFetchMessagesOperation syncMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->syncMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance, modSeq);
    return newCIMAPFetchMessagesOperation(imapOperation);
}

CIMAPFetchContentOperation fetchMessageByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByUIDOperation(new mailcore::String(folder), uid, urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}

CIMAPFetchContentOperation fetchMessageByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByNumberOperation(new mailcore::String(folder), uid, urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}

CIMAPFetchContentOperation fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByUIDOperation(new mailcore::String(folder),
        uid, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}

CIMAPFetchContentOperation fetchMessageAttachmentByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t number, const UChar *partID, Encoding encoding, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByNumberOperation(new mailcore::String(folder),
        number, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}

CIMAPSearchOperation searchOperationWithExpression(CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(new mailcore::String(folder), expression.instance);
    return newCIMAPSearchOperation(imapOperation);
}

CIMAPSearchOperation searchOperation(CIMAPAsyncSession self, const UChar *folder, IMAPSearchKind kind, const UChar *str){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(new mailcore::String(folder), 
        static_cast<mailcore::IMAPSearchKind>(kind), new mailcore::String(str));
    return newCIMAPSearchOperation(imapOperation);
}

CIMAPCopyMessagesOperation copyMessagesOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder){
    mailcore::IMAPCopyMessagesOperation *imapOperation = self.instance->copyMessagesOperation(new mailcore::String(folder), 
        uids.instance, new mailcore::String(destFolder));
    return newCIMAPCopyMessagesOperation(imapOperation);
}

CIMAPFolderInfoOperation folderInfoOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPFolderInfoOperation(self.instance->folderInfoOperation(new mailcore::String(folder)));
}

CIMAPFolderStatusOperation folderStatusOperation(CIMAPAsyncSession self, const UChar *folder){
    mailcore::IMAPFolderStatusOperation *imapOperation = self.instance->folderStatusOperation(new mailcore::String(folder));
    return newCIMAPFolderStatusOperation(imapOperation);
}

CIMAPIdleOperation idleOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID){
    return newCIMAPIdleOperation(self.instance->idleOperation(new mailcore::String(folder), lastKnownUID));
}

CIMAPMoveMessagesOperation moveMessagesOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, const UChar* destFolder) {
    return newCIMAPMoveMessagesOperation(self.instance->moveMessagesOperation(new mailcore::String(folder), uids.instance, new mailcore::String(destFolder)));
}

CIMAPFetchParsedContentOperation fetchParsedMessageOperationByUIDOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, bool urgent) {
    return newCIMAPFetchParsedContentOperation(self.instance->fetchParsedMessageByUIDOperation(new mailcore::String(folder), uid));
}

CIMAPFetchParsedContentOperation fetchParsedMessageOperationByNumberOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t number, bool urgent) {
    return newCIMAPFetchParsedContentOperation(self.instance->fetchParsedMessageByNumberOperation(new mailcore::String(folder), number));
}
CIMAPMessageRenderingOperation htmlRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return newCIMAPMessageRenderingOperation(self.instance->htmlRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPIdentityOperation identityOperationWithClientIdentity(struct CIMAPAsyncSession self, CIMAPIdentity identity) {
    return newCIMAPIdentityOperation(self.instance->identityOperation(identity.instance));
}

CIMAPMessageRenderingOperation htmlBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return newCIMAPMessageRenderingOperation(self.instance->htmlBodyRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPMessageRenderingOperation plainTextRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return newCIMAPMessageRenderingOperation(self.instance->plainTextRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPMessageRenderingOperation plainTextBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder, bool stripWhitespace) {
    return newCIMAPMessageRenderingOperation(self.instance->plainTextBodyRenderingOperation(message.instance, new mailcore::String(folder), stripWhitespace));
}

CIMAPQuotaOperation quotaOperation(struct CIMAPAsyncSession self) {
    return newCIMAPQuotaOperation(self.instance->quotaOperation());
}

CIMAPAsyncSession newCIMAPAsyncSession(){
    CIMAPAsyncSession session;
    session.instance = new mailcore::IMAPAsyncSession();
    session._callback = new CIMAPCallbackBridge();
    session.instance->setOperationQueueCallback(session._callback);
    
    session.hostname = &hostname;
    session.port = &port;
    session.username = &username;
    session.password = &password;
    session.connectionType = &connectionType;
    session.timeout = &timeout;
    session.isCheckCertificateEnabled = &isCheckCertificateEnabled;
    session.OAuth2Token = &OAuth2Token;
    session.authType = &authType;
    session.maximumConnections = &maximumConnections;
    session.allowsFolderConcurrentAccessEnabled = &allowsFolderConcurrentAccessEnabled;
    session.defaultNamespace = &defaultNamespace;
    session.clientIdentity = &clientIdentity;
    session.serverIdentity = &serverIdentity;
    session.isVoIPEnabled = &isVoIPEnabled;
    session.isIdleEnabled = &isIdleEnabled;
    session.isOperationQueueRunning = &isOperationQueueRunning;
    session.setHostname = &setHostname;
    session.setPort = &setPort;
    session.setUsername = &setUsername;
    session.setPassword = &setPassword;
    session.setConnectionType = &setConnectionType;
    session.setTimeout = &setTimeout;
    session.setCheckCertificateEnabled = &setCheckCertificateEnabled;
    session.setOAuth2Token = &setOAuth2Token;
    session.setAuthType = &setAuthType;
    session.setMaximumConnections = &setMaximumConnections;
    session.setAllowsFolderConcurrentAccessEnabled = &setAllowsFolderConcurrentAccessEnabled;
    session.setDefaultNamespace = &setDefaultNamespace;
    session.setClientIdentity = &setClientIdentity;
    session.dispatchQueue = &dispatchQueue;
    session.setDispatchQueue = &setDispatchQueue;
    session.setConnectionLogger = &setConnectionLogger;
    session.cancelAllOperations = &cancelAllOperations;
    session.connectOperation = &connectOperation;
    session.disconnectOperation = &disconnectOperation;
    session.noopOperation = &noopOperation;
    session.expungeOperation = &expungeOperation;
    session.createFolderOperation = &createFolderOperation;
    session.deleteFolderOperation = &deleteFolderOperation;
    session.storeFlagsByUIDOperation = &storeFlagsByUIDOperation;
    session.storeFlagsByNumberOperation = &storeFlagsByNumberOperation;
    session.storeLabelsByUIDOperation = &storeLabelsByUIDOperation;
    session.storeLabelsByNumberOperation = &storeLabelsByNumberOperation;
    session.renameFolderOperation = &renameFolderOperation;
    session.subscribeFolderOperation = &subscribeFolderOperation;
    session.unsubscribeFolderOperation = &unsubscribeFolderOperation;
    session.fetchSubscribedFoldersOperation = &fetchSubscribedFoldersOperation;
    session.fetchMessageAttachmentToFileOperation = &fetchMessageAttachmentToFileOperation;
    session.fetchNamespace = &fetchNamespace;
    session.customCommandOperation = &customCommandOperation;
    session.checkAccountOperation = &checkAccountOperation;
    session.capabilityOperation = &capabilityOperation;
    session.fetchAllFoldersOperation = &fetchAllFoldersOperation;
    session.appendMessageOperation = &appendMessageOperation;
    session.appendMessageOperationWithData = &appendMessageOperationWithData;
    session.fetchMessagesByNumberOperation = &fetchMessagesByNumberOperation;
    session.fetchMessagesByUIDOperation = &fetchMessagesByUIDOperation;
    session.syncMessagesByUIDOperation = &syncMessagesByUIDOperation;
    session.fetchMessageByUIDOperation = &fetchMessageByUIDOperation;
    session.fetchMessageByNumberOperation = &fetchMessageByNumberOperation;
    session.fetchMessageAttachmentByUIDOperation = &fetchMessageAttachmentByUIDOperation;
    session.fetchMessageAttachmentByNumberOperation = &fetchMessageAttachmentByNumberOperation;
    session.searchOperationWithExpression = &searchOperationWithExpression;
    session.searchOperation = &searchOperation;
    session.copyMessagesOperation = &copyMessagesOperation;
    session.folderInfoOperation = &folderInfoOperation;
    session.folderStatusOperation = &folderStatusOperation;
    session.idleOperation = &idleOperation;
    session.moveMessagesOperation = &moveMessagesOperation;
    session.fetchParsedMessageOperationByUIDOperation = &fetchParsedMessageOperationByUIDOperation;
    session.fetchParsedMessageOperationByNumberOperation = &fetchParsedMessageOperationByNumberOperation;
    session.htmlRenderingOperation = &htmlRenderingOperation;
    session.htmlBodyRenderingOperation = &htmlBodyRenderingOperation;
    session.plainTextRenderingOperation = &plainTextRenderingOperation;
    session.plainTextBodyRenderingOperation = &plainTextBodyRenderingOperation;
    session.quotaOperation = &quotaOperation;
    session.identityOperationWithClientIdentity = &identityOperationWithClientIdentity;
    return session;
}

void deleteCIMAPAsyncSession(CIMAPAsyncSession session){
    session.instance->setConnectionLogger(NULL);
    session.instance->setOperationQueueCallback(NULL);
    C_SAFE_RELEASE(session._callback);
    session.instance->release();
}


