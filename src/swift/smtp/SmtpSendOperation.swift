import Foundation

public class SmtpSendOperation : SmtpOperation {
    
    public typealias OperationProgressBlock = (UInt32, UInt32) -> Void
    
    public var progressBlock: OperationProgressBlock? {
        get { return self.progressBlock; }
        set { self.operation = operation.setProgressBlocks(operation, progressBlock); }
    }
    
}
