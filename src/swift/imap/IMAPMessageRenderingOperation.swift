import Foundation

#if os(Android)
    import CMailCore
#endif

public class MCOIMAPMessageRenderingOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  String?) -> Void
    
    internal var operation: CIMAPMessageRenderingOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPMessageRenderingOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
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
            completionBlock!(nil, operation.result().string())
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
