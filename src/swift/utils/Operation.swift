import Foundation
import Dispatch

public class Operation {
    
    internal var nativeInstance: COperation;
    private var _started: Bool = false;
    
    internal init(_ cOperation: COperation) {
        self.nativeInstance = cOperation;
        self.nativeInstance = cOperation.setCompletionBlock(cOperation, operationCompletedCallback, Unmanaged.passUnretained(self).toOpaque())
    }
    
    deinit {
        deleteCOperation(nativeInstance);
    }
    
    /** The queue this operation dispatches the callback on.  Defaults to the main queue.
     This property should be used only if there's performance issue creating or calling the callback
     in the main thread. */
    public var callbackDispatchQueue: DispatchQueue? {
        get {
            #if os(Android)
                //This property is ignored for Android
                return nil;
            #else
                return nativeInstance.callbackDispatchQueue(nativeInstance);
            #endif
        }
        set {
            #if os(Android)
            #else
                nativeInstance.setCallbackDispatchQueue(nativeInstance, newValue);
            #endif
        }
        
    }
    
    /** Returns whether the operation is cancelled.*/
    public var isCancelled: Bool {
        get { return nativeInstance.isCanceled(nativeInstance); }
    }
    
    /** Returns whether the operation should run even if it's cancelled.*/
    public var shouldRunWhenCancelled: Bool {
        get { return nativeInstance.shouldRunWhenCancelled(nativeInstance); }
        set { nativeInstance.setShouldRunWhenCancelled(nativeInstance, newValue); }
    }
    
    /** This methods is called on the main thread when the asynchronous operation is finished.
     Needs to be overriden by subclasses.*/
    public func operationCompleted() {
    
    }
    
    /** Cancel the operation.*/
    public func cancel() {
        if (_started) {
            _started = false;
        }
        nativeInstance.cancel(nativeInstance);
    }
    
    internal func start(){
        _started = true;
        nativeInstance.start(nativeInstance);
    }
}

//MARK: C Functions
public func operationCompletedCallback(ref: UnsafeRawPointer?) {
    let retained = Unmanaged<Operation>.fromOpaque(ref!).takeUnretainedValue()
    retained.operationCompleted()
}
