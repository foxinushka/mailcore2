import Foundation
import CMailCore

public class MCOIMAPQuotaOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, UInt32, UInt32) -> Void
    
    internal var operation: CIMAPQuotaOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPQuotaOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
        completionBlock = nil
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled), 0, 0)
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        guard let completionBlock = self.completionBlock else {
            return
        }

        mailCoreAutoreleasePool {
            let errorCode = error()
            if errorCode == ErrorNone {
                completionBlock(nil, operation.usage(), operation.limit())
            }
            else {
                completionBlock(MailCoreError.error(code: errorCode), 0, 0)
            }
        }
        self.completionBlock = nil
    }
    
}
