import Foundation

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
            if operation.loginResponse(operation) != nil || operation.loginUnparsedResponseData(operation).bytes != nil {
                var userInfo = Dictionary<String, Any>()
                if operation.loginResponse(operation) != nil {
                    userInfo["IMAPResponseKey"] = String(utf16: operation.loginResponse(operation))
                }
                if operation.loginUnparsedResponseData(operation).bytes != nil {
                    userInfo["IMAPUnparsedResponseDataKey"] = Data.init(cdata: operation.loginUnparsedResponseData(operation))
                }
                error.userInfo = userInfo
            }
            completionBlock!(error)
        }
        completionBlock = nil
    }
    
}
