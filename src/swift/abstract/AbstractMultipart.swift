import Foundation

public class AbstractMultipart : AbstractPart {
    
    var abstractMultipart: CAbstractMultipart;
    
    init(abstractMultipart: CAbstractMultipart) {
        self.abstractMultipart = abstractMultipart;
        super.init(abstractMultipart.abstractPart);
    }
    
    required public init(_ obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    public var parts : Array<AbstractPart> {
        set { abstractMultipart.setParts(abstractMultipart, Array<AbstractPart>.cast(newValue)); }
        get { return Array<AbstractPart>.cast(abstractMultipart.parts(abstractMultipart)); }
    }
    
}
