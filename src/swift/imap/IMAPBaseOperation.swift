import Foundation


public class MCOIMAPBaseOperation : MCOOperation {
    
    public typealias MCOOperationProgressBlock = (UInt32, UInt32) -> Void
    public typealias MCOOperationItemProgressBlock = (UInt32) -> Void
    
    internal var baseOperation: CIMAPBaseOperation;
    public var session: MCOIMAPSession?;
    
    internal init(baseOperation: CIMAPBaseOperation) {
        self.baseOperation = baseOperation;
        super.init(baseOperation.cOperation);
        self.baseOperation.cOperation = super.nativeInstance
        self.baseOperation = self.baseOperation.setProgressBlocks(itemProgressCallback,
                                                                  bodyProgressCallback,
                                                                  Unmanaged.passUnretained(self).toOpaque());
    }
    
    deinit {
        baseOperation.release()
    }
    
    internal func error() -> ErrorCode {
        return baseOperation.error()
    }
    
    public func itemProgress(current: UInt32, maximum: UInt32) {
        
    }
    
    public func bodyProgress(current: UInt32, maximum: UInt32) {
    
    }
}

//MARK: C Functions
public func itemProgressCallback(ref: UnsafeRawPointer?, current: UInt32, maximum: UInt32) {
    let selfRef = Unmanaged<MCOIMAPBaseOperation>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.itemProgress(current: current, maximum: maximum)
}

public func bodyProgressCallback(ref: UnsafeRawPointer?, current: UInt32, maximum: UInt32) {
    let selfRef = Unmanaged<MCOIMAPBaseOperation>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.bodyProgress(current: current, maximum: maximum)
}

