//
//  CMailCore.h
//  CMailCore framework
//
//  Copyright (c) 2015 Readdle. All rights reserved.
//

#include <libetpan/libetpan.h>

extern int mailimap_hack_date_time_parse(char * str,
                                             struct mailimap_date_time ** result,
                                             size_t progr_rate,
                                             progress_function * progr_fun);

extern time_t MailCoreTimestampFromDate(struct mailimf_date_time * date_time);
extern time_t MailCoreTimestampFromIMAPDate(struct mailimap_date_time * imap_date);

#include "CAbstractMessage.h"
#include "CAbstractMessagePart.h"
#include "CAbstractMessageRendererCallback.h"
#include "CAbstractMessageRendererCallbackWrapper.h"
#include "CAbstractMultipart.h"
#include "CAbstractPart.h"
#include "CAddress.h"
#include "CArray.h"
#include "CAttachment.h"
#include "CBase.h"
#include "CData.h"
#include "CDictionary.h"
#include "CIMAPAppendMessageOperation.h"
#include "CIMAPAsyncSession.h"
#include "CIMAPBaseOperation.h"
#include "CIMAPCapabilityOperation.h"
#include "CIMAPCheckAccountOperation.h"
#include "CIMAPCopyMessagesOperation.h"
#include "CIMAPCustomCommandOperation.h"
#include "CIMAPFetchContentOperation.h"
#include "CIMAPFetchContentToFileOperation.h"
#include "CIMAPFetchFoldersOperation.h"
#include "CIMAPFetchMessagesOperation.h"
#include "CIMAPFetchNamespaceOperation.h"
#include "CIMAPFetchParsedContentOperation.h"
#include "CIMAPFolder.h"
#include "CIMAPFolderInfo.h"
#include "CIMAPFolderInfoOperation.h"
#include "CIMAPFolderStatus.h"
#include "CIMAPFolderStatusOperation.h"
#include "CIMAPIdentity.h"
#include "CIMAPIdentityOperation.h"
#include "CIMAPIdleOperation.h"
#include "CIMAPMessage.h"
#include "CIMAPMessagePart.h"
#include "CIMAPMessageRenderingOperation.h"
#include "CIMAPMoveMessagesOperation.h"
#include "CIMAPMultipart.h"
#include "CIMAPNamespace.h"
#include "CIMAPNamespaceItem.h"
#include "CIMAPPart.h"
#include "CIMAPQuotaOperation.h"
#include "CIMAPSearchExpression.h"
#include "CIMAPSearchOperation.h"
#include "CIndexSet.h"
#include "CMailProvider.h"
#include "CMailProvidersManager.h"
#include "CMessageBuilder.h"
#include "CMessageConstants.h"
#include "CMessageHeader.h"
#include "CMessageParser.h"
#include "CMessagePart.h"
#include "CMultipart.h"
#include "CNetService.h"
#include "CObject.h"
#include "COperation.h"
#include "CSMTPOperation.h"
#include "CSMTPSession.h"
#include "CAutoreleasePool.h"
#include "MailCoreString.h"
