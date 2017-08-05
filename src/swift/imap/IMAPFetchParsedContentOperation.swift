import Foundation


public class MCOIMAPFetchParsedContentOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  MCOMessageParser?) -> Void
    
    internal var operation: CIMAPFetchParsedContentOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchParsedContentOperation) {
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
            if let parser: MCOMessageParser = createMCOObject(from: operation.parser().toCObject()) {
                completionBlock!(nil, parser)
            }
            else {
                completionBlock!(nil, nil)
            }
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
