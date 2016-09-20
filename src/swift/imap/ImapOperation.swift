import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapOperation {
	
	var operation:CIMAPOperation;

	init(operation:CIMAPOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPOperation(operation);
	}
}
