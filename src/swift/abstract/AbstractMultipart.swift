import Foundation

public class AbstractMultipart : AbstractPart {
    
    private var nativeInstance: CAbstractMultipart;
    
    internal init(abstractMultipart: CAbstractMultipart) {
        self.nativeInstance = abstractMultipart;
        super.init(abstractMultipart.abstractPart);
    }
    
    required public init(_ obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** Returns the subparts of that multipart.*/
    public var parts : Array<AbstractPart> {
        set { nativeInstance.setParts(nativeInstance, Array<AbstractPart>.cast(newValue)); }
        get { return Array<AbstractPart>.cast(nativeInstance.parts(nativeInstance)); }
    }
    
}
