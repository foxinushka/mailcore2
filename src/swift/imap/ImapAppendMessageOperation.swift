import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

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