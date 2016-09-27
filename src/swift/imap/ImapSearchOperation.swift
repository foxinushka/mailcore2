import Foundation

//#if os(iOS) || os(OSX)
//    import CMailCore
//#endif

class ImapSearchOperation {
	
	var operation:CIMAPSearchOperation;

	init(operation:CIMAPSearchOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPSearchOperation(operation);
	}
}
