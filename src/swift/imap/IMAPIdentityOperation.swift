import Foundation
import CCore

public class IMAPIdentityOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  IMAPIdentity?) -> Void
    
    internal var operation: CIMAPIdentityOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPIdentityOperation) {
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
            completionBlock!(nil, IMAPIdentity.init(operation.serverIdentity()))
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
}
