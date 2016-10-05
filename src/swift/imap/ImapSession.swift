import Foundation

public class ImapSession {
	
	private var session:CIMAPAsyncSession;

	public init() {
 		session = newCIMAPAsyncSession();
	}
    
    deinit {
        deleteCIMAPAsyncSession(session);
    }

	public func setHostname(hostname: String) {
		session.setHostname(session, hostname.utf16CString);
	}

	public  func setPort(port: UInt32) {
		session.setPort(session, port);
	}

	public  func setUsername(username: String) {
		session.setUsername(session, username.utf16CString);
	}

	public func setPassword(password: String) {
		session.setPassword(session, password.utf16CString);
	}

	public func setConnectionType(connectionType: ConnectionType) {
		session.setConnectionType(session, connectionType);
	}

	public func setTimeout(timeout: TimeInterval) {
		session.setTimeout(session, Int(timeout));
	}

	public func setCheckCertificateEnabled(isCheckCertificateEnabled: Bool) {
		session.setCheckCertificateEnabled(session, isCheckCertificateEnabled);
	}

	public func setOAuth2Token(OAuth2Token: String) {
		session.setOAuth2Token(session, OAuth2Token.utf16CString);
	}

	public func setAuthType(authType: AuthType) {
		session.setAuthType(session, authType);
	}

	public func setMaximumConnections(maximumConnections: UInt32) {
		session.setMaximumConnections(session, maximumConnections);
	}

	public func setAllowsFolderConcurrentAccessEnabled(allowsFolderConcurrentAccessEnabled: Bool) {
		session.setAllowsFolderConcurrentAccessEnabled(session, allowsFolderConcurrentAccessEnabled);
	}

	public func setDefaultNamespace(defaultNamespace: ImapNamespace) {
		session.setDefaultNamespace(session, defaultNamespace.CIMAPNamespace());
	}

    public func disconnectOperation() -> ImapOperation {
    	return ImapOperation(operation: session.disconnectOperation(session))
    }

    public func noopOperation() -> ImapOperation {
    	return ImapOperation(operation: session.noopOperation(session))
    }

    public func checkAccountOperation() -> ImapOperation {
    	return ImapOperation(operation: session.checkAccountOperation(session))
    }

    public func capabilityOperation() -> ImapOperation {
    	return ImapOperation(operation: session.capabilityOperation(session))
    }

    public func fetchAllFoldersOperation() -> ImapOperation {
    	return ImapOperation(operation: session.fetchAllFoldersOperation(session))
    }

    public func expungeOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.expungeOperation(session, folder.utf16CString))
    }

    public func createFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.createFolderOperation(session, folder.utf16CString))
    }

    public func deleteFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.deleteFolderOperation(session, folder.utf16CString))
    }

    public func storeFlagsByUIDOperation(folder:String, uids:IndexSet, kind:IMAPStoreFlagsRequestKind, flags:MessageFlag, customFlags:Array<String>) -> ImapOperation {
    	return ImapOperation(operation: session.storeFlagsByUIDOperation(session, folder.utf16CString, uids.cast(), kind, flags, Array<String>.cast(customFlags)));
    }

    public func appendMessageOperation(folder:String, path:String, flags:MessageFlag, customFlags:Array<String>) -> ImapAppendMessageOperation {
    	return ImapAppendMessageOperation(operation: session.appendMessageOperation(session, folder.utf16CString, path.utf16CString, flags, Array<String>.cast(customFlags)));
    }

    public func fetchMessagesByNumber(folder:String, type:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByNumberOperation(session, folder.utf16CString, type, numbers.cast()));
    }

    public func fetchMessagesOperation(folder:String, kind:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByUIDOperation(session, folder.utf16CString, kind, numbers.cast()));
    }

    public func syncMessages(folder:String, kind:IMAPMessagesRequestKind, uids:IndexSet, modSeq:UInt64) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.syncMessagesByUIDOperation(session, folder.utf16CString, kind, uids.cast(), modSeq));
    }

    public func fetchMessageOperation(folder:String, uid:UInt32, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageByUIDOperation(session, folder.utf16CString, uid, urgent));
    }

    public func fetchMessageAttachmentOperation(folder:String, uid:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageAttachmentByUIDOperation(session, folder.utf16CString, uid, partId.utf16CString, encoding, urgent));
    }

    public func searchExpressionOperation(folder:String, expression:ImapSearchExpression) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperationWithExpression(session, folder.utf16CString, expression.cast()));
    }

    public func searchOperation(folder:String, kind:IMAPSearchKind, searchString:String) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperation(session, folder.utf16CString, kind, searchString.utf16CString));
    }

    public func copyMessagesOperation(folder:String, uids:IndexSet, destFolder:String) -> ImapCopyMessagesOperation {
    	return ImapCopyMessagesOperation(operation: session.copyMessagesOperation(session, folder.utf16CString, uids.cast(), destFolder.utf16CString));
    }

    public func folderInfoOperation(folder:String) -> ImapFolderInfoOperation {
    	return ImapFolderInfoOperation(operation: session.folderInfoOperation(session, folder.utf16CString));
    }

    public func folderStatusOperation(folder:String) -> ImapFolderStatusOperation {
    	return ImapFolderStatusOperation(operation: session.folderStatusOperation(session, folder.utf16CString));
    }
    
    public func idleOperation(folder:String, lastKnownUID:UInt32) -> ImapIdleOperation {
        return ImapIdleOperation(idleOperation: session.idleOperation(session, folder.utf16CString, lastKnownUID));
    }

}
