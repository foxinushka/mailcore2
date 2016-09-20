import Foundation
import Glibc

class ImapFetchMessagesOperation {
	
	var operation:CIMAPFetchMessagesOperation;

	init(operation:CIMAPFetchMessagesOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPFetchMessagesOperation(operation);
	}
}
