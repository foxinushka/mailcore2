import Foundation

//#if os(iOS) || os(OSX)
//    import CMailCore
//#endif

class ImapFolderStatusOperation {
	
	var operation:CIMAPFolderStatusOperation;

	init(operation:CIMAPFolderStatusOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPFolderStatusOperation(operation);
	}
}
