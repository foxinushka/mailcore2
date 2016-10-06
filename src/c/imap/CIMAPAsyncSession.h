#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#ifdef __ANDROID__
#else
#include <dispatch/dispatch.h>
#endif

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

class CIMAPCallbackBridge;

extern "C" {
#endif
    
    typedef struct CIMAPAsyncSession {
#ifdef __cplusplus
        mailcore::IMAPAsyncSession*     instance;
        CIMAPCallbackBridge*            _callback;
#else
        void*                           instance;
        void*                           _callback;
#endif
        
        const UChar*    (*hostname)(struct CIMAPAsyncSession self);
        unsigned int    (*port)(struct CIMAPAsyncSession self);
        const UChar*    (*username)(struct CIMAPAsyncSession self);
        const UChar*    (*password)(struct CIMAPAsyncSession self);
        ConnectionType  (*connectionType)(struct CIMAPAsyncSession self);
        time_t          (*timeout)(struct CIMAPAsyncSession self);
        bool            (*isCheckCertificateEnabled)(struct CIMAPAsyncSession self);
        const UChar*    (*OAuth2Token)(struct CIMAPAsyncSession self);
        AuthType        (*authType)(struct CIMAPAsyncSession self);
        unsigned int    (*maximumConnections)(struct CIMAPAsyncSession self);
        bool            (*allowsFolderConcurrentAccessEnabled)(struct CIMAPAsyncSession self);
        CIMAPNamespace  (*defaultNamespace)(struct CIMAPAsyncSession self);
        
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
        
#ifdef __ANDROID__
#else
        dispatch_queue_t    (*dispatchQueue)(struct CIMAPAsyncSession self);
        void                (*setDispatchQueue)(struct CIMAPAsyncSession self, dispatch_queue_t queue);
#endif
        void    (*setConnectionLogger)(struct CIMAPAsyncSession self, ConnectionLogger logger);

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
