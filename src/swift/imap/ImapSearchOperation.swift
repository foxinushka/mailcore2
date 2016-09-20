import Foundation
import Glibc

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
