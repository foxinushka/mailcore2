import Foundation
import Dispatch


public class SMTPSession {
    
    var session:CSMTPSession;
    
    public init() {
        self.session = CSMTPSession();
    }
    
    internal init(session: CSMTPSession) {
        self.session = session;
    }
    
    /** This is the hostname of the SMTP server to connect to. */
    public var hostname : String? {
        get { return String(utf16: self.session.hostname) }
        set { String.utf16(newValue, { self.session.hostname = $0 }) }
    }
    
    /** This is the port of the SMTP server to connect to. */
    public var port : UInt32 {
        get { return self.session.port }
        set { self.session.port = newValue }
    }
    
    /** This is the username of the account. */
    public var username : String? {
        get { return String(utf16: self.session.username) }
        set { String.utf16(newValue, { self.session.username = $0 }) }
    }
    
    /** This is the password of the account. */
    public var password : String? {
        get { return String(utf16: self.session.password) }
        set { String.utf16(newValue, { self.session.password = $0 }) }
    }
    
    /** This is the OAuth2 token. */
    public var OAuth2Token : String? {
        get { return String(utf16: self.session.OAuth2Token) }
        set { String.utf16(newValue, { self.session.OAuth2Token = $0 }) }
    }
    
    /**
     This is the authentication type to use to connect.
     `MCOAuthTypeSASLNone` means that it uses the clear-text is used (and is the default).
     @warning *Important*: Over an encrypted connection like TLS, the password will still be secure
     */
    public var authType : AuthType {
        get { return self.session.authType }
        set { self.session.authType = newValue }
    }
    
    /**
     This is the encryption type to use.
     See MCOConnectionType for more information.
     */
    public var connectionType : ConnectionType {
        get { return self.session.connectionType }
        set { self.session.connectionType = newValue }
    }
    
    /** This is the timeout of the connection. */
    public var timeout : TimeInterval {
        get { return Double(self.session.timeout) }
        set { self.session.timeout = time_t(newValue) }
    }
    
    /** When set to YES, the connection will fail if the certificate is incorrect. */
    public var checkCertificateEnabled : Bool {
        get { return self.session.isCheckCertificateEnabled }
        set { self.session.isCheckCertificateEnabled = newValue }
    }
    
    /**
     If set to YES, when sending the EHLO or HELO command, use IP address instead of hostname.
     Default is NO.
     */
    public var useHeloIPEnabled : Bool {
        get { return self.session.useHeloIPEnabled }
        set { self.session.useHeloIPEnabled = newValue }
    }
    
    /**
     Sets logger callback. The network traffic will be sent to this block.
     
     [session setConnectionLogger:^(void * connectionID, MCOConnectionLogType type, NSData * data) {
     ...
     }];
     */
    public var connectionLogger : ConnectionLogger {
        get { return self.session.connectionLogger; }
        set { self.session.connectionLogger = newValue }
    }
    
    /** This property provides some hints to MCOSMTPSession about where it's called from.
     It will make MCOSMTPSession safe. It will also set all the callbacks of operations to run on this given queue.
     Defaults to the main queue.
     This property should be used only if there's performance issue using MCOSMTPSession in the main thread. */
    /** The queue this operation dispatches the callback on.  Defaults to the main queue.
     This property should be used only if there's performance issue creating or calling the callback
     in the main thread. */
    #if os(Android)
    public var dispatchQueue: dispatch_queue_t? {
        get {
            return session.dispatchQueue(session);
        }
        set {
            session.setDispatchQueue(session, newValue);
        }
    }
    #else
    public var dispatchQueue: DispatchQueue? {
        get {
            return self.session.dispatchQueue()
        }
        set {
            self.session.setDispatchQueue(newValue: newValue)
        }
    }
    #endif
    
    
    /**
     The value will be YES when asynchronous operations are running, else it will return NO.
     */
    public var operationQueueRunning : Bool {
        get { return self.session.isOperationQueueRunning }
    }
    
    /**
     Sets operation running callback. It will be called when operations start or stop running.
     
     [session setOperationQueueRunningChangeBlock:^{
     if ([session isOperationQueueRunning]) {
     ...
     }
     else {
     ...
     }
     }];
     */
    public var operationQueueRunningChangeBlock : OperationQueueRunningChangeBlock {
        get { return self.session.operationQueueRunningChangeBlock; }
        set { self.session.operationQueueRunningChangeBlock = newValue }
    }
    
    /**
     Cancel all operations
     */
    //- (void) cancelAllOperations;
    public func cancelAllOperations() {
        self.session.cancelAllOperations();
    }
    
    /** @name Operations */
    
    /**
     Returns an operation that will perform a login.
     
     MCOSMTPOperation * op = [session loginOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func loginOperation() -> SMTPOperation{
        return SMTPOperation(self.session.loginOperation());
    }
    
    /**
     Returns an operation that will send the given message through SMTP.
     It will use the recipient set in the message data (To, Cc and Bcc).
     It will also filter out Bcc from the content of the message.
     
     Generate RFC 822 data using MCOMessageBuilder
     
     MCOSMTPOperation * op = [session sendOperationWithData:rfc822Data];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func sendOperationWithData(messageData: Data) -> SMTPSendOperation{
        let bytes: UnsafePointer<Int8>? = messageData.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> UnsafePointer<Int8> in
            return bytes;
        }
        return SMTPSendOperation(self.session.sendOperationWithData(messageDataBytes: bytes, messageDataLenght: UInt32(messageData.count)));
    }
    
    /**
     Returns an operation that will send the given message through SMTP.
     It will use the sender and recipient set from the parameters.
     It will also filter out Bcc from the content of the message.
     
     Generate RFC 822 data using MCOMessageBuilder
     
     MCOSMTPOperation * op = [session sendOperationWithData:rfc822Data
     from:[MCOAddress addressWithMailbox:@"hoa@etpan.org"]
     recipients:[NSArray arrayWithObject:[MCOAddress addressWithMailbox:@"laura@etpan.org"]]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func sendOperationWithData(messageData: Data, from: Address, recipients: Array<Address>) -> SMTPSendOperation {
        let bytes: UnsafePointer<Int8>? = messageData.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> UnsafePointer<Int8> in
            return bytes;
        }
        return SMTPSendOperation(self.session.sendOperationWithDataAndFromAndRecipients(messageDataBytes: bytes, messageDataLenght: UInt32(messageData.count), from: from.getNativeInstance(), recipients: recipients.cast()));
    }
    
    
    /**
     Returns an operation that will send the message from the given file through SMTP.
     It will use the sender and recipient set from the parameters.
     It will also filter out Bcc from the content of the message.
     
     MCOSMTPOperation * op = [session sendOperationWithContentsOfFile:rfc822DataFilename
     from:[MCOAddress addressWithMailbox:@"hoa@etpan.org"]
     recipients:[NSArray arrayWithObject:
     [MCOAddress addressWithMailbox:@"laura@etpan.org"]]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func sendOperationWithContentsOfFile(path: String, from: Address, recipients: Array<Address>) -> SMTPSendOperation {
        return SMTPSendOperation(String.utf16(path, { self.session.sendOperationWithContentsOfFile(path: $0, from: from.getNativeInstance(), recipients: recipients.cast()) }));
    }

    
    /**
     Returns an operation that will check whether the SMTP account is valid.
     
     MCOSMTPOperation * op = [session checkAccountOperationWithFrom:[MCOAddress addressWithMailbox:@"hoa@etpan.org"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func checkAccountOperationWithFrom(from: Address) -> SMTPOperation {
        return SMTPOperation(self.session.checkAccountOperationWithFrom(from: from.getNativeInstance()));
    }
    
    /**
     Returns an operation that will perform a No-Op.
     
     MCOSMTPOperation * op = [session noopOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func noopOperation(from: Address) -> SMTPOperation {
        return SMTPOperation(self.session.noopOperation());
    }

}
