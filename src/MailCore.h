//
//  mailcore.h
//  mailcore2
//
//  Created by DINH Viêt Hoà on 1/10/13.
//  Copyright (c) 2013 MailCore. All rights reserved.
//

#ifndef MAILCORE_MAILCORE_H

#define MAILCORE_MAILCORE_H

#include <MailCore/MCCore.h>
#include <MailCore/MCAsync.h>

#include <MailCore/MCBase64.h>
#include <MailCore/MCDataDecoderUtils.h>
#include <MailCore/MCDataStreamDecoder.h>
#include <MailCore/MCDefines.h>
#include <MailCore/MCErrorMessage.h>
#include <MailCore/MCHTMLBodyRendererTemplateCallback.h>
#include <MailCore/MCHTMLRenderer.h>
#include <MailCore/MCHTMLRendererIMAPDataCallback.h>
#include <MailCore/MCIMAPAsyncConnection.h>
#include <MailCore/MCIMAPConnectOperation.h>
#include <MailCore/MCIMAPCreateFolderOperation.h>
#include <MailCore/MCIMAPDeleteFolderOperation.h>
#include <MailCore/MCIMAPDisconnectOperation.h>
#include <MailCore/MCIMAPExpungeOperation.h>
#include <MailCore/MCIMAPMultiDisconnectOperation.h>
#include <MailCore/MCIMAPNoopOperation.h>
#include <MailCore/MCIMAPRenameFolderOperation.h>
#include <MailCore/MCIMAPStoreFlagsOperation.h>
#include <MailCore/MCIMAPStoreLabelsOperation.h>
#include <MailCore/MCIMAPSubscribeFolderOperation.h>
#include <MailCore/MCLock.h>
#include <MailCore/MCMainThread.h>
#include <MailCore/MCMXRecordResolverOperation.h>
#include <MailCore/MCNNTPCheckAccountOperation.h>
#include <MailCore/MCNNTPDisconnectOperation.h>
#include <MailCore/MCOperationQueueCallback.h>
#include <MailCore/MCPOPCheckAccountOperation.h>
#include <MailCore/MCPOPDeleteMessagesOperation.h>
#include <MailCore/MCPOPNoopOperation.h>
#include <MailCore/MCSizeFormatter.h>
#include <MailCore/MCSMTPCheckAccountOperation.h>
#include <MailCore/MCSMTPDisconnectOperation.h>
#include <MailCore/MCSMTPLoginOperation.h>
#include <MailCore/MCSMTPNoopOperation.h>
#include <MailCore/MCSMTPSendWithDataOperation.h>
#include <MailCore/MCWin32.h>
#include <MailCore/MCZip.h>

#include <MailCore/CAbstractMessage.h>
#include <MailCore/CAbstractMessagePart.h>
#include <MailCore/CAbstractMessageRendererCallback.h>
#include <MailCore/CAbstractMessageRendererCallbackWrapper.h>
#include <MailCore/CAbstractMultipart.h>
#include <MailCore/CAbstractPart.h>
#include <MailCore/CAddress.h>
#include <MailCore/CMessageConstants.h>
#include <MailCore/CMessageHeader.h>

#include <MailCore/CBase.h>
#include <MailCore/CCore.h>

#include <MailCore/CArray.h>
#include <MailCore/CData.h>
#include <MailCore/CDictionary.h>
#include <MailCore/CIndexSet.h>
#include <MailCore/CObject.h>
#include <MailCore/MailCoreString.h>

#include <MailCore/CAttachment.h>
#include <MailCore/CMessageBuilder.h>
#include <MailCore/CMessageParser.h>
#include <MailCore/CMessagePart.h>
#include <MailCore/CMultipart.h>
	
#include <MailCore/CMailProvider.h>
#include <MailCore/CMailProvidersManager.h>
#include <MailCore/CNetService.h>

#include <MailCore/CSMTPOperation.h>
#include <MailCore/CSMTPSession.h>

#include <MailCore/CIMAPAppendMessageOperation.h>
#include <MailCore/CIMAPAsyncSession.h>
#include <MailCore/CIMAPBaseOperation.h>
#include <MailCore/CIMAPCapabilityOperation.h>
#include <MailCore/CIMAPCheckAccountOperation.h>
#include <MailCore/CIMAPCopyMessagesOperation.h>
#include <MailCore/CIMAPCustomCommandOperation.h>
#include <MailCore/CIMAPFetchContentOperation.h>
#include <MailCore/CIMAPFetchContentToFileOperation.h>
#include <MailCore/CIMAPFetchFoldersOperation.h>
#include <MailCore/CIMAPFetchMessagesOperation.h>
#include <MailCore/CIMAPFetchNamespaceOperation.h>
#include <MailCore/CIMAPFetchParsedContentOperation.h>
#include <MailCore/CIMAPFolder.h>
#include <MailCore/CIMAPFolderInfo.h>
#include <MailCore/CIMAPFolderInfoOperation.h>
#include <MailCore/CIMAPFolderStatus.h>
#include <MailCore/CIMAPFolderStatusOperation.h>
#include <MailCore/CIMAPIdentity.h>
#include <MailCore/CIMAPIdentityOperation.h>
#include <MailCore/CIMAPIdleOperation.h>
#include <MailCore/CIMAPMessage.h>
#include <MailCore/CIMAPMessagePart.h>
#include <MailCore/CIMAPMessageRenderingOperation.h>
#include <MailCore/CIMAPMoveMessagesOperation.h>
#include <MailCore/CIMAPMultipart.h>
#include <MailCore/CIMAPNamespace.h>
#include <MailCore/CIMAPNamespaceItem.h>
#include <MailCore/CIMAPPart.h>
#include <MailCore/CIMAPQuotaOperation.h>
#include <MailCore/CIMAPSearchExpression.h>
#include <MailCore/CIMAPSearchOperation.h>

#endif
