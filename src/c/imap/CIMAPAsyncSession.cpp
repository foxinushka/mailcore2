#include <MailCore/MCAsync.h>

extern "C" {
    #include "CIMAPAsyncSession.h"

    extern "C" void setHostname(CIMAPAsyncSession *session, const char *hostname) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->setHostname(new mailcore::String(hostname));
    }

    extern "C" void setPort(CIMAPAsyncSession *self, unsigned int port) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setPort(port);
    }
    extern "C" void setUsername(CIMAPAsyncSession *self, const char *username) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setUsername(new mailcore::String(username));
    }
    extern "C" void setPassword(CIMAPAsyncSession *self, const char *password) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setPassword(new mailcore::String(password));
    }
    extern "C" void setConnectionType(CIMAPAsyncSession *self, uint64_t connectionType) {
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setConnectionType(static_cast<mailcore::ConnectionType>(connectionType));
    }

    void setTimeout(CIMAPAsyncSession *self, time_t timeout){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setTimeout(timeout);
    }

    void setCheckCertificateEnabled(CIMAPAsyncSession *self, bool checkCertificateEnabled){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setCheckCertificateEnabled(checkCertificateEnabled);
    }

    void setOAuth2Token(CIMAPAsyncSession *self, const char *token){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setOAuth2Token(new mailcore::String(token));   
    }

    void setAuthType(CIMAPAsyncSession *self, uint64_t authType){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setAuthType(static_cast<mailcore::AuthType>(authType));   
    }

    void setMaximumConnections(CIMAPAsyncSession *self, unsigned int maxConnections){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setMaximumConnections(maxConnections);  
    }

    void setAllowsFolderConcurrentAccessEnabled(CIMAPAsyncSession *self, bool enabled){
        reinterpret_cast<mailcore::IMAPAsyncSession *>(self->self)->setAllowsFolderConcurrentAccessEnabled(enabled);  
    }

    // extern "C" void fetchMessagesByNumber(CIMAPAsyncSession *session, const char *folder, uint64_t request, CIndexSet uids, uint64_t *error) {
    //     mailcore::ErrorCode errorCode;
    //     reinterpret_cast<mailcore::IMAPAsyncSession *>(session->self)->
    //             fetchMessagesByNumber(new mailcore::String(folder), static_cast<mailcore::IMAPMessagesRequestKind >(request),
    //                                   reinterpret_cast<mailcore::IndexSet *>(uids.self), NULL, &errorCode);
    //     (*error) = errorCode;
    // }

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
