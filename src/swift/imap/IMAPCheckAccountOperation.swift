import Foundation
import CCore

public class IMAPCheckAccountOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CIMAPCheckAccountOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPCheckAccountOperation) {
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
            completionBlock!(nil)
        }
        else {
            let error = MailCoreError(code: errorCode)
            if operation.loginResponse() != nil || operation.loginUnparsedResponseData().bytes != nil {
                var userInfo = Dictionary<String, Any>()
                if operation.loginResponse() != nil {
                    userInfo["IMAPResponseKey"] = String(utf16: operation.loginResponse())
                }
                if operation.loginUnparsedResponseData().bytes != nil {
                    userInfo["IMAPUnparsedResponseDataKey"] = Data.init(cdata: operation.loginUnparsedResponseData())
                }
                error.userInfo = userInfo
            }
            completionBlock!(error)
        }
        completionBlock = nil
    }
    
}
