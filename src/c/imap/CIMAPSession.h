#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include "stdint.h"
#include "CBase.h"
#include "CIndexSet.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CIMAPSession {
        ref self;
        void    (*setHostname)(struct CIMAPSession *self, const char *hostname);
        void    (*setPort)(struct CIMAPSession *self, unsigned int port);
        void    (*setUsername)(struct CIMAPSession *self, const char *username);
        void    (*setPassword)(struct CIMAPSession *self, const char *password);
        void    (*setConnectionType)(struct CIMAPSession *self, uint64_t connectionType);
        void    (*fetchMessagesByNumber)(struct CIMAPSession *self, const char *folder, uint64_t request, CIndexSet uids, uint64_t *errorCode);
    };
    typedef struct CIMAPSession CIMAPSession;

    CIMAPSession newCIMAPSession();
    void deleteCIMAPSession(CIMAPSession self);

#ifdef __cplusplus
}
#endif

#endif