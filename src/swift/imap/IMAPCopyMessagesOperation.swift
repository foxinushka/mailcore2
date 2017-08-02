import Foundation


public class MCOIMAPCopyMessagesOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, Dictionary<UInt32, UInt32>?) -> Void
    
    internal var operation: CIMAPCopyMessagesOperation;
    private var completionBlock : CompletionBlock?;
    
    internal init(operation:CIMAPCopyMessagesOperation) {
        self.operation = operation;
        super.init(baseOperation: operation.baseOperation);
    }
    
    deinit {
        completionBlock = nil;
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }
    
    public override func cancel() {
        completionBlock = nil;
        super.cancel();
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil, Dictionary<UInt32, UInt32>.cast(operation.uidMapping()));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil);
        }
        completionBlock = nil;
    }
    
}
