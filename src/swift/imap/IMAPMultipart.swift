import Foundation


public class MCOIMAPMultipart : MCOAbstractMultipart {
    
    private var nativeInstance:CIMAPMultipart;
    
    // public for SmartMailCore
    public init(part:CIMAPMultipart) {
        self.nativeInstance = part;
        super.init(abstractMultipart: part.abstractMultipart);
    }
    
    required public init(cobject obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return nativeInstance.partID.string() }
        set { nativeInstance.partID = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
}
