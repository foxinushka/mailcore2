import Foundation
import CCore

public class IMAPFetchParsedContentOperation : IMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  MessageParser?) -> Void
    
    internal var operation: CIMAPFetchParsedContentOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchParsedContentOperation) {
        self.operation = operation
        super.init(baseOperation: operation.baseOperation)
    }
    
    deinit {
        completionBlock = nil;
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            let parser = MessageParser(operation.parser())
            if parser.nativeInstance.instance != nil {
                completionBlock!(nil, parser)
            }
            else {
                completionBlock!(nil, nil)
            }
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil)
        }
        completionBlock = nil
    }
    
}
