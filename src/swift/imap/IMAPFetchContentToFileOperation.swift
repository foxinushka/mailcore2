import Foundation


public class MCOIMAPFetchContentToFileOperation : MCOIMAPBaseOperation {
    
    public typealias CompletionBlock = (Error?) -> Void
    
    internal var operation: CIMAPFetchContentToFileOperation
    private var completionBlock : CompletionBlock?
    
    internal init(operation:CIMAPFetchContentToFileOperation) {
        self.operation = operation
        super.init(baseOperation: operation.baseOperation)
    }
    
    deinit {
        completionBlock = nil;
    }
    
    public var isLoadingByChunksEnabled : Bool {
        get { return operation.isLoadingByChunksEnabled }
        set { operation.isLoadingByChunksEnabled = newValue }
    }
    
    public var chunksSize : UInt32 {
        get { return operation.chunksSize }
        set { operation.chunksSize = newValue }
    }
    
    public var estimatedSize : UInt32 {
        get { return operation.estimatedSize }
        set { operation.estimatedSize = newValue }
    }
    
    public func start(completionBlock: CompletionBlock?) {
        self.completionBlock = completionBlock
        start()
    }
    
    public override func cancel() {
        completionBlock = nil
        super.cancel()
    }
    
    public override func operationCompleted() {
        if (completionBlock == nil) {
            return
        }
        
        let errorCode = error()
        if errorCode == ErrorNone {
            completionBlock!(nil)
        }
        else {
            completionBlock!(MailCoreError(code: errorCode))
        }
        completionBlock = nil
    }
    
}
