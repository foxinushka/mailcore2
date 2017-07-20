import Foundation
import Dispatch
import CCore

public class Operation {
    
    internal var nativeInstance: COperation;
    private var _started: Bool = false;
    
    internal init(_ cOperation: COperation) {
        self.nativeInstance = cOperation;
        self.nativeInstance = cOperation.setCompletionBlock(block: operationCompletedCallback, userInfo: Unmanaged.passUnretained(self).toOpaque())
    }
    
    deinit {
        nativeInstance.release()
    }
    
    /** The queue this operation dispatches the callback on.  Defaults to the main queue.
     This property should be used only if there's performance issue creating or calling the callback
     in the main thread. */
    /*public var callbackDispatchQueue: DispatchQueue? {
        get {
            return nativeInstance.callbackDispatchQueue(nativeInstance);
        }
        set {
            nativeInstance.setCallbackDispatchQueue(nativeInstance, newValue);
        }
        
    }*/
    
    /** Returns whether the operation is cancelled.*/
    public var isCancelled: Bool {
        get { return nativeInstance.isCanceled(); }
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
        if (_started) {
            _started = false;
        }
        nativeInstance.cancel();
    }
    
    internal func start(){
        _started = true;
        nativeInstance.start();
    }
}

//MARK: C Functions
public func operationCompletedCallback(ref: UnsafeRawPointer?) {
    let selfRef = Unmanaged<Operation>.fromOpaque(ref!).takeUnretainedValue()
    selfRef.operationCompleted()
}
