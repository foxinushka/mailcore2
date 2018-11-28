import Foundation
import CMailCore

public class MCOIMAPCheckAccountOperation : MCOIMAPOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CIMAPCheckAccountOperation
    private var completionBlock : CompletionBlock?
    
    internal init(checkAccountOperation operation:CIMAPCheckAccountOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(operation: CIMAPBaseOperation(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
        completionBlock = nil;
    }
    
    public override func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled))
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
            var error = MailCoreError.error(code: errorCode)
            if operation.loginResponse().instance != nil || operation.loginUnparsedResponseData().instance != nil {
                var userInfo = [String: Any]()
                if let response = operation.loginResponse().string() {
                    userInfo["IMAPResponseKey"] = response
                }
                let data = operation.loginUnparsedResponseData()
                if data.instance != nil && data.bytes != nil {
                    userInfo["IMAPUnparsedResponseDataKey"] = Data(cdata: data)
                }
                error = MailCoreError.error(code: errorCode, userInfo: userInfo)
            }
            completionBlock!(error)
        }
        completionBlock = nil
    }
    
}
