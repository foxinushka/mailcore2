import Foundation

public class IMAPMessageRenderingOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  String?) -> Void
    
    internal var operation: CIMAPMessageRenderingOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPMessageRenderingOperation) {
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
            completionBlock!(nil, String.init(utf16: operation.result(operation)))
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
