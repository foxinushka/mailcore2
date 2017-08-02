import Foundation


public class MCOAbstractMultipart : MCOAbstractPart {
    
    private var nativeInstance: CAbstractMultipart;
    
    internal init(abstractMultipart: CAbstractMultipart) {
        self.nativeInstance = abstractMultipart;
        super.init(abstractMultipart.abstractPart);
    }
    
    required public init(cobject obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** Returns the subparts of that multipart.*/
    public var parts : Array<MCOAbstractPart> {
        set { nativeInstance.parts = Array<MCOAbstractPart>.cast(newValue) }
        get { return Array<MCOAbstractPart>.cast(nativeInstance.parts) }
    }
    
}
