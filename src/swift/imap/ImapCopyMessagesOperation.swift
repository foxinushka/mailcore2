import Foundation
import Glibc

class ImapCopyMessagesOperation {
	
	var operation:CIMAPCopyMessagesOperation;

	init(operation:CIMAPCopyMessagesOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteCIMAPCopyMessagesOperation(operation);
	}
}
