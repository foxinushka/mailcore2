import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapFetchContentOperation {
	
	var operation:CIMAPFetchContentOperation;

	init(operation:CIMAPFetchContentOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPFetchContentOperation(operation);
	}
}
