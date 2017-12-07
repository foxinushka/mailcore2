import Foundation


public class MCOSMTPSendOperation : MCOSMTPOperation {
    
    public typealias MCOOperationProgressBlock = (UInt32, UInt32) -> Void
    
    override init(operation: CSMTPOperation) {
        super.init(operation: operation)
        self.operation = self.operation.setProgressBlocks(operationProgressCallback, Unmanaged.passUnretained(self).toOpaque())
    }
    
    public var progressBlock: MCOOperationProgressBlock?
}

//MARK: C-Function
func operationProgressCallback(_ ref: UnsafeRawPointer?, _ current: UInt32, _ max: UInt32) {
    let selfRef = Unmanaged<MCOSMTPSendOperation>.fromOpaque(ref!).takeUnretainedValue()
    if selfRef.progressBlock != nil {
        selfRef.progressBlock!(current, max)
    }
}
