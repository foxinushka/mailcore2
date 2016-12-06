import Foundation

public class IMAPCustomCommandOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (String?, Error?) -> Void
    
    internal var operation: CIMAPCustomCommandOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPCustomCommandOperation) {
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
            completionBlock!(String(utf16: operation.response(operation)), nil)
        }
        else {
            completionBlock!(nil, MailCoreError(code: errorCode))
        }
        completionBlock = nil
    }
    
}
