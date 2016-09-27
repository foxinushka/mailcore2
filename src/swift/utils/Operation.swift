import Foundation

class Operation {
    
    internal var nativeInstance: COperation;
    private var _started: Bool = false;
    
    internal init(cOperation: COperation) {
        self.nativeInstance = cOperation;
        self.nativeInstance.setCompletionBlock(&nativeInstance, operationCompleted);
    }
    
    /** Returns whether the operation is cancelled.*/
    public var isCancelled: Bool {
        get { return nativeInstance.isCanceled(&nativeInstance); }
    }
    
    /** Returns whether the operation should run even if it's cancelled.*/
    public var shouldRunWhenCancelled: Bool {
        get { return nativeInstance.shouldRunWhenCancelled(&nativeInstance); }
        set { nativeInstance.setShouldRunWhenCancelled(&nativeInstance, newValue); }
    }
    
    /** This methods is called on the main thread when the asynchronous operation is finished.
     Needs to be overriden by subclasses.*/
    public func operationCompleted() {
    
    }
    
    /** Cancel the operation.*/
    public func cancel() {
        if (_started) {
            _started = false;
            //[self release];
        }
        nativeInstance.cancel(&nativeInstance);
    }
    
    internal func start(){
        _started = true;
        //[self retain];
        nativeInstance.start(&nativeInstance);
    }
}
