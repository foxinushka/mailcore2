import Foundation
import Dispatch

public class SMTPSession {
    
    var session:CSMTPSession;
    
    public init() {
        self.session = newCSMTPSession();
    }
    
    internal init(session: CSMTPSession) {
        self.session = session;
    }
    
    /** This is the hostname of the SMTP server to connect to. */
    public var hostname : String? {
        get { return String(utf16: self.session.hostname(self.session)); }
        set { newValue?.utf16({ self.session.setHostname(self.session, $0) }) }
    }
    
    /** This is the port of the SMTP server to connect to. */
    public var port : UInt32 {
        get { return self.session.port(self.session); }
        set { self.session.setPort(self.session, newValue); }
    }
    
    /** This is the username of the account. */
    public var username : String? {
        get { return String(utf16: self.session.username(self.session)); }
        set { newValue?.utf16({ self.session.setUsername(self.session, $0) }) }
    }
    
    /** This is the password of the account. */
    public var password : String? {
        get { return String(utf16: self.session.password(self.session)); }
        set { newValue?.utf16({ self.session.setPassword(self.session, $0) }) }
    }
    
    /** This is the OAuth2 token. */
    public var OAuth2Token : String? {
        get { return String(utf16: self.session.OAuth2Token(self.session)); }
        set { newValue?.utf16({ self.session.setOAuth2Token(self.session, $0) }) }
    }
    
    /**
     This is the authentication type to use to connect.
     `MCOAuthTypeSASLNone` means that it uses the clear-text is used (and is the default).
     @warning *Important*: Over an encrypted connection like TLS, the password will still be secure
     */
    public var authType : AuthType {
        get { return self.session.authType(self.session); }
        set { self.session.setAuthType(self.session, newValue); }
    }
    
    /**
     This is the encryption type to use.
     See MCOConnectionType for more information.
     */
    public var connectionType : ConnectionType {
        get { return self.session.connectionType(self.session); }
        set { self.session.setConnectionType(self.session, newValue); }
    }
    
    /** This is the timeout of the connection. */
    public var timeout : TimeInterval {
        get { return Double(self.session.timeout(self.session)); }
        set { self.session.setTimeout(self.session, time_t(newValue)); }
    }
    
    /** When set to YES, the connection will fail if the certificate is incorrect. */
    public var checkCertificateEnabled : Bool {
        get { return self.session.isCheckCertificateEnabled(self.session); }
        set { self.session.setCheckCertificateEnabled(self.session, newValue); }
    }
    
    /**
     If set to YES, when sending the EHLO or HELO command, use IP address instead of hostname.
     Default is NO.
     */
    public var useHeloIPEnabled : Bool {
        get { return self.session.useHeloIPEnabled(self.session); }
        set { self.session.setUseHeloIPEnabled(self.session, newValue); }
    }
    
    /**
     Sets logger callback. The network traffic will be sent to this block.
     
     [session setConnectionLogger:^(void * connectionID, MCOConnectionLogType type, NSData * data) {
     ...
     }];
     */
    public var connectionLogger : ConnectionLogger {
        get { return self.connectionLogger; }
        set { self.session.setConnectionLogger(self.session, newValue); }
    }
    
    /** This property provides some hints to MCOSMTPSession about where it's called from.
     It will make MCOSMTPSession safe. It will also set all the callbacks of operations to run on this given queue.
     Defaults to the main queue.
     This property should be used only if there's performance issue using MCOSMTPSession in the main thread. */
    /** The queue this operation dispatches the callback on.  Defaults to the main queue.
     This property should be used only if there's performance issue creating or calling the callback
     in the main thread. */
    public var dispatchQueue: DispatchQueue? {
        get {
            #if os(Android)
                //This property is ignored for Android
                return nil;
            #else
                return session.dispatchQueue(session);
            #endif
        }
        set {
            #if os(Android)
            #else
                session.setDispatchQueue(session, newValue);
            #endif
        }
        
    }
    
    
    /**
     The value will be YES when asynchronous operations are running, else it will return NO.
     */
    public var operationQueueRunning : Bool {
        get { return self.session.isOperationQueueRunning(self.session); }
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
        get { return self.operationQueueRunningChangeBlock; }
        set { self.session.setOperationQueueRunningChangeBlock(self.session, newValue); }
    }
    
    /**
     Cancel all operations
     */
    //- (void) cancelAllOperations;
    public func cancelAllOperations() {
        self.session.cancelAllOperations(self.session);
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
        return SMTPOperation(self.session.loginOperation(self.session));
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
        return SMTPSendOperation(self.session.sendOperationWithData(self.session, bytes, UInt32(messageData.count)));
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
        return SMTPSendOperation(self.session.sendOperationWithDataAndFromAndRecipients(self.session, bytes, UInt32(messageData.count), from.getNativeInstance(), recipients.cast()));
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
        return SMTPSendOperation(path.utf16({ self.session.sendOperationWithContentsOfFile(self.session, $0, from.getNativeInstance(), recipients.cast()) }));
    }

    
    /**
     Returns an operation that will check whether the SMTP account is valid.
     
     MCOSMTPOperation * op = [session checkAccountOperationWithFrom:[MCOAddress addressWithMailbox:@"hoa@etpan.org"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func checkAccountOperationWithFrom(from: Address) -> SMTPOperation {
        return SMTPOperation(self.session.checkAccountOperationWithFrom(self.session, from.getNativeInstance()));
    }
    
    /**
     Returns an operation that will perform a No-Op.
     
     MCOSMTPOperation * op = [session noopOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func noopOperation(from: Address) -> SMTPOperation {
        return SMTPOperation(self.session.noopOperation(self.session));
    }

}
