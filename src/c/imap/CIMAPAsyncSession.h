#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#include "CBase.h"
#include "CIndexSet.h"
#include "CArray.h"
#include "CIMAPNamespace.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPAppendMessageOperation.h"
#include "CIMAPFetchContentOperation.h"
#include "CIMAPFetchMessagesOperation.h"
#include "СIMAPSearchOperation.h"
#include "CIMAPSearchExpression.h"
#include "CIMAPCopyMessagesOperation.h"
#include "CIMAPFolderInfoOperation.h"
#include "CIMAPFolderStatusOperation.h"
#include "CMessageConstants.h"
#include "CIMAPIdleOperation.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    typedef struct CIMAPAsyncSession {
        ref self;
        void    (*setHostname)(struct CIMAPAsyncSession *self, const char *hostname);
        void    (*setPort)(struct CIMAPAsyncSession *self, unsigned int port);
        void    (*setUsername)(struct CIMAPAsyncSession *self, const char *username);
        void    (*setPassword)(struct CIMAPAsyncSession *self, const char *password);
        void    (*setConnectionType)(struct CIMAPAsyncSession *self, ConnectionType connectionType);
        void    (*setTimeout)(struct CIMAPAsyncSession *self, time_t timeout);
        void    (*setCheckCertificateEnabled)(struct CIMAPAsyncSession *self, bool checkCertificateEnabled);
        void    (*setOAuth2Token)(struct CIMAPAsyncSession *self, const char *token);
        void    (*setAuthType)(struct CIMAPAsyncSession *session, AuthType authType);  
        void    (*setMaximumConnections)(struct CIMAPAsyncSession *self, unsigned int maxConnections);
        void    (*setAllowsFolderConcurrentAccessEnabled)(struct CIMAPAsyncSession *self, bool enabled);
        void    (*setDefaultNamespace)(struct CIMAPAsyncSession *self, CIMAPNamespace nspace);

        CIMAPBaseOperation  (*disconnectOperation)(struct CIMAPAsyncSession *self);
        CIMAPBaseOperation  (*noopOperation)(struct CIMAPAsyncSession *self);
        CIMAPBaseOperation  (*checkAccountOperation)(struct CIMAPAsyncSession *self);
        CIMAPBaseOperation  (*capabilityOperation)(struct CIMAPAsyncSession *self);
        CIMAPBaseOperation  (*fetchAllFoldersOperation)(struct CIMAPAsyncSession *self);
        CIMAPBaseOperation  (*expungeOperation)(struct CIMAPAsyncSession *self, const char *folder);
        CIMAPBaseOperation  (*createFolderOperation)(struct CIMAPAsyncSession *self, const char *folder);
        CIMAPBaseOperation  (*deleteFolderOperation)(struct CIMAPAsyncSession *self, const char *folder);
        CIMAPBaseOperation  (*storeFlagsByUIDOperation)(struct CIMAPAsyncSession *session, const char *folder, CIndexSet *set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray *customFlags);

        CIMAPAppendMessageOperation (*appendMessageOperation)(struct CIMAPAsyncSession *session, const char *folder, const char *messagePath, MessageFlag flags, CArray *array);
        CIMAPFetchMessagesOperation (*fetchMessagesByNumberOperation)(struct CIMAPAsyncSession *session, const char *folder, IMAPMessagesRequestKind kind, CIndexSet *numbers);
        CIMAPFetchMessagesOperation (*fetchMessagesByUIDOperation)(struct CIMAPAsyncSession *session, const char *folder, IMAPMessagesRequestKind kind, CIndexSet *uids);
        CIMAPFetchMessagesOperation (*syncMessagesByUIDOperation)(struct CIMAPAsyncSession *session, const char *folder, IMAPMessagesRequestKind kind, CIndexSet *uids, uint64_t modSeq);
        CIMAPFetchContentOperation  (*fetchMessageByUIDOperation)(struct CIMAPAsyncSession *self, const char *folder, uint32_t uid, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageAttachmentByUIDOperation)(struct CIMAPAsyncSession *session, const char *folder, uint32_t uid, const char *partID, Encoding encoding, bool urgent);
        CIMAPSearchOperation        (*searchOperationWithExpression)(struct CIMAPAsyncSession *self, const char *folder, CIMAPSearchExpression expression);
        CIMAPSearchOperation        (*searchOperation)(struct CIMAPAsyncSession *session, const char *folder, IMAPSearchKind kind, const char *str);
        CIMAPCopyMessagesOperation  (*copyMessagesOperation)(struct CIMAPAsyncSession *self, const char *folder, CIndexSet *uids,const char *destFolder);
        CIMAPFolderInfoOperation    (*folderInfoOperation)(struct CIMAPAsyncSession *self, const char *folder);
        CIMAPFolderStatusOperation  (*folderStatusOperation)(struct CIMAPAsyncSession *self, const char *folder);
        //CIMAPIdleOperation          (*idleOperation)(struct CIMAPAsyncSession *self, const char *folder, uint32_t lastKnownUID);
    } CIMAPAsyncSession;

    CIMAPAsyncSession newCIMAPAsyncSession();
    void deleteCIMAPAsyncSession(CIMAPAsyncSession self);

#ifdef __cplusplus
}
#endif

#endif
