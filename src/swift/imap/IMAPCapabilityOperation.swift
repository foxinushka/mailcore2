import Foundation

public class IMAPCapabilityOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  IndexSet?) -> Void
    
    internal var operation: CIMAPCapabilityOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPCapabilityOperation) {
        self.operation = operation
        super.init(baseOperation: operation.baseOperation)
    }
    
    deinit {
        completionBlock = nil;
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            completionBlock!(nil, IndexSet(operation.capabilities(operation)))
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
