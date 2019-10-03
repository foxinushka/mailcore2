import Foundation
import CMailCore

public class MCOIMAPIdleOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var idleOperation: CIMAPIdleOperation
    private var completionBlock: CompletionBlock?
    
    internal init(idleOperation: CIMAPIdleOperation) {
        self.idleOperation = idleOperation
        self.idleOperation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: idleOperation.toCObject()))
    }
    
    deinit {
        self.idleOperation.release()
        self.completionBlock = nil
    }

    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }

    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled))
        self.completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        guard let completionBlock = self.completionBlock else {
            return
        }

        mailCoreAutoreleasePool {
            let errorCode = error()
            if errorCode == ErrorNone {
                completionBlock(nil)
            }
            else {
                completionBlock(MailCoreError.error(code: errorCode))
            }
        }
        self.completionBlock = nil
    }

    public func interruptIdle() {
        idleOperation.interruptIdle();
    }
    
}
