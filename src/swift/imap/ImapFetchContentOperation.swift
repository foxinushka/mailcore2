import Foundation
import Glibc

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
