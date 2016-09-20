import Foundation
import Glibc

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
