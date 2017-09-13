import Foundation

#if os(Android)
    import CMailCore
#endif

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
            var error = MailCoreError(code: errorCode).asNSError()
            if operation.lastSMTPResponse.instance != nil || operation.lastSMTPResponseCode != 0 {
                var userInfo = [String: Any]()
                if let response = operation.lastSMTPResponse.string() {
                    userInfo["MCOSMTPResponseKey"] = response
                }
                if operation.lastSMTPResponseCode != 0 {
                    userInfo["MCOSMTPResponseCodeKey"] = operation.lastSMTPResponseCode
                }
                error = MailCoreError(code: errorCode).asNSError(userInfo: userInfo)
            }
            completionBlock!(error)
        }
        completionBlock = nil;
    }

    

}
