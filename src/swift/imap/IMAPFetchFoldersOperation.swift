import Foundation


public class MCOIMAPFetchFoldersOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  [MCOIMAPFolder]?) -> Void
    
    internal var operation: CIMAPFetchFoldersOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchFoldersOperation) {
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
            completionBlock!(nil, Array<MCOIMAPFolder>(mailCoreArray: operation.folders()))
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
