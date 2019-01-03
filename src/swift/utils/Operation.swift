import Foundation
import Dispatch
import CMailCore

public class MCOOperation: NSObjectCompat {
    
    internal var nativeInstance: COperation!
    
    internal init(_ cOperation: COperation) {
        super.init()
        nativeInstance = cOperation
        nativeInstance.retain()
        nativeInstance = nativeInstance.setCompletionBlock(operationCompletedCallback, Unmanaged.passUnretained(self).toOpaque())
    }
    
    deinit {
        nativeInstance = nativeInstance.clearCompletionBlock()
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
        
        _ = tryFinish(self)
    }
    
    internal func start() {
        guard tryStart(self) else {
            assert(false)
            return
        }
        
        nativeInstance.start();
    }
    
#if os(Android)
    public static func setMainQueue(_ mainQueue: DispatchQueue) {
        CObject.setMainQueue(mainQueue.wrapped)
    }
#endif
}

// MARK: - C Functions

public func operationCompletedCallback(ref: UnsafeRawPointer?) {
    guard let ref = ref else {
        assert(false)
        return
    }
    
    guard let operation = tryFinish(ref) else {
        return
    }
    
    operation.operationCompleted()
}

// MARK: - Scheduled logic helpers

private var scheduled = Set<UnsafeRawPointer>()
private let scheduledLock = NSLock()

private func tryStart(_ op: MCOOperation) -> Bool {
    let unmanaged = Unmanaged.passUnretained(op)
    let pointer = unmanaged.toOpaque()
    
    scheduledLock.lock()
    defer {
        scheduledLock.unlock()
    }
    
    if scheduled.contains(pointer) {
        return false
    }
    
    scheduled.insert(pointer)
    _ = unmanaged.retain()
    
    return true
}

private func tryFinish(_ op: MCOOperation) -> Bool {
    let unmanaged = Unmanaged.passUnretained(op)
    let pointer = unmanaged.toOpaque()
    
    scheduledLock.lock()
    defer {
        scheduledLock.unlock()
    }
    
    guard scheduled.contains(pointer) else {
        return false
    }
    
    scheduled.remove(pointer)
    _ = unmanaged.release()
    
    return true
}

private func tryFinish(_ pointer: UnsafeRawPointer) -> MCOOperation? {
    scheduledLock.lock()
    defer {
        scheduledLock.unlock()
    }
    
    guard scheduled.contains(pointer) else {
        return nil
    }
    
    let unmanaged = Unmanaged<MCOOperation>.fromOpaque(pointer)
    
    let operation = unmanaged.takeUnretainedValue()
    
    scheduled.remove(pointer)
    unmanaged.release()
    
    return operation
}
