#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include "stdint.h"
#include "CBase.h"
#include "CIndexSet.h"
#include "CArray.h"
#include "CIMAPNamespace.h"
#include "CIMAPOperation.h"
#include "CIMAPAppendMessageOperation.h"
#include "CIMAPFetchContentOperation.h"
#include "CIMAPFetchMessagesOperation.h"
#include "СIMAPSearchOperation.h"
#include "СIMAPSearchExpression.h"
#include "CIMAPCopyMessagesOperation.h"
#include "CIMAPFolderInfoOperation.h"
#include "CIMAPFolderStatusOperation.h"

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
        void    (*setDefaultNamespace)(CIMAPAsyncSession *self, CIMAPNamespace *nspace);

        CIMAPOperation  (*disconnectOperation)(CIMAPAsyncSession *self);
        CIMAPOperation  (*noopOperation)(CIMAPAsyncSession *self);
        CIMAPOperation  (*checkAccountOperation)(CIMAPAsyncSession *self);
        CIMAPOperation  (*capabilityOperation)(CIMAPAsyncSession *self);
        CIMAPOperation  (*fetchAllFoldersOperation)(CIMAPAsyncSession *self);
        CIMAPOperation  (*expungeOperation)(CIMAPAsyncSession *self, const char *folder);
        CIMAPOperation  (*createFolderOperation)(CIMAPAsyncSession *self, const char *folder);
        CIMAPOperation  (*deleteFolderOperation)(CIMAPAsyncSession *self, const char *folder);
        CIMAPOperation  (*storeFlagsByUIDOperation)(CIMAPAsyncSession *self, const char *folder, CIndexSet *set, uint64_t kind, uint64_t flags, CArray *customFlags);

        CIMAPAppendMessageOperation (*appendMessageOperation)(CIMAPAsyncSession *self, const char *folder, const char *messagePath, uint64_t flags, CArray *array);
        CIMAPFetchMessagesOperation (*fetchMessagesByNumberOperation)(CIMAPAsyncSession *self, const char *folder, uint64_t kind, CIndexSet *numbers);
        CIMAPFetchMessagesOperation (*fetchMessagesByUIDOperation)(CIMAPAsyncSession *self, const char *folder, uint64_t kind, CIndexSet *uids);
        CIMAPFetchMessagesOperation (*syncMessagesByUIDOperation)(CIMAPAsyncSession *self, const char *folder, uint64_t kind, CIndexSet *uids, uint64_t modSeq);
        CIMAPFetchContentOperation  (*fetchMessageByUIDOperation)(CIMAPAsyncSession *self, const char *folder, uint32_t uid, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageAttachmentByUIDOperation)(CIMAPAsyncSession *self, const char *folder, uint32_t uid, const char *partID, uint64_t encoding, bool urgent);
        CIMAPSearchOperation        (*searchOperationWithExpression)(CIMAPAsyncSession *self, const char *folder, СIMAPSearchExpression *expression);
        CIMAPSearchOperation        (*searchOperation)(CIMAPAsyncSession *self, const char *folder, uint64_t kind, const char *str);
        CIMAPCopyMessagesOperation  (*copyMessagesOperation)(CIMAPAsyncSession *self, const char *folder, CIndexSet *uids,const char *destFolder);
        CIMAPFolderInfoOperation    (*folderInfoOperation)(CIMAPAsyncSession *self, const char *folder);
        CIMAPFolderStatusOperation  (*folderStatusOperation)(CIMAPAsyncSession *self, const char *folder);


        //void    (*fetchMessagesByNumber)(struct CIMAPAsyncSession *self, const char *folder, uint64_t request, CIndexSet uids, uint64_t *errorCode);
    };
    typedef struct CIMAPAsyncSession CIMAPAsyncSession;

    CIMAPAsyncSession newCIMAPAsyncSession();
    void deleteCIMAPAsyncSession(CIMAPAsyncSession self);

#ifdef __cplusplus
}
#endif

#endif