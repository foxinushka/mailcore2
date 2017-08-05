import Foundation


public class MCOAbstractMultipart : MCOAbstractPart {
    
    private var nativeInstance: CAbstractMultipart;
    
    required public init(mailCoreObject obj: CObject) {
        self.nativeInstance = CAbstractMultipart(cobject: obj)
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    internal override func cast() -> CObject {
        return nativeInstance.toCObject();
    }
    
    /** Returns the subparts of that multipart.*/
    public var parts : Array<MCOAbstractPart> {
        set { nativeInstance.parts = Array<MCOAbstractPart>.cast(newValue) }
        get { return Array<MCOAbstractPart>.cast(nativeInstance.parts) }
    }
    
}
