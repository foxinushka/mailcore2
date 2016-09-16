#include <MailCore/MCAsync.h>
#include <MailCore/MCCore.h>

extern "C" {
    #include "CIMAPAsyncSession.h"

    extern "C" void setHostname(CIMAPAsyncSession *session, const char *hostname) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setHostname(new mailcore::String(hostname));
    }

    extern "C" void setPort(CIMAPAsyncSession *session, unsigned int port) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setPort(port);
    }
    extern "C" void setUsername(CIMAPAsyncSession *session, const char *username) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setUsername(new mailcore::String(username));
    }
    extern "C" void setPassword(CIMAPAsyncSession *session, const char *password) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setPassword(new mailcore::String(password));
    }
    extern "C" void setConnectionType(CIMAPAsyncSession *session, uint64_t connectionType) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setConnectionType(static_cast<mailcore::ConnectionType>(connectionType));
    }

    void setTimeout(CIMAPAsyncSession *session, time_t timeout){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setTimeout(timeout);
    }

    void setCheckCertificateEnabled(CIMAPAsyncSession *session, bool checkCertificateEnabled){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setCheckCertificateEnabled(checkCertificateEnabled);
    }

    void setOAuth2Token(CIMAPAsyncSession *session, const char *token){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setOAuth2Token(new mailcore::String(token));   
    }

    void setAuthType(CIMAPAsyncSession *session, uint64_t authType){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setAuthType(static_cast<mailcore::AuthType>(authType));   
    }

    void setMaximumConnections(CIMAPAsyncSession *session, unsigned int maxConnections){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setMaximumConnections(maxConnections);  
    }

    void setAllowsFolderConcurrentAccessEnabled(CIMAPAsyncSession *session, bool enabled){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setAllowsFolderConcurrentAccessEnabled(enabled);  
    }

    void setDefaultNamespace(CIMAPAsyncSession *session, CIMAPNamespace *nspace){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setDefaultNamespace(reinterpret_cast<mailcore::IMAPNamespace *>(nspace->self));  
    }

    // extern "C" void fetchMessagesByNumber(CIMAPAsyncSession *session, const char *folder, uint64_t request, CIndexSet uids, uint64_t *error) {
    //     mailcore::ErrorCode errorCode;
    //     reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->
    //             fetchMessagesByNumber(new mailcore::String(folder), static_cast<mailcore::IMAPMessagesRequestKind >(request),
    //                                   reinterpret_cast<mailcore::IndexSet *>(uids.self), NULL, &errorCode);
    //     (*error) = errorCode;
    // }

    CIMAPOperation disconnectOperation(CIMAPAsyncSession *session){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->disconnectOperation();
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation noopOperation(CIMAPAsyncSession *session){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->noopOperation();
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation checkAccountOperation(CIMAPAsyncSession *session){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->checkAccountOperation();
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation capabilityOperation(CIMAPAsyncSession *session){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->capabilityOperation();
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation fetchAllFoldersOperation(CIMAPAsyncSession *session){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->fetchAllFoldersOperation();
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation expungeOperation(CIMAPAsyncSession *session, const char *folder){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->expungeOperation(new mailcore::String(folder));
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation createFolderOperation(CIMAPAsyncSession *session, const char *folder){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->createFolderOperation(new mailcore::String(folder));
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation deleteFolderOperation(CIMAPAsyncSession *session, const char *folder){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->deleteFolderOperation(new mailcore::String(folder));
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPOperation storeFlagsByUIDOperation(CIMAPAsyncSession *session, const char *folder, CIndexSet *set, uint64_t kind, uint64_t flags, CArray *customFlags){
        mailcore::IMAPOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->storeFlagsByUIDOperation(new mailcore::String(folder), 
            reinterpret_cast<mailcore::IndexSet *>(set->self), static_cast<mailcore::IMAPStoreFlagsRequestKind>(kind), static_cast<mailcore::MessageFlag>(flags), reinterpret_cast<mailcore::Array *>(customFlags->self));
        return wrapIMAPOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPAppendMessageOperation appendMessageOperation(CIMAPAsyncSession *session, const char *folder, const char *messagePath, uint64_t flags, CArray *array){
        mailcore::IMAPAppendMessageOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->appendMessageOperation(new mailcore::String(folder), 
            new mailcore::String(messagePath), static_cast<mailcore::MessageFlag>(flags), reinterpret_cast<mailcore::Array *>(array->self));
        return wrapIMAPAppendMessageOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFetchMessagesOperation fetchMessagesByNumberOperation(CIMAPAsyncSession *session, const char *folder, uint64_t kind, CIndexSet *numbers){
        mailcore::IMAPFetchMessagesOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->fetchMessagesByNumberOperation(new mailcore::String(folder),
            static_cast<mailcore::IMAPMessagesRequestKind>(kind), reinterpret_cast<mailcore::IndexSet *>(numbers->self));
        return wrapCIMAPFetchMessagesOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFetchMessagesOperation fetchMessagesByUIDOperation(CIMAPAsyncSession *session, const char *folder, uint64_t kind, CIndexSet *uids){
        mailcore::IMAPFetchMessagesOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->fetchMessagesByUIDOperation(new mailcore::String(folder),
            static_cast<mailcore::IMAPMessagesRequestKind>(kind), reinterpret_cast<mailcore::IndexSet *>(uids->self));
        return wrapCIMAPFetchMessagesOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFetchMessagesOperation syncMessagesByUIDOperation(CIMAPAsyncSession *session, const char *folder, uint64_t kind, CIndexSet *uids, uint64_t modSeq){
        mailcore::IMAPFetchMessagesOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->syncMessagesByUIDOperation(new mailcore::String(folder),
            static_cast<mailcore::IMAPMessagesRequestKind>(kind), reinterpret_cast<mailcore::IndexSet *>(uids->self), modSeq);
        return wrapCIMAPFetchMessagesOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFetchContentOperation fetchMessageByUIDOperation(CIMAPAsyncSession *session, const char *folder, uint32_t uid, bool urgent){
        mailcore::IMAPFetchContentOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->fetchMessageByUIDOperation(new mailcore::String(folder), uid, urgent);
        return wrapCIMAPFetchContentOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFetchContentOperation fetchMessageAttachmentByUIDOperation(CIMAPAsyncSession *session, const char *folder, uint32_t uid, const char *partID, uint64_t encoding, bool urgent){
        mailcore::IMAPFetchContentOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->fetchMessageAttachmentByUIDOperation(new mailcore::String(folder),
            uid, new mailcore::String(partID), static_cast<mailcore::Encoding>(encoding), urgent);
        return wrapCIMAPFetchContentOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPSearchOperation searchOperationWithExpression(CIMAPAsyncSession *session, const char *folder, СIMAPSearchExpression *expression){
        mailcore::IMAPSearchOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->searchOperation(new mailcore::String(folder), 
            reinterpret_cast<mailcore::IMAPSearchExpression *>(expression->self));
        return wrapCIMAPSearchOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPSearchOperation searchOperation(CIMAPAsyncSession *session, const char *folder, uint64_t kind, const char *str){
        mailcore::IMAPSearchOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->searchOperation(new mailcore::String(folder), 
            static_cast<mailcore::IMAPSearchKind>(kind), new mailcore::String(str));
        return wrapCIMAPSearchOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPCopyMessagesOperation copyMessagesOperation(CIMAPAsyncSession *session, const char *folder, CIndexSet *uids,const char *destFolder){
        mailcore::IMAPCopyMessagesOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->copyMessagesOperation(new mailcore::String(folder), 
            reinterpret_cast<mailcore::IndexSet *>(uids->self), new mailcore::String(destFolder));
        return wrapCIMAPCopyMessagesOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFolderInfoOperation folderInfoOperation(CIMAPAsyncSession *session, const char *folder){
        mailcore::IMAPFolderInfoOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->folderInfoOperation(new mailcore::String(folder));
        return wrapCIMAPFolderInfoOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPFolderStatusOperation folderStatusOperation(CIMAPAsyncSession *session, const char *folder){
        mailcore::IMAPFolderStatusOperation *imapOperation = reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->folderStatusOperation(new mailcore::String(folder));
        return wrapCIMAPFolderStatusOperation(reinterpret_cast<void *>(imapOperation));
    }

    CIMAPAsyncSession newCIMAPAsyncSession(){
        CIMAPAsyncSession session;
        session.self = reinterpret_cast<void *>(new mailcore::IMAPAsyncSession());
        session.setHostname = &setHostname;
        session.setPort = &setPort;
        session.setUsername = &setUsername;
        session.setPassword = &setPassword;
        session.setConnectionType = &setConnectionType;
        session.setTimeout = &setTimeout;
        session.setCheckCertificateEnabled = &setCheckCertificateEnabled;
        return session;
    }

    void deleteCIMAPAsyncSession(CIMAPAsyncSession session){
        delete reinterpret_cast<mailcore::IMAPAsyncSession*>(session.self);
    }
}
