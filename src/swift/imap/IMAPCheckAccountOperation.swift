import Foundation


public class MCOIMAPCheckAccountOperation : MCOIMAPOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CIMAPCheckAccountOperation
    private var completionBlock : CompletionBlock?
    
    internal init(checkAccountOperation operation:CIMAPCheckAccountOperation) {
        self.operation = operation
        super.init(operation: operation.baseOperation)
    }
    
    deinit {
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
            let error = MailCoreError(code: errorCode) as NSError
            if operation.loginResponse() != nil || operation.loginUnparsedResponseData().bytes != nil {
                if let response = operation.loginResponse().string() {
                    error.insertValue(response, inPropertyWithKey: "IMAPResponseKey")
                }
                if operation.loginUnparsedResponseData().bytes != nil {
                    error.insertValue(Data.init(cdata: operation.loginUnparsedResponseData()), inPropertyWithKey: "IMAPUnparsedResponseDataKey")
                }
                
            }
            completionBlock!(error)
        }
        completionBlock = nil
    }
    
}
