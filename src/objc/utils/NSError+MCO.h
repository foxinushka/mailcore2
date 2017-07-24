//
//  Created by mronge on 1/31/13.
//

#ifndef MAILCORE_NSERROR_MCO_H

#define MAILCORE_NSERROR_MCO_H

#import <Foundation/Foundation.h>

#import <MailCore/MCMessageConstants.h>

/** Error domain for mailcore.*/
#define MCOErrorDomain @"MCOErrorDomain"

/** Here's the list of errors.*/
typedef NS_ENUM(NSInteger, MCOErrorCode) {
    /** No error occurred.*/
    MCOErrorNone, // 0
    /** An error related to the connection occurred.*/
    /** It could not connect or it's been disconnected.*/
    MCOErrorConnection,
    /** TLS/SSL connection was not available.*/
    MCOErrorTLSNotAvailable,
    /** The protocol could not be parsed.*/
    MCOErrorParse,
    /** Certificate was not valid.*/
    MCOErrorCertificate,
    /** An authentication error occurred.*/
    MCOErrorAuthentication,
    /** Specific to Gmail: IMAP not enabled.*/
    MCOErrorGmailIMAPNotEnabled,
    /** Specific to Gmail: Exceeded bandwidth limit.*/
    MCOErrorGmailExceededBandwidthLimit,
    /** Specific to Gmail: Too many simultaneous connections.*/
    MCOErrorGmailTooManySimultaneousConnections,
    /** Specific to Mobile Me: Moved to iCloud.*/
    MCOErrorMobileMeMoved,
    /** Specific to Yahoo: not available.*/
    MCOErrorYahooUnavailable, // 10
    /** Non existant folder, select failed.*/
    MCOErrorNonExistantFolder,
    /** IMAP: Error occurred while renaming a folder.*/
    MCOErrorRename,
    /** IMAP: Error occurred while deleting a folder.*/
    MCOErrorDelete,
    /** IMAP: Error occurred while creating a folder.*/
    MCOErrorCreate,
    /** IMAP: Error occurred while subscribing/unsubcribing to a folder.*/
    MCOErrorSubscribe,
    /** IMAP: Error occurred while adding a message to a folder.*/
    MCOErrorAppend,
    /** IMAP: Error occurred while copying a message.*/
    MCOErrorCopy,
    /** IMAP: Error occurred while expunging.*/
    MCOErrorExpunge,
    /** IMAP: Error occurred while fetching messages.*/
    MCOErrorFetch,
    /** IMAP: Error occurred while IDLing.*/
    MCOErrorIdle, // 20
    /** IMAP: Error occurred while sending/getting identity.*/
    MCOErrorIdentity,
    /** IMAP: Error occurred while getting namespace.*/
    MCOErrorNamespace,
    /** IMAP: Error occurred while storing flags.*/
    MCOErrorStore,
    /** IMAP: Error wile getting capabilities.*/
    MCOErrorCapability,
    /** STARTTLS is not available.*/
    MCOErrorStartTLSNotAvailable,
    /** SMTP: Illegal attachment: certain kind of attachment cannot be sent.*/
    MCOErrorSendMessageIllegalAttachment,
    /** SMTP: Storage limit: message is probably too big.*/
    MCOErrorStorageLimit,
    /** SMTP: Sending message is not allowed.*/
    MCOErrorSendMessageNotAllowed,
    /** SMTP: Specific to hotmail. Needs to connect to webmail.*/
    MCOErrorNeedsConnectToWebmail,
    /** SMTP: Error while sending message.*/
    MCOErrorSendMessage, // 30
    /** SMTP: Authentication required.*/
    MCOErrorAuthenticationRequired,
    /** POP: Error occurred while fetching message list.*/
    MCOErrorFetchMessageList,
    /** POP: Error occurred while deleting message.*/
    MCOErrorDeleteMessage,
    /** SMTP: Error while checking account.*/
    MCOErrorInvalidAccount,
    /** Error when accessing/reading/writing file.*/
    MCOErrorFile,
    /** IMAP: Error when trying to enable compression.*/
    MCOErrorCompression,
    /** SMTP: Error when no sender has been specified.*/
    MCOErrorNoSender,
    /** SMTP: Error when no recipient has been specified.*/
    MCOErrorNoRecipient,
    /** IMAP: Error when a noop operation fails.*/
    MCOErrorNoop,
    /** IMAP: Error when the password has been entered but second factor
     authentication is enabled: an application specific password is required. */
    MCOErrorGmailApplicationSpecificPasswordRequired, // 40
    /** NNTP: error when requesting date */
    MCOErrorServerDate,
    /** No valid server found */
    MCOErrorNoValidServerFound,
    /** Error while running custom command */
    MCOErrorCustomCommand,
    /** Spam was suspected by server */
    MCOErrorYahooSendMessageSpamSuspected,
    /** Daily limit of sent messages was hit */
    MCOErrorYahooSendMessageDailyLimitExceeded,
    /** You need to login via the web browser first */
    MCOErrorOutlookLoginViaWebBrowser,
    /** Tiscali Simple Mail Error */
    MCOErrorTiscaliSimplePassword,
    /** The count of all errors */
    MCOErrorCodeCount,
};

@interface NSError (MCO)
#ifdef __cplusplus
+ (NSError *) mco_errorWithErrorCode:(mailcore::ErrorCode)code;
#endif
@end

#endif
