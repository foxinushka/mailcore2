import Foundation
import CMailCore

public class MCOIMAPMessagePart : MCOAbstractMessagePart, NSCoding {
    
    private var nativeInstance:CIMAPMessagePart;
    
    required public init(mailCoreObject obj: CObject) {
        self.nativeInstance = CIMAPMessagePart.init(cobject: obj)
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    override func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return nativeInstance.partID.string() }
        set { nativeInstance.partID = newValue?.mailCoreString() ?? MailCoreString() }
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
