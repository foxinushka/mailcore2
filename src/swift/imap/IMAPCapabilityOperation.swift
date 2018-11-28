import Foundation
import CMailCore

public class MCOIMAPCapabilityOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  MCOIndexSet?) -> Void
    
    internal var operation: CIMAPCapabilityOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPCapabilityOperation) {
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
        completionBlock?(MailCoreError.error(code: ErrorCanceled), nil)
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            completionBlock!(nil, MCOIndexSet(operation.capabilities()))
        }
        else {
            completionBlock!(MailCoreError.error(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
