import Foundation

//#if os(iOS) || os(OSX)
//    import CMailCore
//#endif

class ImapSession {
	
	var session:CIMAPAsyncSession;

	init() {
 		session = newCIMAPAsyncSession();
	}


	func setHostname(hostname: String) {
		session.setHostname(session, hostname.utf16CString);
	}

	func setPort(port: UInt32) {
		session.setPort(session, port);
	}

	func setUsername(username: String) {
		session.setUsername(session, username.utf16CString);
	}

	func setPassword(password: String) {
		session.setPassword(session, password.utf16CString);
	}

	func setConnectionType(connectionType: ConnectionType) {
		session.setConnectionType(session, connectionType);
	}

	func setTimeout(timeout: TimeInterval) {
		session.setTimeout(session, Int(timeout));
	}

	func setCheckCertificateEnabled(isCheckCertificateEnabled: Bool) {
		session.setCheckCertificateEnabled(session, isCheckCertificateEnabled);
	}

	func setOAuth2Token(OAuth2Token: String) {
		session.setOAuth2Token(session, OAuth2Token.utf16CString);
	}

	func setAuthType(authType: AuthType) {
		session.setAuthType(session, authType);
	}

	func setMaximumConnections(maximumConnections: UInt32) {
		session.setMaximumConnections(session, maximumConnections);
	}

	func setAllowsFolderConcurrentAccessEnabled(allowsFolderConcurrentAccessEnabled: Bool) {
		session.setAllowsFolderConcurrentAccessEnabled(session, allowsFolderConcurrentAccessEnabled);
	}

	func setDefaultNamespace(defaultNamespace: ImapNamespace) {
		session.setDefaultNamespace(session, defaultNamespace.CIMAPNamespace());
	}



    func disconnectOperation() -> ImapOperation {
    	return ImapOperation(operation: session.disconnectOperation(session))
    }

    func noopOperation() -> ImapOperation {
    	return ImapOperation(operation: session.noopOperation(session))
    }

    func checkAccountOperation() -> ImapOperation {
    	return ImapOperation(operation: session.checkAccountOperation(session))
    }

    func capabilityOperation() -> ImapOperation {
    	return ImapOperation(operation: session.capabilityOperation(session))
    }

    func fetchAllFoldersOperation() -> ImapOperation {
    	return ImapOperation(operation: session.fetchAllFoldersOperation(session))
    }

    func expungeOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.expungeOperation(session, folder.utf16CString))
    }

    func createFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.createFolderOperation(session, folder.utf16CString))
    }

    func deleteFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.deleteFolderOperation(session, folder.utf16CString))
    }

    func storeFlagsByUIDOperation(folder:String, uids:IndexSet, kind:IMAPStoreFlagsRequestKind, flags:MessageFlag, customFlags:Array<CObject>) -> ImapOperation {
    	return ImapOperation(operation: session.storeFlagsByUIDOperation(session, folder.utf16CString, uids.indexSet, kind, flags, cArray(customFlags)));
    }



    func appendMessageOperation(folder:String, path:String, flags:MessageFlag, customFlags:Array<CObject>) -> ImapAppendMessageOperation {
    	return ImapAppendMessageOperation(operation: session.appendMessageOperation(session, folder.utf16CString, path.utf16CString, flags, cArray(customFlags)));
    }

    func fetchMessagesByNumber(folder:String, type:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByNumberOperation(session, folder.utf16CString, type, numbers.indexSet));
    }

    func fetchMessagesOperation(folder:String, kind:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByUIDOperation(session, folder.utf16CString, kind, numbers.indexSet));
    }

    func syncMessages(folder:String, kind:IMAPMessagesRequestKind, uids:IndexSet, modSeq:UInt64) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.syncMessagesByUIDOperation(session, folder.utf16CString, kind, uids.indexSet, modSeq));
    }

    func fetchMessageOperation(folder:String, uid:UInt32, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageByUIDOperation(session, folder.utf16CString, uid, urgent));
    }

    func fetchMessageAttachmentOperation(folder:String, uid:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageAttachmentByUIDOperation(session, folder.utf16CString, uid, partId.utf16CString, encoding, urgent));
    }

    func searchExpressionOperation(folder:String, expression:ImapSearchExpression) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperationWithExpression(session, folder.utf16CString, expression.cast()));
    }

    func searchOperation(folder:String, kind:IMAPSearchKind, searchString:String) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperation(session, folder.utf16CString, kind, searchString.utf16CString));
    }

    func copyMessagesOperation(folder:String, uids:IndexSet, destFolder:String) -> ImapCopyMessagesOperation {
    	return ImapCopyMessagesOperation(operation: session.copyMessagesOperation(session, folder.utf16CString, uids.indexSet, destFolder.utf16CString));
    }

    func folderInfoOperation(folder:String) -> ImapFolderInfoOperation {
    	return ImapFolderInfoOperation(operation: session.folderInfoOperation(session, folder.utf16CString));
    }

    func folderStatusOperation(folder:String) -> ImapFolderStatusOperation {
    	return ImapFolderStatusOperation(operation: session.folderStatusOperation(session, folder.utf16CString));
    }
    
    func idleOperation(folder:String, lastKnownUID:UInt32) -> ImapIdleOperation {
        return ImapIdleOperation(idleOperation: session.idleOperation(session, folder.utf16CString, lastKnownUID));
    }
    

	deinit {
		deleteCIMAPAsyncSession(session);
	}
}
