import Foundation
import CCore

public class IMAPMultipart : AbstractMultipart {
    
    private var nativeInstance:CIMAPMultipart;
    
    internal init(part:CIMAPMultipart) {
        self.nativeInstance = part;
        super.init(abstractMultipart: part.abstractMultipart);
    }
    
    required public init(_ obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return String(utf16: nativeInstance.partID) }
        set { String.utf16(newValue, { nativeInstance.partID = $0 }) }
    }
    
}
