import Foundation
import CMailCore

public class MCOIMAPOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    private let cancelLock = NSLock()
    private var completionBlock: CompletionBlock?
    
    internal init(operation:CIMAPBaseOperation) {
        super.init(baseOperation: operation)
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        cancelLock.lock()
        let completionBlock = self.completionBlock
        self.completionBlock = nil
        cancelLock.unlock()

        if let completionBlock = completionBlock {
            completionBlock(MailCoreError.error(code: ErrorCanceled))
        }

        super.cancel()
    }
    
    public override func operationCompleted() {
        cancelLock.lock()
        guard let completionBlock = self.completionBlock else {
            cancelLock.unlock()
            return
        }
        
        self.completionBlock = nil
        cancelLock.unlock()
        
        mailCoreAutoreleasePool {
            let errorCode = error()
            if errorCode == ErrorNone {
                completionBlock(nil)
            }
            else {
                completionBlock(MailCoreError.error(code: errorCode))
            }
        }
    }

}
