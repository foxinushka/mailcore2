import Foundation

#if os(iOS) || os(OSX)
    import CMailCore
#endif

class ImapIdleOperation {
    
    typealias CompletionBlock = @convention(block) (ErrorCode) -> Void

	var ref:CIMAPIdleOperation;

	init(operation:CIMAPIdleOperation) {
 		self.ref = operation
	}

	deinit {
		deleteCIMAPIdleOperation(&ref);
	}
    
    func start(completionBlock: CompletionBlock?) {
        ref.start(&ref, completionBlock);
    }
    
    func cancel() {
        ref.cancel(&ref);
    }
    
    func interruptIdle() {
        ref.interruptIdle(&ref);
    }
}
