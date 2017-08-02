import Foundation


/**
 The class is used to get folder metadata (like UIDVALIDITY, UIDNEXT, etc).
 @see MCOIMAPFolderInfo
 */
public class MCOIMAPFolderInfoOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?, MCOIMAPFolderInfo?) -> Void
	
	private var operation: CIMAPFolderInfoOperation;
    private var completionBlock : CompletionBlock?;

	internal init(operation:CIMAPFolderInfoOperation) {
 		self.operation = operation
        super.init(baseOperation: operation.baseOperation);
	}

    deinit {
        completionBlock = nil;
    }
    
    /**
     Starts the asynchronous operation.
     
     @param completionBlock Called when the operation is finished.
     
     - On success `error` will be nil and `info` will contain the folder metadata
     
     - On failure, `error` will be set with `MCOErrorDomain` as domain and an
     error code available in `MCOConstants.h`, `info` will be nil
     */
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
            completionBlock!(nil, MCOIMAPFolderInfo(info: operation.info()));
        }
        else {
            completionBlock!(MailCoreError(code: errorCode), nil);
        }
        completionBlock = nil;
    }
}
