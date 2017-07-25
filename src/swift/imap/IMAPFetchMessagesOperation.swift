import Foundation


public class IMAPFetchMessagesOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, Array<IMAPMessage>?, MCOIndexSet?) -> Void
    
    internal var operation: CIMAPFetchMessagesOperation;
    private var completionBlock : CompletionBlock?;
    public var progressBlock : OperationItemProgressBlock?;
    
    internal init(operation:CIMAPFetchMessagesOperation) {
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
            completionBlock!(nil, Array<IMAPMessage>.cast(operation.messages()), MCOIndexSet(operation.vanishedMessages()));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil, nil);
        }
        completionBlock = nil;
    }
    
    public override func itemProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current);
        }
    }
    
    public var extraHeaders: Array<String> {
        get { return Array<String>.cast(operation.extraHeaders) }
        set { operation.extraHeaders = Array<String>.cast(newValue) }
    }
    
}
