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

mailcore::IMAPAsyncSession* cast(CIMAPAsyncSession self) {
    return reinterpret_cast<mailcore::IMAPAsyncSession*>(self.nativeInstance);
}

CIMAPBaseOperation disconnectOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(cast(self)->disconnectOperation());
}
CIMAPBaseOperation noopOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(cast(self)->noopOperation());
}
CIMAPBaseOperation checkAccountOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(cast(self)->checkAccountOperation());
}
CIMAPBaseOperation capabilityOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(cast(self)->capabilityOperation());
}
CIMAPBaseOperation fetchAllFoldersOperation(CIMAPAsyncSession self){
    return newCIMAPBaseOperation(cast(self)->fetchAllFoldersOperation());
}
CIMAPBaseOperation expungeOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(cast(self)->expungeOperation(mailcore::String::stringWithCharacters(folder)));
}
CIMAPBaseOperation createFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(cast(self)->createFolderOperation(new mailcore::String(folder)));
}
CIMAPBaseOperation deleteFolderOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPBaseOperation(cast(self)->deleteFolderOperation(new mailcore::String(folder)));
}
CIMAPBaseOperation storeFlagsByUIDOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags){
    mailcore::IMAPOperation *imapOperation = cast(self)->storeFlagsByUIDOperation(new mailcore::String(folder), 
        cast(set), static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), cast(customFlags));
    return newCIMAPBaseOperation(imapOperation);
}
CIMAPAppendMessageOperation appendMessageOperation(CIMAPAsyncSession self, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array){
    mailcore::IMAPAppendMessageOperation *imapOperation = cast(self)->appendMessageOperation(new mailcore::String(folder), 
        new mailcore::String(messagePath), static_cast<mailcore::MessageFlag>(flags), cast(array));
    return newIMAPAppendMessageOperation(imapOperation);
}
CIMAPFetchMessagesOperation fetchMessagesByNumberOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers){
    mailcore::IMAPFetchMessagesOperation *imapOperation = cast(self)->fetchMessagesByNumberOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), cast(numbers));
    return newCIMAPFetchMessagesOperation(imapOperation);
}
CIMAPFetchMessagesOperation fetchMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids){
    mailcore::IMAPFetchMessagesOperation *imapOperation = cast(self)->fetchMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), cast(uids));
    return newCIMAPFetchMessagesOperation(imapOperation);
}
CIMAPFetchMessagesOperation syncMessagesByUIDOperation(CIMAPAsyncSession self, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq){
    mailcore::IMAPFetchMessagesOperation *imapOperation = cast(self)->syncMessagesByUIDOperation(new mailcore::String(folder),
        static_cast<mailcore::IMAPMessagesRequestKind>(kind), cast(uids), modSeq);
    return newCIMAPFetchMessagesOperation(imapOperation);
}
CIMAPFetchContentOperation fetchMessageByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = cast(self)->fetchMessageByUIDOperation(new mailcore::String(folder), uid, urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}
CIMAPFetchContentOperation fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession self, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent){
    mailcore::IMAPFetchContentOperation *imapOperation = cast(self)->fetchMessageAttachmentByUIDOperation(new mailcore::String(folder),
        uid, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
    return newCIMAPFetchContentOperation(imapOperation);
}
CIMAPSearchOperation searchOperationWithExpression(CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression){
    mailcore::IMAPSearchOperation *imapOperation = cast(self)->searchOperation(new mailcore::String(folder), 
        reinterpret_cast<mailcore::IMAPSearchExpression *>(expression.nativeInstance));
    return newCIMAPSearchOperation(imapOperation);
}
CIMAPSearchOperation searchOperation(CIMAPAsyncSession self, const UChar *folder, IMAPSearchKind kind, const UChar *str){
    mailcore::IMAPSearchOperation *imapOperation = cast(self)->searchOperation(new mailcore::String(folder), 
        static_cast<mailcore::IMAPSearchKind>(kind), new mailcore::String(str));
    return newCIMAPSearchOperation(imapOperation);
}
CIMAPCopyMessagesOperation copyMessagesOperation(CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder){
    mailcore::IMAPCopyMessagesOperation *imapOperation = cast(self)->copyMessagesOperation(new mailcore::String(folder), 
        cast(uids), new mailcore::String(destFolder));
    return newCIMAPCopyMessagesOperation(imapOperation);
}
CIMAPFolderInfoOperation folderInfoOperation(CIMAPAsyncSession self, const UChar *folder){
    return newCIMAPFolderInfoOperation(cast(self)->folderInfoOperation(new mailcore::String(folder)));
}
CIMAPFolderStatusOperation folderStatusOperation(CIMAPAsyncSession self, const UChar *folder){
    mailcore::IMAPFolderStatusOperation *imapOperation = cast(self)->folderStatusOperation(new mailcore::String(folder));
    return newCIMAPFolderStatusOperation(imapOperation);
}

  CIMAPIdleOperation idleOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID){
      return newCIMAPIdleOperation(cast(self)->idleOperation(new mailcore::String(folder), lastKnownUID));
  }
CIMAPAsyncSession newCIMAPAsyncSession(){
    CIMAPAsyncSession session;
    session.nativeInstance = reinterpret_cast<void *>(new mailcore::IMAPAsyncSession());
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
    //delete reinterpret_cast<mailcore::IMAPAsyncSession*>(session.nativeInstance);
}


