#include <MailCore/MCAsync.h>

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
C_SYNTHESIZE_MAILCORE_OBJ(CIMAPNamespace, newCIMAPNamespace, mailcore::CIMAPNamespace, setDefaultNamespace, defaultNamespace)

CIMAPBaseOperation disconnectOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->disconnectOperation());
}

CIMAPBaseOperation noopOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->noopOperation());
}

CIMAPBaseOperation checkAccountOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->checkAccountOperation());
}

CIMAPBaseOperation capabilityOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->capabilityOperation());
}

CIMAPBaseOperation fetchAllFoldersOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(self.instance->fetchAllFoldersOperation());
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

CIMAPAppendMessageOperation appendMessageOperation(CIMAPAsyncSession self, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = self.instance->appendMessageOperation(new mailcore::String(folder), 
        new mailcore::String(messagePath), static_cast<mailcore::MessageFlag>(flags), array.instance);
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

CIMAPFetchContentOperation fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = self.instance->fetchMessageAttachmentByUIDOperation(new mailcore::String(folder),
        uid, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
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

CIMAPAsyncSession newCIMAPAsyncSession(){
    CIMAPAsyncSession session;
    session.instance = new mailcore::IMAPAsyncSession();
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
    session.disconnectOperation = &disconnectOperation;
    session.noopOperation = &noopOperation;
    session.checkAccountOperation = &checkAccountOperation;
    session.capabilityOperation = &capabilityOperation;
    session.fetchAllFoldersOperation = &fetchAllFoldersOperation;
    session.expungeOperation = &expungeOperation;
    session.createFolderOperation = &createFolderOperation;
    session.deleteFolderOperation = &deleteFolderOperation;
    session.storeFlagsByUIDOperation = &storeFlagsByUIDOperation;
    session.appendMessageOperation = &appendMessageOperation;
    session.fetchMessagesByNumberOperation = &fetchMessagesByNumberOperation;
    session.fetchMessagesByUIDOperation = &fetchMessagesByUIDOperation;
    session.syncMessagesByUIDOperation = &syncMessagesByUIDOperation;
    session.fetchMessageByUIDOperation = &fetchMessageByUIDOperation;
    session.fetchMessageAttachmentByUIDOperation = &fetchMessageAttachmentByUIDOperation;
    session.searchOperationWithExpression = &searchOperationWithExpression;
    session.searchOperation = &searchOperation;
    session.copyMessagesOperation = &copyMessagesOperation;
    session.folderInfoOperation = &folderInfoOperation;
    session.folderStatusOperation = &folderStatusOperation;
    return session;
}

void deleteCIMAPAsyncSession(CIMAPAsyncSession session){
    session.instance->release();
}


