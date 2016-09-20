import Foundation
import Glibc

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
