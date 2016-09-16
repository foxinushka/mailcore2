#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include "stdint.h"
#include "CBase.h"
#include "CIndexSet.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPAsyncSession {
        ref self;
        void    (*setHostname)(struct CIMAPAsyncSession *self, const char *hostname);
        void    (*setPort)(struct CIMAPAsyncSession *self, unsigned int port);
        void    (*setUsername)(struct CIMAPAsyncSession *self, const char *username);
        void    (*setPassword)(struct CIMAPAsyncSession *self, const char *password);
        void    (*setConnectionType)(struct CIMAPAsyncSession *self, uint64_t connectionType);
        void    (*setTimeout)(CIMAPAsyncSession *self, time_t timeout);
        void    (*setCheckCertificateEnabled)(CIMAPAsyncSession *self, bool checkCertificateEnabled);
        void    (*setOAuth2Token)(CIMAPAsyncSession *self, const char *token);
        void    (*setAuthType)(CIMAPAsyncSession *self, uint64_t authType);
        void    (*setMaximumConnections)(CIMAPAsyncSession *self, unsigned int maxConnections);
        void    (*setAllowsFolderConcurrentAccessEnabled)(CIMAPAsyncSession *self, bool enabled);

        void    (*fetchMessagesByNumber)(struct CIMAPAsyncSession *self, const char *folder, uint64_t request, CIndexSet uids, uint64_t *errorCode);
    };
    typedef struct CIMAPAsyncSession CIMAPAsyncSession;

    CIMAPAsyncSession newCIMAPAsyncSession();
    void deleteCIMAPAsyncSession(CIMAPAsyncSession self);

#ifdef __cplusplus
}
#endif

#endif