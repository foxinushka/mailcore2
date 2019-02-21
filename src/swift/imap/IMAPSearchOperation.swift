import Foundation
import CMailCore

public class MCOIMAPSearchOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, MCOIndexSet?) -> Void
	
    private var operation: CIMAPSearchOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPSearchOperation) {
        self.operation = operation
        self.operation.retain()
        super.init(baseOperation: CIMAPBaseOperation.init(cobject: operation.toCObject()));
    }

	deinit {
        self.operation.release()
        completionBlock = nil
	}
    
    /**
     Starts the asynchronous search operation.
     
     @param completionBlock Called when the operation is finished.
     
     - On success `error` will be nil and `searchResults` will contain the UIDs of any matching messages
     
     - On failure, `error` will be set with `MCOErrorDomain` as domain and an
     error code available in MCOConstants.h, `searchResult` will be nil
     */
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
            completionBlock(nil, MCOIndexSet(operation.uids()))
        }
        else {
            completionBlock(MailCoreError.error(code: errorCode), nil)
        }
        self.completionBlock = nil
    }
}
