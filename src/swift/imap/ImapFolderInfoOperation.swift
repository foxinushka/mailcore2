import Foundation

//#if os(iOS) || os(OSX)
//    import CMailCore
//#endif

class ImapFolderInfoOperation {
	
	var operation:CIMAPFolderInfoOperation;

	init(operation:CIMAPFolderInfoOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPFolderInfoOperation(operation);
	}
}
