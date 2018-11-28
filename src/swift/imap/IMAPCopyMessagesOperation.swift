import Foundation
import CMailCore

public class MCOIMAPCopyMessagesOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, Dictionary<UInt32, UInt32>?) -> Void
    
    internal var operation: CIMAPCopyMessagesOperation;
    private var completionBlock : CompletionBlock?;
    
    internal init(operation:CIMAPCopyMessagesOperation) {
        self.operation = operation;
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
        completionBlock = nil;
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled), nil)
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
            completionBlock!(MailCoreError.error(code: errorCode), nil);
        }
        completionBlock = nil;
    }
    
}
