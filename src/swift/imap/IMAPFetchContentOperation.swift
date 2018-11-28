import Foundation
import CMailCore

public class MCOIMAPFetchContentOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  Data?) -> Void
    
    internal var operation: CIMAPFetchContentOperation;
    private var completionBlock : CompletionBlock?;
    public var progressBlock : MCOOperationProgressBlock?;
    
    internal init(operation:CIMAPFetchContentOperation) {
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
            completionBlock!(nil, Data.init(desctructiveCData: operation.data()));
        }
        else {
            completionBlock!(MailCoreError.error(code: errorCode), nil);
        }
        completionBlock = nil;
    }
    
    public override func bodyProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current, maximum);
        }
    }
    
}

