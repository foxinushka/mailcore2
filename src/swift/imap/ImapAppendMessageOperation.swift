import Foundation
import Glibc

class ImapAppendMessageOperation {
	
	var operation:CIMAPAppendMessageOperation;

	init(operation:CIMAPAppendMessageOperation) {
 		self.operation = operation
	}

	deinit {
        //?
		deleteIMAPAppendMessageOperation(operation);
	}
}