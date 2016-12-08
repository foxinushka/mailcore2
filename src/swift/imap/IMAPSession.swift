import Foundation
import Dispatch

/**
 This is the main IMAP class from which all operations are created
 
 After calling a method that returns an operation you must call start: on the instance
 to begin the operation.
 */
public class IMAPSession {
	
	internal var session:CIMAPAsyncSession;

	public init() {
 		session = newCIMAPAsyncSession();
	}
    
    deinit {
        deleteCIMAPAsyncSession(session);
    }
    
    /** This is the hostname of the IMAP server to connect to. */
    public var hostname: String? {
        get { return String(utf16: session.hostname(session)); }
        set { newValue?.utf16({ session.setHostname(session, $0) }) }
    }
    
    /** This is the port of the IMAP server to connect to. */
    public var port: UInt32 {
        get { return session.port(session); }
        set { session.setPort(session, newValue); }
    }
    
    /** This is the username of the account. */
    public var username: String? {
        get { return String(utf16: session.username(session)); }
        set { newValue?.utf16({ session.setUsername(session, $0) }) }
    }
    
    /** This is the password of the account. */
    public var password: String? {
        get { return String(utf16: session.password(session)); }
        set { newValue?.utf16({ session.setPassword(session, $0) }) }
    }
    
    /** This is the OAuth2 token. */
    public var OAuth2Token: String? {
        get { return String(utf16: session.OAuth2Token(session)); }
        set { newValue?.utf16({ session.setOAuth2Token(session, $0) }) }
    }
    
    /**
     This is the authentication type to use to connect.
     `MCOAuthTypeSASLNone` means that it uses the clear-text is used (and is the default).
     @warning *Important*: Over an encrypted connection like TLS, the password will still be secure
     */
    public var authType: AuthType {
        get { return session.authType(session); }
        set { session.setAuthType(session, newValue); }
    }
    
    /**
     This is the encryption type to use.
     See MCOConnectionType for more information.
     */
    public var connectionType: ConnectionType {
        get { return session.connectionType(session); }
        set { session.setConnectionType(session, newValue); }
    }
    
    /** This is the timeout of the connection. */
    public var timeout: TimeInterval {
        get { return Double(session.timeout(session)); }
        set { session.setTimeout(session, time_t(newValue)); }
    }
    
    /** When set to YES, the connection will fail if the certificate is incorrect. */
    public var checkCertificateEnabled: Bool {
        get { return session.isCheckCertificateEnabled(session); }
        set { session.setCheckCertificateEnabled(session, newValue); }
    }
    
    /** The default namespace. */
    public var defaultNamespace: IMAPNamespace? {
        get { return IMAPNamespace(namespace: session.defaultNamespace(session)); }
        set { session.setDefaultNamespace(session, (newValue?.CIMAPNamespace())!); }
    }
    
    /**
     When set to YES, the session is allowed open to open several connections to the same folder.
     @warning Some older IMAP servers don't like this
     */
    public var allowsFolderConcurrentAccessEnabled: Bool {
        get { return session.allowsFolderConcurrentAccessEnabled(session); }
        set { session.setAllowsFolderConcurrentAccessEnabled(session, newValue); }
    }
    
    /**
     Maximum number of connections to the server allowed.
     */
    public var maximumConnections: UInt32 {
        get { return session.maximumConnections(session); }
        set { session.setMaximumConnections(session, newValue); }
    }
    
    /**
     Sets logger callback. The network traffic will be sent to this block.
     
     [session setConnectionLogger:^(void * connectionID, MCOConnectionLogType type, NSData * data) {
     NSLog(@"%@", [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease]);
     // ...
     }];
     */
    public var connectionLogger : ConnectionLogger {
        get { return self.connectionLogger; }
        set { self.session.setConnectionLogger(self.session, newValue); }
    }
    
    /** This property provides some hints to MCOIMAPSession about where it's called from.
     It will make MCOIMAPSession safe. It will also set all the callbacks of operations to run on this given queue.
     Defaults to the main queue.
     This property should be used only if there's performance issue using MCOIMAPSession in the main thread. */
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
    
    public var isVoIPEnabled: Bool {
        get { return session.isVoIPEnabled(session) }
    }
    
    public var isIdleEnabled: Bool {
        get { return session.isIdleEnabled(session) }
    }
    
    public var isOperationQueueRunning: Bool {
        get { return session.isOperationQueueRunning(session) }
    }
    
    /**
     Cancel all operations
     */
    public func cancelAllOperations() {
        session.cancelAllOperations(session)
    }
    
    /**
     Returns an operation that gets the list of subscribed folders.
     
     MCOIMAPFetchFoldersOperation * op = [session fetchSubscribedFoldersOperation];
     [op start:^(NSError * __nullable error, NSArray * folders) {
     ...
     }];
     */
    
    public func fetchSubscribedFoldersOperation() -> IMAPFetchFoldersOperation {
        return IMAPFetchFoldersOperation.init(operation: session.fetchSubscribedFoldersOperation(session))
    }
    
    /**
     Creates an operation for renaming a folder
     
     MCOIMAPOperation * op = [session renameFolderOperation:@"my documents" otherName:@"Documents"];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     
     */
    public func renameFolderOperation(folder: String, otherName: String) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ folderPtr in
            otherName.utf16({ otherNamePtr in
                session.renameFolderOperation(session, folderPtr, otherNamePtr)
            })
        }))
    }

    /**
     Returns an operation to disconnect the session.
     It will disconnect all the sockets created by the session.
     
     MCOIMAPOperation * op = [session disconnectOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func disconnectOperation() -> IMAPOperation {
    	return IMAPOperation(operation: session.disconnectOperation(session))
    }
    
    /**
     Returns an operation that will connect to the given IMAP server without authenticating.
     Useful for checking initial server capabilities.
     
     MCOIMAPOperation * op = [session connectOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func connectOperation() -> IMAPOperation {
        return IMAPOperation.init(operation: session.connectOperation(session))
    }

    /**
     Returns an operation that will perform a No-Op operation on the given IMAP server.
     
     MCOIMAPOperation * op = [session noopOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func noopOperation() -> IMAPOperation {
    	return IMAPOperation(operation: session.noopOperation(session))
    }

    /**
     Returns an operation that will check whether the IMAP account is valid.
     
     MCOIMAPOperation * op = [session checkAccountOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func checkAccountOperation() -> IMAPCheckAccountOperation {
    	return IMAPCheckAccountOperation(operation: session.checkAccountOperation(session))
    }

    /**
     Returns an operation to request capabilities of the server.
     See MCOIMAPCapability for the list of capabilities.
     
     canIdle = NO;
     MCOIMAPCapabilityOperation * op = [session capabilityOperation];
     [op start:^(NSError * __nullable error, MCOIndexSet * capabilities) {
     if ([capabilities containsIndex:MCOIMAPCapabilityIdle]) {
     canIdle = YES;
     }
     }];
     */
    public func capabilityOperation() -> IMAPCapabilityOperation {
    	return IMAPCapabilityOperation(operation: session.capabilityOperation(session))
    }
    
    public func quotaOperation() -> IMAPQuotaOperation {
        return IMAPQuotaOperation(operation: session.quotaOperation(session))
    }
    
    /**
     Returns an operation that gets all folders
     
     MCOIMAPFetchFoldersOperation * op = [session fetchAllFoldersOperation];
     [op start:^(NSError * __nullable error, NSArray *folders) {
     ...
     }];
     */
    public func fetchAllFoldersOperation() -> IMAPFetchFoldersOperation {
    	return IMAPFetchFoldersOperation(operation: session.fetchAllFoldersOperation(session))
    }
    
    /**
     Returns an operation to expunge a folder.
     
     MCOIMAPOperation * op = [session expungeOperation:@"INBOX"];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func expungeOperation(folder:String) -> IMAPOperation {
        return IMAPOperation(operation: folder.utf16({ session.expungeOperation(session, $0) }))
    }

    /**
     Returns an operation that creates a new folder
     
     MCOIMAPOperation * op = [session createFolderOperation:@"holidays 2013"];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func createFolderOperation(folder:String) -> IMAPOperation {
        return IMAPOperation(operation: folder.utf16({ session.createFolderOperation(session, $0) }))
    }
    
    /**
     Returns an operation to subscribe to a folder.
     
     MCOIMAPOperation * op = [session createFolderOperation:@"holidays 2013"];
     [op start:^(NSError * __nullable error) {
     if (error != nil)
     return;
     MCOIMAPOperation * op = [session subscribeFolderOperation:@"holidays 2013"];
     ...
     }];
     */
    public func subscribeFolderOperation(folder: String) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.subscribeFolderOperation(session, $0) }))
    }
    
    /**
     Returns an operation to unsubscribe from a folder.
     
     MCOIMAPOperation * op = [session unsubscribeFolderOperation:@"holidays 2009"];
     [op start:^(NSError * __nullable error) {
     if (error != nil)
     return;
     MCOIMAPOperation * op = [session deleteFolderOperation:@"holidays 2009"]
     ...
     }];
     */
    public func unsubscribeFolderOperation(folder: String) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.unsubscribeFolderOperation(session, $0) }))
    }

    /**
     Returns an operation to unsubscribe from a folder.
     
     MCOIMAPOperation * op = [session unsubscribeFolderOperation:@"holidays 2009"];
     [op start:^(NSError * __nullable error) {
     if (error != nil)
     return;
     MCOIMAPOperation * op = [session deleteFolderOperation:@"holidays 2009"]
     ...
     }];
     */
    public func deleteFolderOperation(folder:String) -> IMAPOperation {
        return IMAPOperation(operation: folder.utf16({ session.deleteFolderOperation(session, $0) }))
    }

    public func storeFlagsByUIDOperation(folder:String, uids:IndexSet, kind:IMAPStoreFlagsRequestKind, flags:MessageFlag, customFlags:Array<String>) -> IMAPOperation {
        return IMAPOperation(operation: folder.utf16({ session.storeFlagsByUIDOperation(session, $0, uids.cast(), kind, flags, Array<String>.cast(customFlags)) }));
    }
    
    /**
     Returns an operation to change flags of messages.
     
     For example: Adds the seen flag to the message with UID 456.
     
     MCOIMAPOperation * op = [session storeFlagsOperationWithFolder:@"INBOX"
     uids:[MCOIndexSet indexSetWithIndex:456]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     flags:MCOMessageFlagSeen];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeFlagsOperation(folder: String, uids: IndexSet, kind: IMAPStoreFlagsRequestKind, flags: MessageFlag) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.storeFlagsByUIDOperation(session, $0, uids.nativeInstance, kind, flags, newCArray()) }))
    }
    
    /**
     Returns an operation to change flags of messages, using IMAP sequence number.
     
     For example: Adds the seen flag to the message with the sequence number number 42.
     
     MCOIMAPOperation * op = [session storeFlagsOperationWithFolder:@"INBOX"
     numbers:[MCOIndexSet indexSetWithIndex:42]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     flags:MCOMessageFlagSeen];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeFlagsOperation(folder: String, numbers: IndexSet, kind: IMAPStoreFlagsRequestKind, flags: MessageFlag) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.storeFlagsByNumberOperation(session, $0, numbers.nativeInstance, kind, flags, newCArray()) }))
    }
    
    /**
     Returns an operation to change flags and custom flags of messages.
     
     For example: Adds the seen flag and $CNS-Greeting-On flag to the message with UID 456.
     
     MCOIMAPOperation * op = [session storeFlagsOperationWithFolder:@"INBOX"
     uids:[MCOIndexSet indexSetWithIndex:456]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     flags:MCOMessageFlagSeen
     customFlags:@["$CNS-Greeting-On"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeFlagsOperation(folder: String, uids: IndexSet, kind: IMAPStoreFlagsRequestKind, flags: MessageFlag, customFlags: Array<String>) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.storeFlagsByUIDOperation(session, $0, uids.nativeInstance, kind, flags, customFlags.cast()) }))
    }
    
    /**
     Returns an operation to change flags and custom flags of messages, using IMAP sequence number.
     
     For example: Adds the seen flag and $CNS-Greeting-On flag to the message with the sequence number 42.
     
     MCOIMAPOperation * op = [session storeFlagsOperationWithFolder:@"INBOX"
     numbers:[MCOIndexSet indexSetWithIndex:42]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     flags:MCOMessageFlagSeen
     customFlags:@["$CNS-Greeting-On"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeFlagsOperation(folder: String, numbers: IndexSet, kind: IMAPStoreFlagsRequestKind, flags: MessageFlag, customFlags: Array<String>) -> IMAPOperation {
        return IMAPOperation.init(operation: folder.utf16({ session.storeFlagsByNumberOperation(session, $0, numbers.nativeInstance, kind, flags, customFlags.cast()) }))
    }
    
    /**
     Returns an operation to change labels of messages. Intended for Gmail
     
     For example: Adds the label "Home" flag to the message with UID 42.
     
     MCOIMAPOperation * op = [session storeLabelsOperationWithFolder:@"INBOX"
     numbers:[MCOIndexSet indexSetWithIndex:42]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     labels:[NSArray arrayWithObject:@"Home"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeLabelsOperation(foler: String, numbers: IndexSet, kind: IMAPStoreFlagsRequestKind, labels: Array<String>) -> IMAPOperation {
        return IMAPOperation.init(operation: foler.utf16({ session.storeLabelsByNumberOperation(session, $0, numbers.nativeInstance, kind, labels.cast()) }))
    }
    
    /**
     Returns an operation to change labels of messages. Intended for Gmail
     
     For example: Adds the label "Home" flag to the message with UID 456.
     
     MCOIMAPOperation * op = [session storeLabelsOperationWithFolder:@"INBOX"
     uids:[MCOIndexSet indexSetWithIndex:456]
     kind:MCOIMAPStoreFlagsRequestKindAdd
     labels:[NSArray arrayWithObject:@"Home"]];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func storeLabelsOperation(foler: String, uids: IndexSet, kind: IMAPStoreFlagsRequestKind, labels: Array<String>) -> IMAPOperation {
        return IMAPOperation.init(operation: foler.utf16({ session.storeLabelsByUIDOperation(session, $0, uids.nativeInstance, kind, labels.cast()) }))
    }
    
    /**
     Returns an operation to add a message to a folder.
     
     MCOIMAPOperation * op = [session appendMessageOperationWithFolder:@"Sent Mail" messageData:rfc822Data flags:MCOMessageFlagNone];
     [op start:^(NSError * __nullable error, uint32_t createdUID) {
     if (error == nil) {
     NSLog(@"created message with UID %lu", (unsigned long) createdUID);
     }
     }];
     */
    public func appendMessageOperation(folder: String, messageData: Data, flags: MessageFlag) -> IMAPAppendMessageOperation {
        return IMAPAppendMessageOperation.init(operation: folder.utf16({ session.appendMessageOperationWithData(session, $0, newCData(messageData.bytes(), messageData.length()), flags, newCArray()) }))
    }
    
    /**
     Returns an operation to add a message with custom flags to a folder.
     
     MCOIMAPOperation * op = [session appendMessageOperationWithFolder:@"Sent Mail" messageData:rfc822Data flags:MCOMessageFlagNone customFlags:@[@"$CNS-Greeting-On"]];
     [op start:^(NSError * __nullable error, uint32_t createdUID) {
     if (error == nil) {
     NSLog(@"created message with UID %lu", (unsigned long) createdUID);
     }
     }];
     */
    public func appendMessageOperation(folder: String, messageData: Data, flags: MessageFlag, customFlags:Array<String>) -> IMAPAppendMessageOperation {
        return IMAPAppendMessageOperation.init(operation: folder.utf16({
            session.appendMessageOperationWithData(session, $0, newCData(messageData.bytes(), messageData.length()), flags, Array<String>.cast(customFlags))
        }))
    }

    /**
     Returns an operation to add a message to a folder.
     
     MCOIMAPOperation * op = [session appendMessageOperationWithFolder:@"Sent Mail" messageData:rfc822Data flags:MCOMessageFlagNone];
     [op start:^(NSError * __nullable error, uint32_t createdUID) {
     if (error == nil) {
     NSLog(@"created message with UID %lu", (unsigned long) createdUID);
     }
     }];
     */
    public func appendMessageOperation(folder:String, path:String, flags:MessageFlag, customFlags:Array<String>) -> IMAPAppendMessageOperation {
        return IMAPAppendMessageOperation(operation: folder.utf16({ folderPtr in
            path.utf16({ pathPtr in
                session.appendMessageOperation(session, folderPtr, pathPtr, flags, Array<String>.cast(customFlags))
            })
        }));
    }

    /**
     Returns an operation to fetch messages by (sequence) number.
     For example: show 50 most recent uids.
     NSString *folder = @"INBOX";
     MCOIMAPFolderInfoOperation *folderInfo = [session folderInfoOperation:folder];
     
     [folderInfo start:^(NSError *error, MCOIMAPFolderInfo *info) {
     int numberOfMessages = 50;
     numberOfMessages -= 1;
     MCOIndexSet *numbers = [MCOIndexSet indexSetWithRange:MCORangeMake([info messageCount] - numberOfMessages, numberOfMessages)];
     
     MCOIMAPFetchMessagesOperation *fetchOperation = [session fetchMessagesByNumberOperationWithFolder:folder
     requestKind:MCOIMAPMessagesRequestKindUid
     numbers:numbers];
     
     [fetchOperation start:^(NSError *error, NSArray *messages, MCOIndexSet *vanishedMessages) {
     for (MCOIMAPMessage * message in messages) {
     NSLog(@"%u", [message uid]);
     }
     }];
     }];
     */
    public func fetchMessagesByNumber(folder:String, type:IMAPMessagesRequestKind, numbers:IndexSet) -> IMAPFetchMessagesOperation {
        return IMAPFetchMessagesOperation(operation: folder.utf16({ session.fetchMessagesByNumberOperation(session, $0, type, numbers.cast()) }));
    }

    /**
     Returns an operation to fetch messages by (sequence) number.
     For example: show 50 most recent uids.
     NSString *folder = @"INBOX";
     MCOIMAPFolderInfoOperation *folderInfo = [session folderInfoOperation:folder];
     
     [folderInfo start:^(NSError *error, MCOIMAPFolderInfo *info) {
     int numberOfMessages = 50;
     numberOfMessages -= 1;
     MCOIndexSet *numbers = [MCOIndexSet indexSetWithRange:MCORangeMake([info messageCount] - numberOfMessages, numberOfMessages)];
     
     MCOIMAPFetchMessagesOperation *fetchOperation = [session fetchMessagesByNumberOperationWithFolder:folder
     requestKind:MCOIMAPMessagesRequestKindUid
     numbers:numbers];
     
     [fetchOperation start:^(NSError *error, NSArray *messages, MCOIndexSet *vanishedMessages) {
     for (MCOIMAPMessage * message in messages) {
     NSLog(@"%u", [message uid]);
     }
     }];
     }];
     */
    public func fetchMessagesOperation(folder:String, kind:IMAPMessagesRequestKind, numbers:IndexSet) -> IMAPFetchMessagesOperation {
        return IMAPFetchMessagesOperation(operation: folder.utf16({ session.fetchMessagesByUIDOperation(session, $0, kind, numbers.cast()) }));
    }

    /**
     Returns an operation to sync the last changes related to the given message list given a modSeq.
     
     MCOIMAPFetchMessagesOperation * op = [session syncMessagesByUIDWithFolder:@"INBOX"
     requestKind:MCOIMAPMessagesRequestKindUID
     uids:MCORangeMake(1, UINT64_MAX)
     modSeq:lastModSeq];
     [op start:^(NSError * __nullable error, NSArray * messages, MCOIndexSet * vanishedMessages) {
     NSLog(@"added or modified messages: %@", messages);
     NSLog(@"deleted messages: %@", vanishedMessages);
     }];
     
     @warn *Important*: This is only for servers that support Conditional Store. See [RFC4551](http://tools.ietf.org/html/rfc4551)
     vanishedMessages will be set only for servers that support QRESYNC. See [RFC5162](http://tools.ietf.org/html/rfc5162)
     */
    public func syncMessages(folder:String, kind:IMAPMessagesRequestKind, uids:IndexSet, modSeq:UInt64) -> IMAPFetchMessagesOperation {
        return IMAPFetchMessagesOperation(operation: folder.utf16({ session.syncMessagesByUIDOperation(session, $0, kind, uids.cast(), modSeq) }));
    }

    /**
     Returns an operation to fetch the content of a message.
     @param urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageOperationWithFolder:@"INBOX" uid:456 urgent:NO];
     [op start:^(NSError * __nullable error, NSData * messageData) {
     MCOMessageParser * parser = [MCOMessageParser messageParserWithData:messageData]
     ...
     }];
     */
    public func fetchMessageOperation(folder:String, uid:UInt32, urgent:Bool) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ session.fetchMessageByUIDOperation(session, $0, uid, urgent) }));
    }
    
    /**
     Returns an operation to fetch the content of a message.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageOperationWithFolder:@"INBOX" uid:456];
     [op start:^(NSError * __nullable error, NSData * messageData) {
     MCOMessageParser * parser = [MCOMessageParser messageParserWithData:messageData]
     ...
     }];
     */
    public func fetchMessageOperation(folder: String, uid: UInt32) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation.init(operation: folder.utf16({ session.fetchMessageByUIDOperation(session, $0, uid, false) }))
    }
    
    /**
     Returns an operation to fetch the content of a message, using IMAP sequence number.
     @param urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageOperationWithFolder:@"INBOX" number:42 urgent:NO];
     [op start:^(NSError * __nullable error, NSData * messageData) {
     MCOMessageParser * parser = [MCOMessageParser messageParserWithData:messageData]
     ...
     }];
     */
    public func fetchMessageOperation(folder:String, number:UInt32, urgent:Bool) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ session.fetchMessageByUIDOperation(session, $0, number, urgent) }));
    }
    
    /**
     Returns an operation to fetch the content of a message, using IMAP sequence number.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageOperationWithFolder:@"INBOX" number:42];
     [op start:^(NSError * __nullable error, NSData * messageData) {
     MCOMessageParser * parser = [MCOMessageParser messageParserWithData:messageData]
     ...
     }];
     */
    public func fetchMessageOperation(folder:String, number:UInt32) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ session.fetchMessageByUIDOperation(session, $0, number, false) }));
    }

    /**
     Returns an operation to fetch an attachment.
     @param  urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     uid:456
     partID:@"1.2"
     encoding:MCOEncodingBase64
     urgent:YES];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     */
    public func fetchMessageAttachmentOperation(folder:String, uid:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ folderPtr in
            partId.utf16({ partIdPtr in
                session.fetchMessageAttachmentByUIDOperation(session, folderPtr, uid, partIdPtr, encoding, urgent)
            })
        }))
    }
    
    
    /**
     Returns an operation to fetch an attachment.
     
     Example 1:
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     uid:456
     partID:@"1.2"
     encoding:MCOEncodingBase64];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     
     Example 2:
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     uid:[message uid]
     partID:[part partID]
     encoding:[part encoding]];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     */
    public func fetchMessageAttachmentOperation(folder: String, uid: UInt32, partID: String, encoding: Encoding) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation.init(operation: folder.utf16({ folderPtr in
            partID.utf16({ partIDPtr in
                session.fetchMessageAttachmentByUIDOperation(session, folderPtr, uid, partIDPtr, encoding, false)
            })
        }))
    }
    
    /**
     Returns an operation to fetch an attachment.
     @param  urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     uid:456
     partID:@"1.2"
     encoding:MCOEncodingBase64
     urgent:YES];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     */
    public func fetchMessageAttachmentOperation(folder:String, number:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ folderPtr in
            partId.utf16({ partIdPtr in
                session.fetchMessageAttachmentByNumberOperation(session, folderPtr, number, partIdPtr, encoding, urgent)
            })
        }))
    }
    
    /**
     Returns an operation to fetch an attachment.
     
     Example 1:
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     number:42
     partID:@"1.2"
     encoding:MCOEncodingBase64];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     
     Example 2:
     
     MCOIMAPFetchContentOperation * op = [session fetchMessageAttachmentOperationWithFolder:@"INBOX"
     number:[message sequenceNumber]
     partID:[part partID]
     encoding:[part encoding]];
     [op start:^(NSError * __nullable error, NSData * partData) {
     ...
     }];
     */
    public func fetchMessageAttachmentOperation(folder:String, number:UInt32, partId:String, encoding:Encoding) -> IMAPFetchContentOperation {
        return IMAPFetchContentOperation(operation: folder.utf16({ folderPtr in
            partId.utf16({ partIdPtr in
                session.fetchMessageAttachmentByNumberOperation(session, folderPtr, number, partIdPtr, encoding, false)
            })
        }))
    }

    /**
     Returns an operation to search for messages.
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchOperation * op = [session searchExpressionOperationWithFolder:@"INBOX"
     expression:expr];
     [op start:^(NSError * __nullable error, MCOIndexSet * searchResult) {
     ...
     }];
     */
    public func searchExpressionOperation(folder:String, expression:IMAPSearchExpression) -> IMAPSearchOperation {
        return IMAPSearchOperation(operation: folder.utf16({ session.searchOperationWithExpression(session, $0, expression.cast()) }));
    }

    /**
     Returns an operation to search for messages.
     
     MCOIMAPSearchExpression * expr = [MCOIMAPSearchExpression searchFrom:@"laura@etpan.org"]
     MCOIMAPSearchOperation * op = [session searchExpressionOperationWithFolder:@"INBOX"
     expression:expr];
     [op start:^(NSError * __nullable error, MCOIndexSet * searchResult) {
     ...
     }];
     */
    public func searchOperation(folder:String, kind:IMAPSearchKind, searchString:String) -> IMAPSearchOperation {
        return IMAPSearchOperation(operation: folder.utf16({ folderPtr in
            searchString.utf16({ searchStringPtr in
                session.searchOperation(session, folderPtr, kind, searchStringPtr)
            })
        }))
    }

    /**
     Returns an operation to copy messages to a folder.
     
     MCOIMAPCopyMessagesOperation * op = [session copyMessagesOperationWithFolder:@"INBOX"
     uids:[MCIndexSet indexSetWithIndex:456]
     destFolder:@"Cocoa"];
     [op start:^(NSError * __nullable error, NSDictionary * uidMapping) {
     NSLog(@"copied to folder with UID mapping %@", uidMapping);
     }];
     */
    public func copyMessagesOperation(folder:String, uids:IndexSet, destFolder:String) -> IMAPCopyMessagesOperation {
        return IMAPCopyMessagesOperation(operation: folder.utf16({ folderPtr in
            destFolder.utf16({ destFolderPtr in
                 session.copyMessagesOperation(session, folderPtr, uids.cast(), destFolderPtr)
            })
        }))
    }

    /**
     Returns an operation that retrieves folder metadata (like UIDNext)
     
     MCOIMAPFolderInfoOperation * op = [session folderInfoOperation:@"INBOX"];
     [op start:^(NSError *error, MCOIMAPFolderInfo * info) {
     NSLog(@"UIDNEXT: %lu", (unsigned long) [info uidNext]);
     NSLog(@"UIDVALIDITY: %lu", (unsigned long) [info uidValidity]);
     NSLog(@"HIGHESTMODSEQ: %llu", (unsigned long long) [info modSequenceValue]);
     NSLog(@"messages count: %lu", [info messageCount]);
     }];
     */
    public func folderInfoOperation(folder:String) -> IMAPFolderInfoOperation {
        return IMAPFolderInfoOperation(operation: folder.utf16({ session.folderInfoOperation(session, $0) }));
    }

    /**
     Returns an operation that retrieves folder status (like UIDNext - Unseen -)
     
     MCOIMAPFolderStatusOperation * op = [session folderStatusOperation:@"INBOX"];
     [op start:^(NSError *error, MCOIMAPFolderStatus * info) {
     NSLog(@"UIDNEXT: %lu", (unsigned long) [info uidNext]);
     NSLog(@"UIDVALIDITY: %lu", (unsigned long) [info uidValidity]);
     NSLog(@"messages count: %lu", [info totalMessages]);
     }];
     */
    public func folderStatusOperation(folder:String) -> IMAPFolderStatusOperation {
        return IMAPFolderStatusOperation(operation: folder.utf16({ session.folderStatusOperation(session, $0) }));
    }
    
    /**
     Returns an operation to wait for something to happen in the folder.
     See [RFC2177](http://tools.ietf.org/html/rfc2177) for me info.
     
     MCOIMAPIdleOperation * op = [session idleOperationWithFolder:@"INBOX"
     lastKnownUID:0];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func idleOperation(folder:String, lastKnownUID:UInt32) -> IMAPIdleOperation {
        return IMAPIdleOperation(idleOperation: folder.utf16({ session.idleOperation(session, $0, lastKnownUID) }));
    }
    
    /**
     Returns an operation for custom command.
     @param command is the text representation of the command to be send.
     
     
     MCOIMAPCustomCommandOperation * op = [session customCommandOperation:@"ACTIVATE SERVICE"];
     [op start: ^(NSString * __nullable response, NSError * __nullable error) {
     ...
     }];
     */
    public func customCommandOperation(_ command: String) -> IMAPCustomCommandOperation {
        return IMAPCustomCommandOperation.init(operation: command.utf16({ session.customCommandOperation(session, $0) }))
    }
    
    /**
     Returns an operation to fetch an attachment to a file.
     @param  urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     Operation will be perform in a memory efficient manner.
     
     MCOIMAPFetchContentToFileOperation * op = [session fetchMessageAttachmentToFileOperationWithFolder:@"INBOX"
     uid:456
     partID:@"1.2"
     encoding:MCOEncodingBase64
     filename:filename
     urgent:YES];
     
     // Optionally, explicitly enable chunked mode
     [op setLoadingByChunksEnabled:YES];
     [op setChunksSize:1024*1024];
     // need in chunked mode for correct progress indication
     [op setEstimatedSize:sizeOfAttachFromBodystructure];
     
     [op start:^(NSError * __nullable error) {
     ...
     }];
     
     */
    func fetchMessageAttachmentToFileOperation(folder: String, uid: UInt32, partID: String, encoding: Encoding, filename:String, urgent: Bool) -> IMAPFetchContentToFileOperation {
        return IMAPFetchContentToFileOperation(operation:  folder.utf16({ folderPtr in
            partID.utf16({ partIDPtr  in
                filename.utf16({ filenamePtr in
                    session.fetchMessageAttachmentToFileOperation(session, folderPtr, uid, partIDPtr, encoding, filenamePtr, urgent)
                })
            })
        }))
    }
    
    /**
     Returns an operation to fetch the list of namespaces.
     
     MCOIMAPFetchNamespaceOperation * op = [session fetchNamespaceOperation];
     [op start:^(NSError * __nullable error, NSDictionary * namespaces) {
     if (error != nil)
     return;
     MCOIMAPNamespace * ns = [namespace objectForKey:MCOIMAPNamespacePersonal];
     NSString * path = [ns pathForComponents:[NSArray arrayWithObject:]];
     MCOIMAPOperation * createOp = [session createFolderOperation:foobar];
     [createOp start:^(NSError * __nullable error) {
     ...
     }];
     }];
     */
    public func fetchNamespaceOperation() -> IMAPFetchNamespaceOperation {
        return IMAPFetchNamespaceOperation(operation: session.fetchNamespace(session))
    }
    
    /**
     Returns an operation to move messages to a folder.
     
     MCOIMAPMoveMessagesOperation * op = [session moveMessagesOperationWithFolder:@"INBOX"
     uids:[MCIndexSet indexSetWithIndex:456]
     destFolder:@"Cocoa"];
     [op start:^(NSError * __nullable error, NSDictionary * uidMapping) {
     NSLog(@"moved to folder with UID mapping %@", uidMapping);
     }];
     */
    public func moveMessagesOperation(folder: String, uids: IndexSet, destFolder: String) -> IMAPMoveMessagesOperation {
        return IMAPMoveMessagesOperation.init(operation: folder.utf16({ folderPtr in
            destFolder.utf16({ destFolderPtr in
                session.moveMessagesOperation(session, folderPtr, uids.nativeInstance, destFolderPtr)
            })
        }))
    }
    
    /**
     Returns an operation to fetch the parsed content of a message.
     @param urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchParsedContentOperation * op = [session fetchParsedMessageOperationWithFolder:@"INBOX" uid:456 urgent:NO];
     [op start:^(NSError * __nullable error, MCOMessageParser * parser) {
     
     ...
     }];
     */
    public func fetchParsedMessageOperation(folder: String, uid: UInt32, urgent: Bool) -> IMAPFetchParsedContentOperation {
        return IMAPFetchParsedContentOperation.init(operation: folder.utf16({ session.fetchParsedMessageOperationByUIDOperation(session, $0, uid, urgent) }))
    }
    
    /**
     Returns an operation to fetch the parsed content of a message.
     
     MCOIMAPFetchParsedContentOperation * op = [session fetchParsedMessageOperationWithFolder:@"INBOX" uid:456];
     [op start:^(NSError * __nullable error, MCOMessageParser * parser) {
     
     ...
     }];
     */
    public func fetchParsedMessageOperation(folder: String, uid: UInt32) -> IMAPFetchParsedContentOperation {
        return IMAPFetchParsedContentOperation.init(operation: folder.utf16({ session.fetchParsedMessageOperationByUIDOperation(session, $0, uid, false) }))
    }
    
    /**
     Returns an operation to fetch the parsed content of a message, using IMAP sequence number.
     @param urgent is set to YES, an additional connection to the same folder might be opened to fetch the content.
     
     MCOIMAPFetchParsedContentOperation * op = [session fetchParsedMessageOperationWithFolder:@"INBOX" number:42 urgent:NO];
     [op start:^(NSError * __nullable error, MCOMessageParser * parser) {
     
     ...
     }];
     */
    public func fetchParsedMessageOperation(folder: String, number: UInt32, urgent: Bool) -> IMAPFetchParsedContentOperation {
        return IMAPFetchParsedContentOperation.init(operation: folder.utf16({ session.fetchParsedMessageOperationByNumberOperation(session, $0, number, urgent) }))
    }
    
    /**
     Returns an operation to fetch the parsed content of a message, using IMAP sequence number.
     
     MCOIMAPFetchParsedContentOperation * op = [session fetchParsedMessageOperationWithFolder:@"INBOX" number:42];
     [op start:^(NSError * __nullable error, MCOMessageParser * parser) {
     
     ...
     }];
     */
    public func fetchParsedMessageOperation(folder: String, number: UInt32) -> IMAPFetchParsedContentOperation {
        return IMAPFetchParsedContentOperation.init(operation: folder.utf16({ session.fetchParsedMessageOperationByNumberOperation(session, $0, number, false) }))
    }
    
    /**
     Returns an operation to render the HTML version of a message to be displayed in a web view.
     
     MCOIMAPMessageRenderingOperation * op = [session htmlRenderingOperationWithMessage:msg
     folder:@"INBOX"];
     
     [op start:^(NSString * htmlString, NSError * error) {
     ...
     }];
     */
    public func htmlRenderingOperation(message: IMAPMessage, folder: String) -> IMAPMessageRenderingOperation {
        return IMAPMessageRenderingOperation.init(operation: folder.utf16({ session.htmlRenderingOperation(session, message.nativeInstance, $0) }))
    }
    
    /**
     Returns an operation to render the HTML body of a message to be displayed in a web view.
     
     MCOIMAPMessageRenderingOperation * op = [session htmlBodyRenderingOperationWithMessage:msg
     folder:@"INBOX"];
     
     [op start:^(NSString * htmlString, NSError * error) {
     ...
     }];
     */
    public func htmlBodyRenderingOperation(message: IMAPMessage, folder: String) -> IMAPMessageRenderingOperation {
        return IMAPMessageRenderingOperation.init(operation: folder.utf16({ session.htmlBodyRenderingOperation(session, message.nativeInstance, $0) }))
    }
    
    /**
     Returns an operation to render the plain text version of a message.
     
     MCOIMAPMessageRenderingOperation * op = [session plainTextRenderingOperationWithMessage:msg
     folder:@"INBOX"];
     
     [op start:^(NSString * htmlString, NSError * error) {
     ...
     }];
     */
    public func plainTextRenderingOperation(message: IMAPMessage, folder: String) -> IMAPMessageRenderingOperation {
        return IMAPMessageRenderingOperation.init(operation: folder.utf16({ session.plainTextRenderingOperation(session, message.nativeInstance, $0) }))
    }
    
    /**
     Returns an operation to render the plain text body of a message.
     All end of line will be removed and white spaces cleaned up if requested.
     This method can be used to generate the summary of the message.
     
     MCOIMAPMessageRenderingOperation * op = [session plainTextBodyRenderingOperationWithMessage:msg
     folder:@"INBOX"
     stripWhitespace:YES];
     
     [op start:^(NSString * htmlString, NSError * error) {
     ...
     }];
     */
    public func plainTextBodyRenderingOperationWithMessage(message: IMAPMessage, folder: String, stripWhitespace: Bool) -> IMAPMessageRenderingOperation {
        return IMAPMessageRenderingOperation.init(operation: folder.utf16({ session.plainTextBodyRenderingOperation(session, message.nativeInstance, $0, stripWhitespace) }))
    }
    
    /**
     Returns an operation to render the plain text body of a message.
     All end of line will be removed and white spaces cleaned up.
     This method can be used to generate the summary of the message.
     
     MCOIMAPMessageRenderingOperation * op = [session plainTextBodyRenderingOperationWithMessage:msg
     folder:@"INBOX"];
     
     [op start:^(NSString * htmlString, NSError * error) {
     ...
     }];
     */
    public func plainTextBodyRenderingOperationWithMessage(message: IMAPMessage, folder: String) -> IMAPMessageRenderingOperation {
        return IMAPMessageRenderingOperation.init(operation: folder.utf16({ session.plainTextBodyRenderingOperation(session, message.nativeInstance, $0, true) }))
    }

}
