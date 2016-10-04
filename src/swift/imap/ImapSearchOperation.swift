import Foundation

class ImapSearchOperation : ImapBaseOperation {
    
    typealias CompletionBlock = (Error?, IndexSet?) -> Void
	
    private var operation: CIMAPSearchOperation;
    private var completionBlock : CompletionBlock?;
    
    init(operation:CIMAPSearchOperation) {
        self.operation = operation
        super.init(baseOperation: operation.baseOperation);
    }

	deinit {
        completionBlock = nil;
	}
    
    /**
     Starts the asynchronous search operation.
     
     @param completionBlock Called when the operation is finished.
     
     - On success `error` will be nil and `searchResults` will contain the UIDs of any matching messages
     
     - On failure, `error` will be set with `MCOErrorDomain` as domain and an
     error code available in MCOConstants.h, `searchResult` will be nil
     */
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
            completionBlock!(nil, IndexSet.cast(operation.uids(operation)));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil);
        }
        completionBlock = nil;
    }
}