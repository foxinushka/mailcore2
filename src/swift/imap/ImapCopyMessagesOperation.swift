import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapCopyMessagesOperation {
	
	var operation:CIMAPCopyMessagesOperation;

	init(operation:CIMAPCopyMessagesOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPCopyMessagesOperation(operation);
	}
}
