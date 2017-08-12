import Foundation


public class MCOSMTPOperation: MCOOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CSMTPOperation;
    public var session: MCOSMTPSession?;
    private var completionBlock: CompletionBlock?;
    
    internal init(operation: CSMTPOperation) {
        self.operation = operation;
        self.operation.retain()
        super.init(operation.cOperation);
    }
    
    deinit {
        self.operation.release()
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }
    
    public override func cancel() {
        self.completionBlock = nil;
        super.cancel()
    }
    
    override public func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = operation.error;
        if errorCode == ErrorNone {
            completionBlock!(nil);
        }
        else {
            var error = MailCoreError(code: errorCode) as NSError
            if operation.lastSMTPResponse.instance != nil || operation.lastSMTPResponseCode != 0 {
                var userInfo = [AnyHashable: Any]()
                if let response = operation.lastSMTPResponse.string() {
                    userInfo["MCOSMTPResponseKey"] = response
                }
                if operation.lastSMTPResponseCode != 0 {
                    userInfo["MCOSMTPResponseCodeKey"] = operation.lastSMTPResponseCode
                }
                error = NSError(domain: "MailCoreErrorDomain", code: error.code, userInfo: userInfo)
            }
            completionBlock!(error)
        }
        completionBlock = nil;
    }

    

}
