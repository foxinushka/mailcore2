import Foundation
import CCore

public class IMAPFetchNamespaceOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  Dictionary<String, IMAPNamespace>?) -> Void
    
    internal var operation: CIMAPFetchNamespaceOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchNamespaceOperation) {
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
            completionBlock!(nil, Dictionary<String, IMAPNamespace>.cast(operation.namespaces()))
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
}
