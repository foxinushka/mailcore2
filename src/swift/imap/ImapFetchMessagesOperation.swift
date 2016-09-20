import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapFetchMessagesOperation {
	
	var operation:CIMAPFetchMessagesOperation;

	init(operation:CIMAPFetchMessagesOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPFetchMessagesOperation(operation);
	}
}
