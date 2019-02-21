import Foundation
import CMailCore

public class MCOIMAPIdentityOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  MCOIMAPIdentity?) -> Void
    
    internal var operation: CIMAPIdentityOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPIdentityOperation) {
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
        guard let completionBlock = self.completionBlock else {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            completionBlock(nil, MCOIMAPIdentity.init(mailCoreObject: operation.serverIdentity().toCObject()))
        }
        else {
            completionBlock(MailCoreError.error(code: errorCode), nil)
        }
        self.completionBlock = nil
    }
}
