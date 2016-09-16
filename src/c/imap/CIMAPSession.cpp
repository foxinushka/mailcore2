#include <MailCore/MCCore.h>

extern "C" {
    #include "CIMAPSession.h"

    extern "C" void setHostname(CIMAPSession *self, const char *hostname) {
        reinterpret_cast<mailcore::IMAPSession *>(self->self)->setHostname(new mailcore::String(hostname));
    }

    extern "C" void setPort(CIMAPSession *self, unsigned int port) {
        reinterpret_cast<mailcore::IMAPSession *>(self->self)->setPort(port);
    }
    extern "C" void setUsername(CIMAPSession *self, const char *username) {
        reinterpret_cast<mailcore::IMAPSession *>(self->self)->setUsername(new mailcore::String(username));
    }
    extern "C" void setPassword(CIMAPSession *self, const char *password) {
        reinterpret_cast<mailcore::IMAPSession *>(self->self)->setPassword(new mailcore::String(password));
    }
    extern "C" void setConnectionType(CIMAPSession *self, uint64_t connectionType) {
        reinterpret_cast<mailcore::IMAPSession *>(self->self)->setConnectionType(static_cast<mailcore::ConnectionType>(connectionType));
    }

    extern "C" void fetchMessagesByNumber(CIMAPSession *session, const char *folder, uint64_t request, CIndexSet uids, uint64_t *error) {
        mailcore::ErrorCode errorCode;
        reinterpret_cast<mailcore::IMAPSession *>(session->self)->
                fetchMessagesByNumber(new mailcore::String(folder), static_cast<mailcore::IMAPMessagesRequestKind >(request),
                                      reinterpret_cast<mailcore::IndexSet *>(uids.self), NULL, &errorCode);
        (*error) = errorCode;
    }

    CIMAPSession newCIMAPSession(){
        CIMAPSession session;
        session.self = reinterpret_cast<void *>(new mailcore::IMAPSession());
        session.setHostname = &setHostname;
        session.setPort = &setPort;
        session.setUsername = &setUsername;
        session.setPassword = &setPassword;
        session.setConnectionType = &setConnectionType;
        session.fetchMessagesByNumber = &fetchMessagesByNumber;
        return session;
    }

    void deleteCIMAPSession(CIMAPSession session){
        delete reinterpret_cast<mailcore::IMAPSession*>(session.self);
    }
}
