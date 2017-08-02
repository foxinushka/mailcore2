import Foundation


public class MCOIMAPPart : MCOAbstractPart {
    
    private var nativeInstance:CIMAPPart;
    
    // public for SmartMailCore
    public init(part:CIMAPPart) {
        self.nativeInstance = part;
        super.init(part.abstractPart);
    }
    
    required public init(cobject obj: CObject) {
        let part = CIMAPPart(cobject: obj);
        self.nativeInstance = part;
        super.init(part.abstractPart);
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return nativeInstance.partID.string() }
        set { nativeInstance.partID = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** The size of the single part in bytes */
    public var size: UInt32 {
        get { return nativeInstance.size }
        set { nativeInstance.size = newValue }
    }
    
    /** It's the encoding of the single part */
    public var encoding: Encoding {
        get { return nativeInstance.encoding }
        set { nativeInstance.encoding = newValue }
    }
    
    /**
     Returns the decoded size of the part.
     For example, for a part that's encoded with base64, it will return actual_size * 3/4.
     */
    public func decodedSize() -> UInt32 {
        return nativeInstance.decodedSize();
    }
    
}
