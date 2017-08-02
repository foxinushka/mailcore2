import Foundation


public class MCOIMAPMessagePart : MCOAbstractMessagePart {
    
    private var nativeInstance:CIMAPMessagePart;
    
    // public for smartmailcore
    public init(part:CIMAPMessagePart) {
        self.nativeInstance = part;
        super.init(abstractMessagePart: part.abstractMessagePart);
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
