import Foundation
import CMailCore

public class MCOIMAPFetchMessagesOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, Array<MCOIMAPMessage>?, MCOIndexSet?) -> Void
    
    internal var operation: CIMAPFetchMessagesOperation;
    private var completionBlock : CompletionBlock?;
    public var progressBlock : MCOOperationItemProgressBlock?;
    
    internal init(operation:CIMAPFetchMessagesOperation) {
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
        completionBlock?(MailCoreError.error(code: ErrorCanceled), nil, nil)
        completionBlock = nil;
        super.cancel();
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil, Array<MCOIMAPMessage>(mailCoreArray: operation.messages()), MCOIndexSet(operation.vanishedMessages()));
        }
        else {
            completionBlock!(MailCoreError.error(code: errorCode), nil, nil);
        }
        completionBlock = nil;
    }
    
    public override func itemProgress(current: UInt32, maximum: UInt32) {
        if progressBlock != nil {
            progressBlock!(current);
        }
    }
    
    public var extraHeaders: Array<String>? {
        get { return Array<String>(mailCoreArray: operation.extraHeaders) }
        set { operation.extraHeaders = newValue?.mailCoreArray() ?? CArray() }
    }
    
}
