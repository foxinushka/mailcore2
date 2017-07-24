import Foundation


public class IMAPAppendMessageOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, UInt32) -> Void
	
	internal var operation: CIMAPAppendMessageOperation;
    private var completionBlock : CompletionBlock?;
    public var progressBlock : OperationProgressBlock?;

	internal init(operation:CIMAPAppendMessageOperation) {
        self.operation = operation;
        super.init(baseOperation: operation.baseOperation);
	}

	deinit {
        progressBlock = nil;
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
            completionBlock!(nil, operation.createdUID());
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), 0);
        }
        completionBlock = nil;
    }
    
    public override func bodyProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current, maximum);
        }
    }
    
}
