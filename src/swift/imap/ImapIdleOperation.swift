import Foundation

class ImapIdleOperation : ImapBaseOperation {
    
    typealias CompletionBlock = (Error?) -> Void
    
    internal var idleOperation: CIMAPIdleOperation;
    private var completionBlock: CompletionBlock?;
    
    internal init(idleOperation: CIMAPIdleOperation) {
        self.idleOperation = idleOperation;
        super.init(baseOperation: idleOperation.operation);
    }

	deinit {
		deleteCIMAPIdleOperation(idleOperation);
	}

    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }

    override func cancel() {
        self.completionBlock = nil;
        super.cancel();
    }
    
    override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }

        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil);
        }
        else {
            completionBlock!(MailCoreError(code: errorCode));
        }
        completionBlock = nil;
    }

    public func interruptIdle() {
        idleOperation.interruptIdle(idleOperation);
    }
    
}
