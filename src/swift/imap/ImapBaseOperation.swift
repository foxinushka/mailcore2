import Foundation

public class ImapBaseOperation : Operation {
    
    public typealias OperationProgressBlock = (UInt32, UInt32) -> Void
    public typealias OperationItemProgressBlock = (UInt32) -> Void
    
    internal var baseOperation: CIMAPBaseOperation;
    public var session: ImapSession?;
    
    internal init(baseOperation: CIMAPBaseOperation) {
        self.baseOperation = baseOperation;
        super.init(baseOperation.cOperation);
        self.baseOperation = self.baseOperation.setProgressBlocks(self.baseOperation, itemProgress, bodyProgress);
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
