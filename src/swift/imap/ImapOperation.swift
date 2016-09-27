import Foundation

class ImapOperation : ImapBaseOperation {
    
    typealias CompletionBlock = (Error?) -> Void
    
    private var completionBlock: CompletionBlock?;
	
	internal init(operation:CIMAPBaseOperation) {
        super.init(baseOperation: operation);
	}
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }
    
    override func cancel() {
        self.completionBlock = nil;
        super.cancel();
    }
    
    override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil);
        }
        else {
            completionBlock!(MailCoreError(code: errorCode));
        }
        completionBlock = nil;
    }

}
