import Foundation

public class SMTPOperation: Operation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CSMTPOperation;
    public var session: SMTPSession?;
    private var completionBlock: CompletionBlock?;
    
    internal init(_ operation: CSMTPOperation) {
        self.operation = operation;
        super.init(operation.cOperation);
    }
    
    deinit {
        deleteCSMTPOperation(self.operation);
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
        
        let errorCode = operation.error(operation);
        if errorCode == ErrorNone {
            completionBlock!(nil);
        }
        else {
            //TODO: copy lastSMTPResponse info
            completionBlock!(MailCoreError(code: errorCode));
        }
        completionBlock = nil;
    }

    

}
