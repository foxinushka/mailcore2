import Foundation
import Dispatch
import CMailCore

public class MCOOperation: NSObjectCompat {
    
    internal var nativeInstance: COperation!
    
    private let startedPropertyLock = NSLock()
    fileprivate var _started: Bool = false
    
    internal init(_ cOperation: COperation) {
        super.init()
        self.nativeInstance = cOperation
        self.nativeInstance.retain()
        self.nativeInstance = cOperation.setCompletionBlock(operationCompletedCallback, Unmanaged.passUnretained(self).toOpaque())
    }
    
    deinit {
        nativeInstance.release()
    }
    
    /** The queue this operation dispatches the callback on.  Defaults to the main queue.
     This property should be used only if there's performance issue creating or calling the callback
     in the main thread. */
    public var callbackDispatchQueue: DispatchQueue? {
        get {
            return DispatchQueue.queueFromWrapped(nativeInstance.callbackDispatchQueue())
        }
        set {
            nativeInstance.setCallbackDispatchQueue(newValue?.wrapped)
        }
    }
    
    /** Returns whether the operation is cancelled.*/
    public var isCancelled: Bool {
        get { return nativeInstance.isCancelled(); }
    }
    
    /** Returns whether the operation should run even if it's cancelled.*/
    public var shouldRunWhenCancelled: Bool {
        get { return nativeInstance.shouldRunWhenCancelled; }
        set { nativeInstance.shouldRunWhenCancelled = newValue; }
    }
    
    /** This methods is called on the main thread when the asynchronous operation is finished.
     Needs to be overriden by subclasses.*/
    public func operationCompleted() {
        
    }
    
    /** Cancel the operation.*/
    public func cancel() {
        // cancel first, because MCOperationQueue.cpp check isCancelled() before call completion
        // which will call operationCompletedCallback, which causes to access to deallocated object
        nativeInstance.cancel();
        
        releaseOnComplete()
    }
    
    internal func start() {
        startedPropertyLock.lock()
        assert(_started == false)
        _started = true;
        // Unbalanced retain
        let _ = Unmanaged<MCOOperation>.passRetained(self)
        startedPropertyLock.unlock()
        nativeInstance.start();
    }
    
    fileprivate func releaseOnComplete() {
        startedPropertyLock.lock()
        if _started {
            _started = false
            // Unbalanced release
            Unmanaged<MCOOperation>.passUnretained(self).release()
        }
        startedPropertyLock.unlock()
    }
    
#if os(Android)
    public static func setMainQueue(_ mainQueue: DispatchQueue) {
        CObject.setMainQueue(mainQueue.wrapped)
    }
#endif
}

//MARK: C Functions
public func operationCompletedCallback(ref: UnsafeRawPointer?) {
    guard let ref = ref else {
        assert(false)
        return
    }
    
    let unmanagedSelf = Unmanaged<MCOOperation>.fromOpaque(ref)
    let selfRef = unmanagedSelf.takeUnretainedValue()
    selfRef.operationCompleted()
    selfRef.releaseOnComplete()
}
