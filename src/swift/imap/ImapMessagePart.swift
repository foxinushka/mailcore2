import Foundation

public class ImapMessagePart : AbstractMessagePart {
    
    private var nativeInstance:CIMAPMessagePart;
    
    internal init(part:CIMAPMessagePart) {
        self.nativeInstance = part;
        super.init(abstractMessagePart: part.abstractMessagePart);
    }
    
    deinit {
        
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String {
        get { return String(utf16: nativeInstance.partID(&nativeInstance)!)!; }
        set { nativeInstance.setPartID(&nativeInstance, newValue.utf16CString); }
    }
    
}
