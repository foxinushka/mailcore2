import Foundation
import CMailCore

public class MCOIMAPAppendMessageOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, UInt32) -> Void
    
    internal var operation: CIMAPAppendMessageOperation
    private var completionBlock : CompletionBlock?
    public var progressBlock : MCOOperationProgressBlock?
    
    internal init(operation:CIMAPAppendMessageOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
        progressBlock = nil
        completionBlock = nil
    }
    
    public var date: time_t {
        get {
            return mailCoreAutoreleasePool {
                return self.operation.date
            }
        }
        set {
            return mailCoreAutoreleasePool {
                self.operation.date = newValue
            }
        }
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled), 0)
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
                completionBlock(nil, operation.createdUID())
            }
            else {
                completionBlock(MailCoreError.error(code: errorCode), 0)
            }
        }
        self.completionBlock = nil
    }
    
    public override func bodyProgress(current: UInt32, maximum: UInt32) {
        progressBlock?(current, maximum)
    }
    
}
