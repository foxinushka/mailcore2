import Foundation

#if os(Android)
    import CMailCore
#endif

public class MCOIMAPIdleOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var idleOperation: CIMAPIdleOperation;
    private var completionBlock: CompletionBlock?;
    
    internal init(idleOperation: CIMAPIdleOperation) {
        self.idleOperation = idleOperation;
        self.idleOperation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: idleOperation.toCObject()))
    }
    
    deinit {
        self.idleOperation.release()
        self.completionBlock = nil
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
        idleOperation.interruptIdle();
    }
    
}
