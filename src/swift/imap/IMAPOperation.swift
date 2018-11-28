import Foundation
import CMailCore

public class MCOIMAPOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    private var completionBlock: CompletionBlock?;
	
	internal init(operation:CIMAPBaseOperation) {
        super.init(baseOperation: operation);
	}
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock;
        start();
    }
    
    public override func cancel() {
        completionBlock?(MailCoreError.error(code: ErrorCanceled))
        self.completionBlock = nil;
        super.cancel();
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return;
        }
        
        let errorCode = error();
        if errorCode == ErrorNone {
            completionBlock!(nil);
        }
        else {
            completionBlock!(MailCoreError.error(code: errorCode));
        }
        completionBlock = nil;
    }

}
