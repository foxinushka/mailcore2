import Foundation


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
    
    @objc public override func start(completionBlock: CompletionBlock?) {
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
            var error = MailCoreError(code: errorCode) as NSError
            if operation.loginResponse().instance != nil || operation.loginUnparsedResponseData().bytes != nil {
                var userInfo = [AnyHashable: Any]()
                if let response = operation.loginResponse().string() {
                    userInfo["IMAPResponseKey"] = response
                }
                if operation.loginUnparsedResponseData().bytes != nil {
                    userInfo["IMAPUnparsedResponseDataKey"] = Data(cdata: operation.loginUnparsedResponseData())
                }
                error = NSError(domain: "MailCoreErrorDomain", code: error.code, userInfo: userInfo)
            }
            completionBlock!(error)
        }
        completionBlock = nil
    }
    
}
