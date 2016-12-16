#ifndef MAILCORE_CIMAP_SESSION_H
#define MAILCORE_CIMAP_SESSION_H

#include <stdint.h>
#include <time.h>
#include <stdbool.h>

#include <dispatch/dispatch.h>

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
#include "CIMAPFetchFoldersOperation.h"
#include "CIMAPCapabilityOperation.h"
#include "CIMAPCheckAccountOperation.h"
#include "CIMAPCustomCommandOperation.h"
#include "CIMAPFetchContentToFileOperation.h"
#include "CIMAPFetchNamespaceOperation.h"
#include "CIMAPMoveMessagesOperation.h"
#include "CIMAPFetchParsedContentOperation.h"
#include "CIMAPMessageRenderingOperation.h"
#include "CIMAPQuotaOperation.h"
#include "CIMAPMessage.h"
#include "CIMAPIdentity.h"
#include "CIMAPIdentityOperation.h"

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
        CIMAPIdentity   (*clientIdentity)(struct CIMAPAsyncSession self);
        CIMAPIdentity   (*serverIdentity)(struct CIMAPAsyncSession self);
        //OperationQueueRunningChangeBlock (*operationQueueRunningChangeBlock)(struct CIMAPAsyncSession self);
        dispatch_queue_t    (*dispatchQueue)(struct CIMAPAsyncSession self);
        
        bool    (*isVoIPEnabled)(struct CIMAPAsyncSession self);
        bool    (*isIdleEnabled)(struct CIMAPAsyncSession self);
        bool    (*isOperationQueueRunning)(struct CIMAPAsyncSession self);
        
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
        void    (*setClientIdentity)(struct CIMAPAsyncSession self, CIMAPIdentity identity);
        void    (*setDispatchQueue)(struct CIMAPAsyncSession self, dispatch_queue_t queue);
        void    (*setConnectionLogger)(struct CIMAPAsyncSession self, ConnectionLogger logger);

        void                (*cancelAllOperations)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*connectOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*disconnectOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*noopOperation)(struct CIMAPAsyncSession self);
        CIMAPBaseOperation  (*expungeOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*createFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*deleteFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*storeFlagsByUIDOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet set, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags);
        CIMAPBaseOperation  (*storeFlagsByNumberOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags);
        CIMAPBaseOperation  (*storeLabelsByUIDOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, IMAPStoreFlagsRequestKind kind, CArray labels);
        CIMAPBaseOperation  (*storeLabelsByNumberOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CArray labels);
        CIMAPBaseOperation  (*renameFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder, const UChar *otherName);
        CIMAPBaseOperation  (*subscribeFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPBaseOperation  (*unsubscribeFolderOperation)(struct CIMAPAsyncSession self, const UChar *folder);

        
        CIMAPFetchFoldersOperation  (*fetchSubscribedFoldersOperation)(struct CIMAPAsyncSession self);
        CIMAPFetchContentToFileOperation (*fetchMessageAttachmentToFileOperation)(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, const UChar* partID, Encoding encoding, const UChar* filename, bool urgent);
        CIMAPFetchNamespaceOperation (*fetchNamespace)(struct CIMAPAsyncSession self);
        CIMAPCustomCommandOperation (*customCommandOperation)(struct CIMAPAsyncSession self, const UChar *command);
        CIMAPCheckAccountOperation  (*checkAccountOperation)(struct CIMAPAsyncSession self);
        CIMAPCapabilityOperation    (*capabilityOperation)(struct CIMAPAsyncSession self);
        CIMAPFetchFoldersOperation  (*fetchAllFoldersOperation)(struct CIMAPAsyncSession self);
        CIMAPAppendMessageOperation (*appendMessageOperation)(struct CIMAPAsyncSession session, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array);
        CIMAPAppendMessageOperation (*appendMessageOperationWithData)(struct CIMAPAsyncSession session, const UChar *folder, CData messageData, MessageFlag flags, CArray array);
        CIMAPFetchMessagesOperation (*fetchMessagesByNumberOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers);
        CIMAPFetchMessagesOperation (*fetchMessagesByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids);
        CIMAPFetchMessagesOperation (*syncMessagesByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq);
        CIMAPFetchContentOperation  (*fetchMessageByUIDOperation)(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageByNumberOperation)(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageAttachmentByUIDOperation)(struct CIMAPAsyncSession session, const UChar *folder, uint32_t uid, const UChar *partID, Encoding encoding, bool urgent);
        CIMAPFetchContentOperation  (*fetchMessageAttachmentByNumberOperation)(struct CIMAPAsyncSession session, const UChar *folder, uint32_t number, const UChar *partID, Encoding encoding, bool urgent);
        CIMAPSearchOperation        (*searchOperationWithExpression)(struct CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression);
        CIMAPSearchOperation        (*searchOperation)(struct CIMAPAsyncSession session, const UChar *folder, IMAPSearchKind kind, const UChar *str);
        CIMAPCopyMessagesOperation  (*copyMessagesOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder);
        CIMAPFolderInfoOperation    (*folderInfoOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPFolderStatusOperation  (*folderStatusOperation)(struct CIMAPAsyncSession self, const UChar *folder);
        CIMAPIdleOperation          (*idleOperation)(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID);
        
        CIMAPMoveMessagesOperation          (*moveMessagesOperation)(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, const UChar* destFolder);
        CIMAPFetchParsedContentOperation    (*fetchParsedMessageOperationByUIDOperation)(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, bool urgent);
        CIMAPFetchParsedContentOperation    (*fetchParsedMessageOperationByNumberOperation)(struct CIMAPAsyncSession self, const UChar* folder, uint32_t number, bool urgent);
        CIMAPMessageRenderingOperation      (*htmlRenderingOperation)(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder);
        CIMAPMessageRenderingOperation      (*htmlBodyRenderingOperation)(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder);
        CIMAPMessageRenderingOperation      (*plainTextRenderingOperation)(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder);
        CIMAPMessageRenderingOperation      (*plainTextBodyRenderingOperation)(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder, bool stripWhitespace);
        CIMAPQuotaOperation                 (*quotaOperation)(struct CIMAPAsyncSession self);
        CIMAPIdentityOperation              (*identityOperationWithClientIdentity)(struct CIMAPAsyncSession self, CIMAPIdentity identity);
    } CIMAPAsyncSession;

    CIMAPAsyncSession newCIMAPAsyncSession();
    void deleteCIMAPAsyncSession(CIMAPAsyncSession self);

#ifdef __cplusplus
}
#endif

#endif
