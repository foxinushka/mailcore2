import Foundation

public class IMAPMessagePart : AbstractMessagePart {
    
    private var nativeInstance:CIMAPMessagePart;
    
    internal init(part:CIMAPMessagePart) {
        self.nativeInstance = part;
        super.init(abstractMessagePart: part.abstractMessagePart);
    }
    
    required public init(_ obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return String(utf16: nativeInstance.partID(nativeInstance)); }
        set { newValue?.utf16({ nativeInstance.setPartID(nativeInstance, $0) }) }
    }
    
}
