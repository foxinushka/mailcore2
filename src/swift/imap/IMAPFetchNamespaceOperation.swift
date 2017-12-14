import Foundation
import CMailCore

public class MCOIMAPFetchNamespaceOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  Dictionary<String, MCOIMAPNamespace>?) -> Void
    
    internal var operation: CIMAPFetchNamespaceOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchNamespaceOperation) {
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
            completionBlock!(nil, Dictionary<String, MCOIMAPNamespace>.cast(operation.namespaces()))
        }
        else {
            completionBlock!(MailCoreError.error(code: errorCode), nil)
        }
        completionBlock = nil
    }
}
