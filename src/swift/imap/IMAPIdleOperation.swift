import Foundation

public class IMAPIdleOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var idleOperation: CIMAPIdleOperation;
    private var completionBlock: CompletionBlock?;
    
    internal init(idleOperation: CIMAPIdleOperation) {
        self.idleOperation = idleOperation;
        super.init(baseOperation: idleOperation.operation);
    }

    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }

    public override func cancel() {
        self.completionBlock = nil;
        super.cancel();
    }
    
    public override func operationCompleted() {
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
