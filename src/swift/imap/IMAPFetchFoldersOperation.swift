import Foundation
import CMailCore

public class MCOIMAPFetchFoldersOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?,  [MCOIMAPFolder]?) -> Void
    
    internal var operation: CIMAPFetchFoldersOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchFoldersOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()))
    }
    
    deinit {
        self.operation.release()
        completionBlock = nil;
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled), nil)
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        guard let completionBlock = self.completionBlock else {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            completionBlock(nil, Array<MCOIMAPFolder>(mailCoreArray: operation.folders()))
        }
        else {
            completionBlock(MailCoreError.error(code: errorCode), nil)
        }
        self.completionBlock = nil
    }
    
}
