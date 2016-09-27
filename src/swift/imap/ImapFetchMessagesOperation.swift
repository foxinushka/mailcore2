import Foundation

class ImapFetchMessagesOperation : ImapBaseOperation {
    
    typealias CompletionBlock = (Error?, Array<Any>?, IndexSet?) -> Void
    
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
    
    override func cancel() {
        completionBlock = nil;
        super.cancel();
    }
    
    override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil, arrayFromC(operation.messages(&operation)), IndexSet(cindexset: operation.vanishedMessages(&operation)));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil, nil);
        }
        completionBlock = nil;
    }
    
    override func itemProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current);
        }
    }
    
    public var extraHeaders: Array<Any> {
        get { return arrayFromC(operation.extraHeaders(&operation)); }
        set { operation.setExtraHeaders(&operation, cArray(newValue)!);}
    }
    
}
