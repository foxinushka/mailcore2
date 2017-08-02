import Foundation

//public let ErrorDomain = "MailCoreErrorDomain"
//
//public class MailCoreError : Error {
//    
//    public var errorCode: UInt32;
//    public var errorMessage: String;
//    public var userInfo: Dictionary<String, Any>?
//    
//    internal init(code: ErrorCode) {
//        self.errorCode = code.rawValue;
//        //Add localization
//        self.errorMessage = "";
//    }
//
//}

@objc public enum MailCoreError : Int, Error {
    case errorNone // 0
    case errorConnection
    case errorTLSNotAvailable
    case errorParse
    case errorCertificate
    case errorAuthentication
    case errorGmailIMAPNotEnabled
    case errorGmailExceededBandwidthLimit
    case errorGmailTooManySimultaneousConnections
    case errorMobileMeMoved
    case errorYahooUnavailable // 10
    case errorNonExistantFolder
    case errorRename
    case errorDelete
    case errorCreate
    case errorSubscribe
    case errorAppend
    case errorCopy
    case errorExpunge
    case errorFetch
    case errorIdle // 20
    case errorIdentity
    case errorNamespace
    case errorStore
    case errorCapability
    case errorStartTLSNotAvailable
    case errorSendMessageIllegalAttachment
    case errorStorageLimit
    case errorSendMessageNotAllowed
    case errorNeedsConnectToWebmail
    case errorSendMessage // 30
    case errorAuthenticationRequired
    case errorFetchMessageList
    case errorDeleteMessage
    case errorInvalidAccount
    case errorFile
    case errorCompression
    case errorNoSender
    case errorNoRecipient
    case errorNoop
    case errorGmailApplicationSpecificPasswordRequired // 40
    case errorServerDate
    case errorNoValidServerFound
    case errorCustomCommand
    case errorYahooSendMessageSpamSuspected
    case errorYahooSendMessageDailyLimitExceeded
    case errorOutlookLoginViaWebBrowser
    
    internal init(code: ErrorCode) {
        self.init(rawValue: Int(code.rawValue))!
    }

}
