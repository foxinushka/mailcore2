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
#include "CIMAPSearchOperation.h"
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
    } CIMAPAsyncSession;

    const UChar*        CIMAPAsyncSession_hostname(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.hostname(self:));

    unsigned int        CIMAPAsyncSession_port(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.port(self:));

    const UChar*        CIMAPAsyncSession_username(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.username(self:));

    const UChar*        CIMAPAsyncSession_password(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.password(self:));

    ConnectionType      CIMAPAsyncSession_connectionType(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.connectionType(self:));

    time_t              CIMAPAsyncSession_timeout(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.timeout(self:));

    bool                CIMAPAsyncSession_isCheckCertificateEnabled(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.isCheckCertificateEnabled(self:));

    const UChar*        CIMAPAsyncSession_OAuth2Token(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.OAuth2Token(self:));

    AuthType            CIMAPAsyncSession_authType(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.authType(self:));

    unsigned int        CIMAPAsyncSession_maximumConnections(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.maximumConnections(self:));

    bool                CIMAPAsyncSession_allowsFolderConcurrentAccessEnabled(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.allowsFolderConcurrentAccessEnabled(self:));

    CIMAPNamespace      CIMAPAsyncSession_defaultNamespace(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.defaultNamespace(self:));

    CIMAPIdentity       CIMAPAsyncSession_clientIdentity(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.clientIdentity(self:));

    CIMAPIdentity       CIMAPAsyncSession_serverIdentity(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.serverIdentity(self:));

    dispatch_queue_t    CIMAPAsyncSession_dispatchQueue(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(CIMAPAsyncSession.dispatchQueue(self:));

        
    bool                CIMAPAsyncSession_isVoIPEnabled(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.isVoIPEnabled(self:));

    bool                CIMAPAsyncSession_isIdleEnabled(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.isIdleEnabled(self:));

    bool                CIMAPAsyncSession_isOperationQueueRunning(struct CIMAPAsyncSession self)
                        CF_SWIFT_NAME(getter:CIMAPAsyncSession.isOperationQueueRunning(self:));

        
    void                CIMAPAsyncSession_setHostname(struct CIMAPAsyncSession self, const UChar *hostname)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.hostname(self:newValue:));

    void                CIMAPAsyncSession_setPort(struct CIMAPAsyncSession self, unsigned int port)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.port(self:newValue:));

    void                CIMAPAsyncSession_setUsername(struct CIMAPAsyncSession self, const UChar *username)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.username(self:newValue:));

    void                CIMAPAsyncSession_setPassword(struct CIMAPAsyncSession self, const UChar *password)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.password(self:newValue:));

    void                CIMAPAsyncSession_setConnectionType(struct CIMAPAsyncSession self, ConnectionType connectionType)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.connectionType(self:newValue:));

    void                CIMAPAsyncSession_setTimeout(struct CIMAPAsyncSession self, time_t timeout)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.timeout(self:newValue:));

    void                CIMAPAsyncSession_setCheckCertificateEnabled(struct CIMAPAsyncSession self, bool checkCertificateEnabled)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.isCheckCertificateEnabled(self:newValue:));

    void                CIMAPAsyncSession_setOAuth2Token(struct CIMAPAsyncSession self, const UChar *token)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.OAuth2Token(self:newValue:));

    void                CIMAPAsyncSession_setAuthType(struct CIMAPAsyncSession self, AuthType authType)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.authType(self:newValue:));

    void                CIMAPAsyncSession_setMaximumConnections(struct CIMAPAsyncSession self, unsigned int maxConnections)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.maximumConnections(self:newValue:));

    void                CIMAPAsyncSession_setAllowsFolderConcurrentAccessEnabled(struct CIMAPAsyncSession self, bool enabled)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.allowsFolderConcurrentAccessEnabled(self:newValue:));

    void                CIMAPAsyncSession_setDefaultNamespace(struct CIMAPAsyncSession self, CIMAPNamespace nspace)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.defaultNamespace(self:newValue:));

    void                CIMAPAsyncSession_setClientIdentity(struct CIMAPAsyncSession self, CIMAPIdentity identity)
                        CF_SWIFT_NAME(setter:CIMAPAsyncSession.clientIdentity(self:newValue:));

    void                CIMAPAsyncSession_setDispatchQueue(struct CIMAPAsyncSession self, dispatch_queue_t queue)
                        CF_SWIFT_NAME(CIMAPAsyncSession.setDispatchQueue(self:newValue:));

    void                CIMAPAsyncSession_setConnectionLogger(struct CIMAPAsyncSession self, ConnectionLogger logger)
                        CF_SWIFT_NAME(CIMAPAsyncSession.setConnectionLogger(self:newValue:));


    void                    CIMAPAsyncSession_cancelAllOperations(struct CIMAPAsyncSession self)
                            CF_SWIFT_NAME(CIMAPAsyncSession.cancelAllOperations(self:));

    CIMAPBaseOperation      CIMAPAsyncSession_connectOperation(struct CIMAPAsyncSession self)
                            CF_SWIFT_NAME(CIMAPAsyncSession.connectOperation(self:));

    CIMAPBaseOperation      CIMAPAsyncSession_disconnectOperation(struct CIMAPAsyncSession self)
                            CF_SWIFT_NAME(CIMAPAsyncSession.disconnectOperation(self:));

    CIMAPBaseOperation      CIMAPAsyncSession_noopOperation(struct CIMAPAsyncSession self)
                            CF_SWIFT_NAME(CIMAPAsyncSession.noopOperation(self:));

    CIMAPBaseOperation      CIMAPAsyncSession_expungeOperation(struct CIMAPAsyncSession self, const UChar *folder)
                            CF_SWIFT_NAME(CIMAPAsyncSession.expungeOperation(self:folder:));

    CIMAPBaseOperation      CIMAPAsyncSession_createFolderOperation(struct CIMAPAsyncSession self, const UChar *folder)
                            CF_SWIFT_NAME(CIMAPAsyncSession.createFolderOperation(self:folder:));

    CIMAPBaseOperation      CIMAPAsyncSession_deleteFolderOperation(struct CIMAPAsyncSession self, const UChar *folder)
                            CF_SWIFT_NAME(CIMAPAsyncSession.deleteFolderOperation(self:folder:));

    CIMAPBaseOperation      CIMAPAsyncSession_storeFlagsByUIDOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet set,
                                                                       IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags)
                            CF_SWIFT_NAME(CIMAPAsyncSession.storeFlagsByUIDOperation(self:folder:set:kind:flags:customFlags:));

    CIMAPBaseOperation      CIMAPAsyncSession_storeFlagsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers,
                                                                          IMAPStoreFlagsRequestKind kind, MessageFlag flags, CArray customFlags)
                            CF_SWIFT_NAME(CIMAPAsyncSession.storeFlagsByNumberOperation(self:folder:numbers:kind:flags:customFlags:));

    CIMAPBaseOperation      CIMAPAsyncSession_storeLabelsByUIDOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, IMAPStoreFlagsRequestKind kind, CArray labels)
                            CF_SWIFT_NAME(CIMAPAsyncSession.storeLabelsByUIDOperation(self:folder:uids:kind:labels:));

    CIMAPBaseOperation      CIMAPAsyncSession_storeLabelsByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet numbers, IMAPStoreFlagsRequestKind kind, CArray labels)
                            CF_SWIFT_NAME(CIMAPAsyncSession.storeLabelsByNumberOperation(self:folder:numbers:kind:labels:));

    CIMAPBaseOperation      CIMAPAsyncSession_renameFolderOperation(struct CIMAPAsyncSession self, const UChar *folder, const UChar *otherName)
                            CF_SWIFT_NAME(CIMAPAsyncSession.renameFolderOperation(self:folder:otherName:));

    CIMAPBaseOperation      CIMAPAsyncSession_subscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder)
                            CF_SWIFT_NAME(CIMAPAsyncSession.subscribeFolderOperation(self:folder:));

    CIMAPBaseOperation      CIMAPAsyncSession_unsubscribeFolderOperation(struct CIMAPAsyncSession self, const UChar *folder)
                            CF_SWIFT_NAME(CIMAPAsyncSession.unsubscribeFolderOperation(self:folder:));


        
    CIMAPFetchFoldersOperation          CIMAPAsyncSession_fetchSubscribedFoldersOperation(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchSubscribedFoldersOperation(self:));

    CIMAPFetchContentToFileOperation    CIMAPAsyncSession_fetchMessageAttachmentToFileOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, const UChar* partID,
                                                                                                Encoding encoding, const UChar* filename, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessageAttachmentToFileOperation(self:folder:uid:partID:encoding:filename:urgent:));

    CIMAPFetchNamespaceOperation        CIMAPAsyncSession_fetchNamespace(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchNamespace(self:));

    CIMAPCustomCommandOperation         CIMAPAsyncSession_customCommandOperation(struct CIMAPAsyncSession self, const UChar *command)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.customCommandOperation(self:command:));

    CIMAPCheckAccountOperation          CIMAPAsyncSession_checkAccountOperation(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.checkAccountOperation(self:));

    CIMAPCapabilityOperation            CIMAPAsyncSession_capabilityOperation(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.capabilityOperation(self:));

    CIMAPFetchFoldersOperation          CIMAPAsyncSession_fetchAllFoldersOperation(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchAllFoldersOperation(self:));

    CIMAPAppendMessageOperation         CIMAPAsyncSession_appendMessageOperation(struct CIMAPAsyncSession session, const UChar *folder, const UChar *messagePath, MessageFlag flags, CArray array)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.appendMessageOperation(self:folder:messagePath:flags:array:));

    CIMAPAppendMessageOperation         CIMAPAsyncSession_appendMessageOperationWithData(struct CIMAPAsyncSession session, const UChar *folder, CData messageData, MessageFlag flags, CArray array)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.appendMessageOperationWithData(self:folder:messageData:flags:array:));

    CIMAPFetchMessagesOperation         CIMAPAsyncSession_fetchMessagesByNumberOperation(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet numbers)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessagesByNumberOperation(self:folder:kind:numbers:));

    CIMAPFetchMessagesOperation         CIMAPAsyncSession_fetchMessagesByUIDOperation(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessagesByUIDOperation(self:folder:kind:uids:));

    CIMAPFetchMessagesOperation         CIMAPAsyncSession_syncMessagesByUIDOperation(struct CIMAPAsyncSession session, const UChar *folder, IMAPMessagesRequestKind kind, CIndexSet uids, uint64_t modSeq)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.syncMessagesByUIDOperation(self:folder:kind:uids:modSeq:));

    CIMAPFetchContentOperation          CIMAPAsyncSession_fetchMessageByUIDOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessageByUIDOperation(self:folder:uid:urgent:));

    CIMAPFetchContentOperation          CIMAPAsyncSession_fetchMessageByNumberOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t uid, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessageByNumberOperation(self:folder:uid:urgent:));

    CIMAPFetchContentOperation          CIMAPAsyncSession_fetchMessageAttachmentByUIDOperation(struct CIMAPAsyncSession session, const UChar *folder, uint32_t uid,
                                                                                               const UChar *partID, Encoding encoding, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessageAttachmentByUIDOperation(self:folder:uid:partID:encoding:urgent:));

    CIMAPFetchContentOperation          CIMAPAsyncSession_fetchMessageAttachmentByNumberOperation(struct CIMAPAsyncSession session, const UChar *folder, uint32_t number,
                                                                                                  const UChar *partID, Encoding encoding, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchMessageAttachmentByNumberOperation(self:folder:number:partID:encoding:urgent:));

    CIMAPSearchOperation                CIMAPAsyncSession_searchOperationWithExpression(struct CIMAPAsyncSession self, const UChar *folder, CIMAPSearchExpression expression)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.searchOperationWithExpression(self:folder:expression:));

    CIMAPSearchOperation                CIMAPAsyncSession_searchOperation(struct CIMAPAsyncSession session, const UChar *folder, IMAPSearchKind kind, const UChar *str)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.searchOperation(self:folder:kind:str:));

    CIMAPCopyMessagesOperation          CIMAPAsyncSession_copyMessagesOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids,const UChar *destFolder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.copyMessagesOperation(self:folder:uids:destFolder:));

    CIMAPFolderInfoOperation            CIMAPAsyncSession_folderInfoOperation(struct CIMAPAsyncSession self, const UChar *folder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.folderInfoOperation(self:folder:));

    CIMAPFolderStatusOperation          CIMAPAsyncSession_folderStatusOperation(struct CIMAPAsyncSession self, const UChar *folder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.folderStatusOperation(self:folder:));

    CIMAPIdleOperation                  CIMAPAsyncSession_idleOperation(struct CIMAPAsyncSession self, const UChar *folder, uint32_t lastKnownUID)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.idleOperation(self:folder:lastKnownUID:));

        
    CIMAPMoveMessagesOperation          CIMAPAsyncSession_moveMessagesOperation(struct CIMAPAsyncSession self, const UChar *folder, CIndexSet uids, const UChar* destFolder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.moveMessagesOperation(self:folder:uids:destFolder:));

    CIMAPFetchParsedContentOperation    CIMAPAsyncSession_fetchParsedMessageOperationByUIDOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t uid, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchParsedMessageOperationByUIDOperation(self:folder:uid:urgent:));

    CIMAPFetchParsedContentOperation    CIMAPAsyncSession_fetchParsedMessageOperationByNumberOperation(struct CIMAPAsyncSession self, const UChar* folder, uint32_t number, bool urgent)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.fetchParsedMessageOperationByNumberOperation(self:folder:number:urgent:));

    CIMAPMessageRenderingOperation      CIMAPAsyncSession_htmlRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.htmlRenderingOperation(self:message:folder:));

    CIMAPMessageRenderingOperation      CIMAPAsyncSession_htmlBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.htmlBodyRenderingOperation(self:message:folder:));

    CIMAPMessageRenderingOperation      CIMAPAsyncSession_plainTextRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.plainTextRenderingOperation(self:message:folder:));

    CIMAPMessageRenderingOperation      CIMAPAsyncSession_plainTextBodyRenderingOperation(struct CIMAPAsyncSession self, CIMAPMessage message, const UChar* folder, bool stripWhitespace)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.plainTextBodyRenderingOperation(self:message:folder:stripWhitespace:));

    CIMAPQuotaOperation                 CIMAPAsyncSession_quotaOperation(struct CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.quotaOperation(self:));

    CIMAPIdentityOperation              CIMAPAsyncSession_identityOperationWithClientIdentity(struct CIMAPAsyncSession self, CIMAPIdentity identity)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.identityOperationWithClientIdentity(self:identity:));


    CIMAPAsyncSession                   CIMAPAsyncSession_new()
                                        CF_SWIFT_NAME(CIMAPAsyncSession.init());

    void                                CIMAPAsyncSession_release(CIMAPAsyncSession self)
                                        CF_SWIFT_NAME(CIMAPAsyncSession.release(self:));

#ifdef __cplusplus
}
#endif

#endif
