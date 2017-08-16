//
//  MailCore.h
//  mailcore2
//
//  Created by Anton Pogonets on 19.05.17.
//  Copyright © 2017 MailCore. All rights reserved.
//



#include <MailCore/CIndexSet.h>
#include <MailCore/CArray.h>
#include <MailCore/CObject.h>
#include <MailCore/MailCoreString.h>
#include <MailCore/CData.h>
#include <MailCore/CAbstractMessage.h>
#include <MailCore/CAbstractMessagePart.h>
#include <MailCore/CAbstractMultipart.h>
#include <MailCore/CAddress.h>
#include <MailCore/CAbstractPart.h>
#include <MailCore/CMessageHeader.h>
#include <MailCore/CAbstractMessageRendererCallback.h>

#include <MailCore/COperation.h>
#include <MailCore/CIMAPBaseOperation.h>
#include <MailCore/CIMAPIdleOperation.h>
#include <MailCore/CIMAPFolder.h>
#include <MailCore/CIMAPMessage.h>
#include <MailCore/CIMAPMessagePart.h>
#include <MailCore/CIMAPMultipart.h>
#include <MailCore/CIMAPNamespace.h>
#include <MailCore/CIMAPNamespaceItem.h>
#include <MailCore/CIMAPPart.h>
#include <MailCore/CIMAPFolderInfo.h>
#include <MailCore/CIMAPFolderStatus.h>
#include <MailCore/CIMAPSearchExpression.h>
#include <MailCore/CIMAPAsyncSession.h>
#include <MailCore/CSMTPSession.h>

#include <MailCore/CIMAPSearchOperation.h>
#include <MailCore/CIMAPSearchExpression.h>
#include <MailCore/CIMAPCopyMessagesOperation.h>
#include <MailCore/CIMAPFolderInfoOperation.h>
#include <MailCore/CIMAPFolderStatusOperation.h>
#include <MailCore/CMessageConstants.h>
#include <MailCore/CIMAPIdleOperation.h>
#include <MailCore/CIMAPFetchFoldersOperation.h>
#include <MailCore/CIMAPCapabilityOperation.h>
#include <MailCore/CIMAPCheckAccountOperation.h>
#include <MailCore/CIMAPCustomCommandOperation.h>
#include <MailCore/CIMAPFetchContentToFileOperation.h>
#include <MailCore/CIMAPFetchNamespaceOperation.h>
#include <MailCore/CIMAPMoveMessagesOperation.h>
#include <MailCore/CIMAPFetchParsedContentOperation.h>
#include <MailCore/CIMAPMessageRenderingOperation.h>
#include <MailCore/CIMAPQuotaOperation.h>
#include <MailCore/CIMAPMessage.h>
#include <MailCore/CIMAPIdentity.h>
#include <MailCore/CIMAPIdentityOperation.h>

#include <MailCore/CSMTPOperation.h>
#include <MailCore/CAttachment.h>
#include <MailCore/CMessageBuilder.h>
#include <MailCore/CMessageParser.h>
#include <MailCore/CMessagePart.h>
#include <MailCore/CMultipart.h>

#include <MailCore/CMailProvidersManager.h>
#include <MailCore/CMailProvider.h>
#include <MailCore/CNetService.h>

#include <MailCore/RSMLibetpanHelper.h>
