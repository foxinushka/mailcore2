import Foundation

public class IMAPBaseOperation : Operation {
    
    public typealias OperationProgressBlock = (UInt32, UInt32) -> Void
    public typealias OperationItemProgressBlock = (UInt32) -> Void
    
    internal var baseOperation: CIMAPBaseOperation;
    public var session: IMAPSession?;
    
    internal init(baseOperation: CIMAPBaseOperation) {
        self.baseOperation = baseOperation;
        super.init(baseOperation.cOperation);
        self.baseOperation = self.baseOperation.setProgressBlocks(self.baseOperation, itemProgressCallback, bodyProgressCallback, Unmanaged.passUnretained(self).toOpaque());
    }
    
    deinit {
        deleteCIMAPBaseOperation(baseOperation);
    }
    
    internal func error() -> ErrorCode {
        return baseOperation.error(baseOperation);
    }
    
    public func itemProgress(current: UInt32, maximum: UInt32) {
        
    }
    
    public func bodyProgress(current: UInt32, maximum: UInt32) {
    
    }
}

//MARK: C Functions
public func itemProgressCallback(ref: UnsafeRawPointer?, current: UInt32, maximum: UInt32) {
    let selfRef = Unmanaged<IMAPBaseOperation>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.itemProgress(current: current, maximum: maximum)
}

public func bodyProgressCallback(ref: UnsafeRawPointer?, current: UInt32, maximum: UInt32) {
    let selfRef = Unmanaged<IMAPBaseOperation>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.bodyProgress(current: current, maximum: maximum)
}

