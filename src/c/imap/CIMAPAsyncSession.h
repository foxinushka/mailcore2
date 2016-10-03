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

namespace mailcore {
    class IMAPAsyncSession;
}

extern "C" {
#endif
    
    typedef struct CIMAPAsyncSession {
#ifdef __cplusplus
        mailcore::IMAPAsyncSession*     instance;
#else
        void*                           instance;
#endif
        
        void    (*hostname)(struct CIMAPAsyncSession self, const UChar *hostname);
        void    (*port)(struct CIMAPAsyncSession self, unsigned int port);
        void    (*username)(struct CIMAPAsyncSession self, const UChar *username);
        void    (*password)(struct CIMAPAsyncSession self, const UChar *password);
        void    (*connectionType)(struct CIMAPAsyncSession self, ConnectionType connectionType);
        void    (*timeout)(struct CIMAPAsyncSession self, time_t timeout);
        void    (*isCheckCertificateEnabled)(struct CIMAPAsyncSession self, bool checkCertificateEnabled);
        void    (*OAuth2Token)(struct CIMAPAsyncSession self, const UChar *token);
        void    (*authType)(struct CIMAPAsyncSession self, AuthType authType);
        void    (*maximumConnections)(struct CIMAPAsyncSession self, unsigned int maxConnections);
        void    (*allowsFolderConcurrentAccessEnabled)(struct CIMAPAsyncSession self, bool enabled);
        void    (*defaultNamespace)(struct CIMAPAsyncSession self, CIMAPNamespace nspace);
        
        void    (*setHostname)(struct CIMAPAsyncSession self, const UChar *hostname);
        void    (*setPort)(struct CIMAPAsyncSession self, unsigned int port);
        void    (*setUsername)(struct CIMAPAsyncSession self, const UChar *username);
        void    (*setPassword)(struct CIMAPAsyncSession self, const UChar *password);
        void    (*setConnectionType)(struct CIMAPAsyncSession self, ConnectionType connectionType);
        void    (*setTimeout)(struct CIMAPAsyncSession self, time_t timeout);
        void    (*setCheckCertificateEnabled)(struct CIMAPAsyncSession self, bool checkCertificateEnabled);
        void    (*setOAuth2Token)(struct CIMAPAsyncSession self, const UChar *token);
        void    (*setAuthType)(struct CIMAPAsyncSession self, AuthType authType);
        void    (*setMaximumConnections)(struct CIMAPAsyncSession self, unsigned int maxConnections);
        void    (*setAllowsFolderConcurrentAccessEnabled)(struct CIMAPAsyncSession self, bool enabled);
        void    (*setDefaultNamespace)(struct CIMAPAsyncSession self, CIMAPNamespace nspace);

        CIMAPBaseOperation  (*disconnectOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*noopOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*checkAccountOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*capabilityOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*fetchAllFoldersOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*expungeOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*createFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*deleteFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*storeFlagsByUIDOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags);

        CIMAPAppendMessageOperation (*appendMessageOperation)(struct CIMAPAsyncSession session, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array);
        CIMAPFetchMessagesOperation (*fetchMessagesByNumberOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers);
        CIMAPFetchMessagesOperation (*fetchMessagesByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids);
        CIMAPFetchMessagesOperation (*syncMessagesByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq);
        CIMAPFetchContentOperation  (*fetchMessageByUIDOperation)(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageAttachmentByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent);
        CIMAPSearchOperation        (*searchOperationWithExpression)(struct CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression);
        CIMAPSearchOperation        (*searchOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPSearchKind kind, const UChar *str);
        CIMAPCopyMessagesOperation  (*copyMessagesOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder);
        CIMAPFolderInfoOperation    (*folderInfoOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPFolderStatusOperation  (*folderStatusOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPIdleOperation          (*idleOperation)(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID);
    } CIMAPAsyncSession;

    CIMAPAsyncSession newCIMAPAsyncSession();
    void deleteCIMAPAsyncSession(CIMAPAsyncSession self);

#ifdef __cplusplus
}
#endif

#endif
