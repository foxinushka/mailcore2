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

CIMAPBaseOperation CIMAPAsyncSession_subscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder) {
    return CIMAPBaseOperation_new(self.instance->subscribeFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation CIMAPAsyncSession_unsubscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder) {
    return CIMAPBaseOperation_new(self.instance->unsubscribeFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation CIMAPAsyncSession_renameFolderOperation(struct CIMAPAsyncSession self, const UChar *folder, const UChar *otherName) {
    return CIMAPBaseOperation_new(self.instance->renameFolderOperation(new mailcore::String(folder), new mailcore::String(otherName)));
}

CIMAPFetchFoldersOperation CIMAPAsyncSession_fetchSubscribedFoldersOperation(struct CIMAPAsyncSession self) {
    return CIMAPFetchFoldersOperation_new(self.instance->fetchSubscribedFoldersOperation());
}

CIMAPFetchNamespaceOperation CIMAPAsyncSession_fetchNamespace(struct CIMAPAsyncSession self) {
    return CIMAPFetchNamespaceOperation_new(self.instance->fetchNamespaceOperation());
}

CIMAPFetchContentToFileOperation CIMAPAsyncSession_fetchMessageAttachmentToFileOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, const UChar* partID, Encoding encoding, const UChar* filename, bool urgent){
    return CIMAPFetchContentToFileOperation_new(self.instance->fetchMessageAttachmentToFileByUIDOperation(new mailcore::String(folder), uid, new mailcore::String(partID), ((mailcore::Encoding) encoding), new mailcore::String(filename), urgent));
}

CIMAPCustomCommandOperation CIMAPAsyncSession_customCommandOperation(struct CIMAPAsyncSession self, const UChar *command) {
    return CIMAPCustomCommandOperation_new(self.instance->customCommand(new mailcore::String(command), false));
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

CIMAPBaseOperation CIMAPAsyncSession_expungeOperation(CIMAPAsyncSession self, const UChar *folder){
    return CIMAPBaseOperation_new(self.instance->expungeOperation(mailcore::String::stringWithCharacters(folder)));
}

CIMAPBaseOperation CIMAPAsyncSession_createFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return CIMAPBaseOperation_new(self.instance->createFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation CIMAPAsyncSession_deleteFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return CIMAPBaseOperation_new(self.instance->deleteFolderOperation(new mailcore::String(folder)));
}

CIMAPBaseOperation CIMAPAsyncSession_storeFlagsByUIDOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags){
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByUIDOperation(new mailcore::String(folder), 
        set.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeFlagsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeFlagsByNumberOperation(new mailcore::String(folder),
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), customFlags.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeLabelsByUIDOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByUIDOperation(new mailcore::String(folder),
        uids.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPBaseOperation CIMAPAsyncSession_storeLabelsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CArray labels) {
    mailcore::IMAPOperation *imapOperation = self.instance->storeLabelsByNumberOperation(new mailcore::String(folder),
        numbers.instance, static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), labels.instance);
    return CIMAPBaseOperation_new(imapOperation);
}

CIMAPAppendMessageOperation CIMAPAsyncSession_appendMessageOperation(CIMAPAsyncSession self, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(new mailcore::String(folder), 
        new mailcore::String(messagePath), static_cast<mailcore::MessageFlag>(flags), array.instance);
    return CIMAPAppendMessageOperation_new(imapOperation);
}

CIMAPAppendMessageOperation CIMAPAsyncSession_appendMessageOperationWithData(CIMAPAsyncSession self, const UChar *folder, CData messageData, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(new mailcore::String(folder),
                                                                                                new mailcore::Data(messageData.bytes, messageData.length),
                                                                                                static_cast<mailcore::MessageFlag>(flags), array.instance);
    return CIMAPAppendMessageOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_fetchMessagesByNumberOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByNumberOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), numbers.instance);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_fetchMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->fetchMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchMessagesOperation CIMAPAsyncSession_syncMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq){
    mailcore::IMAPFetchMessagesOperation *imapOperation = self.instance->syncMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), uids.instance, modSeq);
    return CIMAPFetchMessagesOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByUIDOperation(new mailcore::String(folder), uid, urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageByNumberOperation(new mailcore::String(folder), uid, urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByUIDOperation(new mailcore::String(folder),
        uid, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPFetchContentOperation CIMAPAsyncSession_fetchMessageAttachmentByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t number, const UChar *partID, Encoding encoding, bool urgent) {
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByNumberOperation(new mailcore::String(folder),
        number, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
    return CIMAPFetchContentOperation_new(imapOperation);
}

CIMAPSearchOperation CIMAPAsyncSession_searchOperationWithExpression(CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(new mailcore::String(folder), expression.instance);
    return CIMAPSearchOperation_new(imapOperation);
}

CIMAPSearchOperation CIMAPAsyncSession_searchOperation(CIMAPAsyncSession self, const UChar *folder, IMAPSearchKind kind, const UChar *str){
    mailcore::IMAPSearchOperation *imapOperation = self.instance->searchOperation(new mailcore::String(folder), 
        static_cast<mailcore::IMAPSearchKind>(kind), new mailcore::String(str));
    return CIMAPSearchOperation_new(imapOperation);
}

CIMAPCopyMessagesOperation CIMAPAsyncSession_copyMessagesOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder){
    mailcore::IMAPCopyMessagesOperation *imapOperation = self.instance->copyMessagesOperation(new mailcore::String(folder), 
        uids.instance, new mailcore::String(destFolder));
    return CIMAPCopyMessagesOperation_new(imapOperation);
}

CIMAPFolderInfoOperation CIMAPAsyncSession_folderInfoOperation(CIMAPAsyncSession self, const UChar *folder){
    return CIMAPFolderInfoOperation_new(self.instance->folderInfoOperation(new mailcore::String(folder)));
}

CIMAPFolderStatusOperation CIMAPAsyncSession_folderStatusOperation(CIMAPAsyncSession self, const UChar *folder){
    mailcore::IMAPFolderStatusOperation *imapOperation = self.instance->folderStatusOperation(new mailcore::String(folder));
    return CIMAPFolderStatusOperation_new(imapOperation);
}

CIMAPIdleOperation CIMAPAsyncSession_idleOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID){
    return CIMAPIdleOperation_new(self.instance->idleOperation(new mailcore::String(folder), lastKnownUID));
}

CIMAPMoveMessagesOperation CIMAPAsyncSession_moveMessagesOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, const UChar* destFolder) {
    return CIMAPMoveMessagesOperation_new(self.instance->moveMessagesOperation(new mailcore::String(folder), uids.instance, new mailcore::String(destFolder)));
}

CIMAPFetchParsedContentOperation CIMAPAsyncSession_fetchParsedMessageOperationByUIDOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, bool urgent) {
    return CIMAPFetchParsedContentOperation_new(self.instance->fetchParsedMessageByUIDOperation(new mailcore::String(folder), uid));
}

CIMAPFetchParsedContentOperation CIMAPAsyncSession_fetchParsedMessageOperationByNumberOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t number, bool urgent) {
    return CIMAPFetchParsedContentOperation_new(self.instance->fetchParsedMessageByNumberOperation(new mailcore::String(folder), number));
}
CIMAPMessageRenderingOperation CIMAPAsyncSession_htmlRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->htmlRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPIdentityOperation CIMAPAsyncSession_identityOperationWithClientIdentity(struct CIMAPAsyncSession self, CIMAPIdentity identity) {
    return CIMAPIdentityOperation_new(self.instance->identityOperation(identity.instance));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_htmlBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->htmlBodyRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_plainTextRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder) {
    return CIMAPMessageRenderingOperation_new(self.instance->plainTextRenderingOperation(message.instance, new mailcore::String(folder)));
}

CIMAPMessageRenderingOperation CIMAPAsyncSession_plainTextBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder, bool stripWhitespace) {
    return CIMAPMessageRenderingOperation_new(self.instance->plainTextBodyRenderingOperation(message.instance, new mailcore::String(folder), stripWhitespace));
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


