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
            let error = MailCoreError(code: errorCode) as NSError
            if operation.lastSMTPResponse.instance != nil || operation.lastSMTPResponseCode != 0 {
                if let response = operation.lastSMTPResponse.string() {
                    error.insertValue(response, inPropertyWithKey: "MCOSMTPResponseKey")
                }
                if operation.lastSMTPResponseCode != 0 {
                    error.insertValue(operation.lastSMTPResponseCode, inPropertyWithKey: "MCOSMTPResponseCodeKey")
                }
            }
            completionBlock!(error)
        }
        completionBlock = nil;
    }

    

}
