import Foundation

public class ImapPart : AbstractPart {
    
    private var nativeInstance:CIMAPPart;
    
    internal init(part:CIMAPPart) {
        self.nativeInstance = part;
        super.init(part.abstractPart);
    }
    
    required public init(_ obj: CObject) {
        let part = castCIMAPPart(obj);
        self.nativeInstance = part;
        super.init(part.abstractPart);
    }
    
    deinit {
        
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String {
        get { return String(utf16: nativeInstance.partID(nativeInstance)!)!; }
        set { nativeInstance.setPartID(nativeInstance, newValue.utf16CString); }
    }
    
    /** The size of the single part in bytes */
    public var size: UInt32 {
        get { return nativeInstance.size(nativeInstance); }
        set { nativeInstance.setSize(nativeInstance, newValue); }
    }
    
    /** It's the encoding of the single part */
    public var encoding: Encoding {
        get { return nativeInstance.encoding(nativeInstance); }
        set { nativeInstance.setEncoding(nativeInstance, newValue); }
    }
    
    /**
     Returns the decoded size of the part.
     For example, for a part that's encoded with base64, it will return actual_size * 3/4.
     */
    public func decodedSize() -> UInt32 {
        return nativeInstance.decodedSize(nativeInstance);
    }
    
}
