import Foundation


public class MCOIMAPPart : MCOAbstractPart, NSCoding {
    
    private var nativeInstance:CIMAPPart;
    
    override func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    required public init(mailCoreObject obj: CObject) {
        let part = CIMAPPart(cobject: obj);
        self.nativeInstance = part;
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    deinit {
        self.nativeInstance.release()
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
    
    public convenience required init?(coder aDecoder: NSCoder) {
        guard let dict = aDecoder.decodeObject(forKey: "info") as? Dictionary<AnyHashable, Any> else {
            return nil
        }
        let serializable = dictionaryUnsafeCast(dict)
        self.init(mailCoreObject: CObject.objectWithSerializable(serializable))
        self.nativeInstance.retain()
    }
    
    public func encode(with aCoder: NSCoder) {
        let serialazable: CDictionary = self.cast().serializable()
        let dict = dictionaryUnsafeCast(serialazable)
        aCoder.encode(dict, forKey: "info")
    }
    
}
