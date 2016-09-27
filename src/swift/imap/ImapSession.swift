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
		session.setHostname(&session, hostname);
	}

	func setPort(port: UInt32) {
		session.setPort(&session, port);
	}

	func setUsername(username: String) {
		session.setUsername(&session, username);
	}

	func setPassword(password: String) {
		session.setPassword(&session, password);
	}

	func setConnectionType(connectionType: ConnectionType) {
		session.setConnectionType(&session, connectionType);
	}

	func setTimeout(timeout: TimeInterval) {
		session.setTimeout(&session, Int(timeout));
	}

	func setCheckCertificateEnabled(isCheckCertificateEnabled: Bool) {
		session.setCheckCertificateEnabled(&session, isCheckCertificateEnabled);
	}

	func setOAuth2Token(OAuth2Token: String) {
		session.setOAuth2Token(&session, OAuth2Token);
	}

	func setAuthType(authType: AuthType) {
		session.setAuthType(&session, authType);
	}

	func setMaximumConnections(maximumConnections: UInt32) {
		session.setMaximumConnections(&session, maximumConnections);
	}

	func setAllowsFolderConcurrentAccessEnabled(allowsFolderConcurrentAccessEnabled: Bool) {
		session.setAllowsFolderConcurrentAccessEnabled(&session, allowsFolderConcurrentAccessEnabled);
	}

	func setDefaultNamespace(defaultNamespace: ImapNamespace) {
		session.setDefaultNamespace(&session, &defaultNamespace.ref);	
	}



    func disconnectOperation() -> ImapOperation {
    	return ImapOperation(operation: session.disconnectOperation(&session))
    }

    func noopOperation() -> ImapOperation {
    	return ImapOperation(operation: session.noopOperation(&session))
    }

    func checkAccountOperation() -> ImapOperation {
    	return ImapOperation(operation: session.checkAccountOperation(&session))
    }

    func capabilityOperation() -> ImapOperation {
    	return ImapOperation(operation: session.capabilityOperation(&session))
    }

    func fetchAllFoldersOperation() -> ImapOperation {
    	return ImapOperation(operation: session.fetchAllFoldersOperation(&session))
    }

    func expungeOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.expungeOperation(&session, folder))
    }

    func createFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.createFolderOperation(&session, folder))
    }

    func deleteFolderOperation(folder:String) -> ImapOperation {
    	return ImapOperation(operation: session.deleteFolderOperation(&session, folder))
    }

    func storeFlagsByUIDOperation(folder:String, uids:IndexSet, kind:IMAPStoreFlagsRequestKind, flags:MessageFlag, customFlags:Array<CObject>) -> ImapOperation {
    	return ImapOperation(operation: session.storeFlagsByUIDOperation(&session, folder, &uids.indexSet, kind, flags, cArray(customFlags)!));
    }



    func appendMessageOperation(folder:String, path:String, flags:MessageFlag, customFlags:Array<CObject>) -> ImapAppendMessageOperation {
    	return ImapAppendMessageOperation(operation: session.appendMessageOperation(&session, folder, path, flags, cArray(customFlags)!));
    }

    func fetchMessagesByNumber(folder:String, type:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByNumberOperation(&session, folder, type, &numbers.indexSet));
    }

    func fetchMessagesOperation(folder:String, kind:IMAPMessagesRequestKind, numbers:IndexSet) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.fetchMessagesByUIDOperation(&session, folder, kind, &numbers.indexSet));
    }

    func syncMessages(folder:String, kind:IMAPMessagesRequestKind, uids:IndexSet, modSeq:UInt64) -> ImapFetchMessagesOperation {
    	return ImapFetchMessagesOperation(operation: session.syncMessagesByUIDOperation(&session, folder, kind, &uids.indexSet, modSeq));
    }

    func fetchMessageOperation(folder:String, uid:UInt32, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageByUIDOperation(&session, folder, uid, urgent));
    }

    func fetchMessageAttachmentOperation(folder:String, uid:UInt32, partId:String, encoding:Encoding, urgent:Bool) -> ImapFetchContentOperation {
    	return ImapFetchContentOperation(operation: session.fetchMessageAttachmentByUIDOperation(&session, folder, uid, partId, encoding, urgent));
    }

    func searchExpressionOperation(folder:String, expression:ImapSearchExpression) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperationWithExpression(&session, folder, &expression.ref));
    }

    func searchOperation(folder:String, kind:IMAPSearchKind, searchString:String) -> ImapSearchOperation {
    	return ImapSearchOperation(operation: session.searchOperation(&session, folder, kind, searchString));
    }

    func copyMessagesOperation(folder:String, uids:IndexSet, destFolder:String) -> ImapCopyMessagesOperation {
    	return ImapCopyMessagesOperation(operation: session.copyMessagesOperation(&session, folder, &uids.indexSet, destFolder));
    }

    func folderInfoOperation(folder:String) -> ImapFolderInfoOperation {
    	return ImapFolderInfoOperation(operation: session.folderInfoOperation(&session, folder));
    }

    func folderStatusOperation(folder:String) -> ImapFolderStatusOperation {
    	return ImapFolderStatusOperation(operation: session.folderStatusOperation(&session, folder));
    }
    
//    func idleOperation(folder:String, lastKnownUID:UInt32) -> ImapIdleOperation {
//        return ImapIdleOperation(operation: session.idleOperation(&session, folder, lastKnownUID));
//    }
    

	deinit {
		deleteCIMAPAsyncSession(session);
	}
}
