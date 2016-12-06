import Foundation

public class SmtpSendOperation : SmtpOperation {
    
    public typealias OperationProgressBlock = (UInt32, UInt32) -> Void
    
    override init(_ operation: CSMTPOperation) {
        super.init(operation)
        self.operation = operation.setProgressBlocks(operation, operationProgressCallback, Unmanaged.passUnretained(self).toOpaque())
    }
    
    public var progressBlock: OperationProgressBlock?
}

//MARK: C-Function
func operationProgressCallback(_ ref: UnsafeRawPointer?, _ current: UInt32, _ max: UInt32) {
    let selfRef = Unmanaged<SmtpSendOperation>.fromOpaque(ref!).takeUnretainedValue()
    if selfRef.progressBlock != nil {
        selfRef.progressBlock!(current, max)
    }
}
