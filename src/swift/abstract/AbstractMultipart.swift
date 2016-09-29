import Foundation

public class AbstractMultipart : AbstractPart {
    
    var abstractMultipart: CAbstractMultipart;
    
    init(abstractMultipart: CAbstractMultipart) {
        self.abstractMultipart = abstractMultipart;
        super.init(abstractMultipart.abstractPart);
    }
    
    public var parts : Array<Any> {
        set { abstractMultipart.setParts(abstractMultipart, cArray(newValue)); }
        get { return arrayFromC(abstractMultipart.parts(abstractMultipart)); }
    }
    
}
