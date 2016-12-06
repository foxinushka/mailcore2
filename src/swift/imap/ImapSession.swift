import Foundation
import Dispatch

/**
 This is the main IMAP class from which all operations are created
 
 After calling a method that returns an operation you must call start: on the instance
 to begin the operation.
 */
public class ImapSession {
	
	private var session:CIMAPAsyncSession;

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
    public var defaultNamespace: ImapNamespace? {
        get { return ImapNamespace(namespace: session.defaultNamespace(session)); }
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

    /**
     Returns an operation to disconnect the session.
     It will disconnect all the sockets created by the session.
     
     MCOIMAPOperation * op = [session disconnectOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func disconnectOperation() -> ImapOperation {
    	return ImapOperation(operation: session.disconnectOperation(session))
    }

    /**
     Returns an operation that will perform a No-Op operation on the given IMAP server.
     
     MCOIMAPOperation * op = [session noopOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func noopOperation() -> ImapOperation {
    	return ImapOperation(operation: session.noopOperation(session))
    }

    /**
     Returns an operation that will check whether the IMAP account is valid.
     
     MCOIMAPOperation * op = [session checkAccountOperation];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func checkAccountOperation() -> ImapOperation {
    	return ImapOperation(operation: session.checkAccountOperation(session))
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
    public func capabilityOperation() -> ImapOperation {
    	return ImapOperation(operation: session.capabilityOperation(session))
    }
    
    /**
     Returns an operation that gets all folders
     
     MCOIMAPFetchFoldersOperation * op = [session fetchAllFoldersOperation];
     [op start:^(NSError * __nullable error, NSArray *folders) {
     ...
     }];
     */
    public func fetchAllFoldersOperation() -> ImapFetchFoldersOperation {
    	return ImapFetchFoldersOperation(operation: session.fetchAllFoldersOperation(session))
    }
    
    /**
     Returns an operation to expunge a folder.
     
     MCOIMAPOperation * op = [session expungeOperation:@"INBOX"];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func expungeOperation(folder:String) -> ImapOperation {
        return ImapOperation(operation: folder.utf16({ session.expungeOperation(session, $0) }))
    }

    /**
     Returns an operation that creates a new folder
     
     MCOIMAPOperation * op = [session createFolderOperation:@"holidays 2013"];
     [op start:^(NSError * __nullable error) {
     ...
     }];
     */
    public func createFolderOperation(folder:String) -> ImapOperation {
        return ImapOperation(operation: folder.utf16({ session.createFolderOperation(session, $0) }))
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
    public func deleteFolderOperation(folder:String) -> ImapOperation {
        return ImapOperation(operation: folder.utf16({ session.deleteFolderOperation(session, $0) }))
    }

    public func storeFlagsByUIDOperation(folder:String, uids:IndexSet, kind:IMAPStoreFlagsRequestKind, flags:MessageFlag, customFlags:Array<String>) -> ImapOperation {
        return ImapOperation(operation: folder.utf16({ session.storeFlagsByUIDOperation(session, $0, uids.cast(), kind, flags, Array<String>.cast(customFlags)) }));
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
    public func appendMessageOperation(folder:String, path:String, flags:MessageFlag, customFlags:Array<String>) -> ImapAppendMessageOperation {
        return ImapAppendMessageOperation(operation: folder.utf16({ folderPtr in
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
    public func fetchMessagesByNumber(folder:String, type:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
        return ImapFetchMessagesOperation(operation: folder.utf16({ session.fetchMessagesByNumberOperation(session, $0, type, numbers.cast()) }));
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
    public func fetchMessagesOperation(folder:String, kind:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
        return ImapFetchMessagesOperation(operation: folder.utf16({ session.fetchMessagesByUIDOperation(session, $0, kind, numbers.cast()) }));
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
    public func syncMessages(folder:String, kind:IMAPMessagesRequestKind, uids:IndexSet, modSeq:UInt64) -> ImapFetchMessagesOperation {
        return ImapFetchMessagesOperation(operation: folder.utf16({ session.syncMessagesByUIDOperation(session, $0, kind, uids.cast(), modSeq) }));
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
    public func fetchMessageOperation(folder:String, uid:UInt32, urgent:Bool) -> ImapFetchContentOperation {
        return ImapFetchContentOperation(operation: folder.utf16({ session.fetchMessageByUIDOperation(session, $0, uid, urgent) }));
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
    public func fetchMessageAttachmentOperation(folder:String, uid:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> ImapFetchContentOperation {
        return ImapFetchContentOperation(operation: folder.utf16({ folderPtr in
            partId.utf16({ partIdPtr in
                session.fetchMessageAttachmentByUIDOperation(session, folderPtr, uid, partIdPtr, encoding, urgent)
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
    public func searchExpressionOperation(folder:String, expression:ImapSearchExpression) -> ImapSearchOperation {
        return ImapSearchOperation(operation: folder.utf16({ session.searchOperationWithExpression(session, $0, expression.cast()) }));
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
    public func searchOperation(folder:String, kind:IMAPSearchKind, searchString:String) -> ImapSearchOperation {
        return ImapSearchOperation(operation: folder.utf16({ folderPtr in
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
    public func copyMessagesOperation(folder:String, uids:IndexSet, destFolder:String) -> ImapCopyMessagesOperation {
        return ImapCopyMessagesOperation(operation: folder.utf16({ folderPtr in
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
    public func folderInfoOperation(folder:String) -> ImapFolderInfoOperation {
        return ImapFolderInfoOperation(operation: folder.utf16({ session.folderInfoOperation(session, $0) }));
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
    public func folderStatusOperation(folder:String) -> ImapFolderStatusOperation {
        return ImapFolderStatusOperation(operation: folder.utf16({ session.folderStatusOperation(session, $0) }));
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
    public func idleOperation(folder:String, lastKnownUID:UInt32) -> ImapIdleOperation {
        return ImapIdleOperation(idleOperation: folder.utf16({ session.idleOperation(session, $0, lastKnownUID) }));
    }

}
