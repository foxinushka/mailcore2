import Foundation
import Glibc

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
