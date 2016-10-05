import Foundation

public class ImapFetchContentOperation : ImapBaseOperation {
    
    public typealias CompletionBlock = (Error?,  Data?) -> Void
    
    internal var operation: CIMAPFetchContentOperation;
    private var completionBlock : CompletionBlock?;
    public var progressBlock : OperationProgressBlock?;
    
    internal init(operation:CIMAPFetchContentOperation) {
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
            completionBlock!(nil, Data(cdata: operation.data(operation)));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil);
        }
        completionBlock = nil;
    }
    
    public override func bodyProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current, maximum);
        }
    }
    
}

