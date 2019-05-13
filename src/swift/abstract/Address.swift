import Foundation
import CMailCore

public final class MCOAddress : NSObjectCompat, Convertible, NSCoding {
    
    var nativeInstance:CAddress
    
    public override init() {
        self.nativeInstance = CAddress_init();
        super.init()
    }
    
    private init?(address:CAddress) {
        guard address.instance != nil else {
            return nil
        }
        self.nativeInstance = address;
        self.nativeInstance.retain()
    }
    
    internal init(mailCoreObject obj: CObject) {
        self.nativeInstance = CAddress.init(cobject: obj)
        self.nativeInstance.retain()
    }
    
    deinit {
        self.nativeInstance.release();
    }
    
    internal func cast() -> CObject {
        return nativeInstance.toCObject()
    }
    
    public func isNil() -> Bool {
        return nativeInstance.instance == nil
    }
    
    /** Creates an address with a display name and a mailbox.
     
     Example: [MCOAddress addressWithDisplayName:@"DINH Viêt Hoà" mailbox:@"hoa@etpan.org"] */
    public convenience init?(displayName: String?, mailbox: String) {
        let autoreleasePool = CAutoreleasePool_init()
        defer {
            autoreleasePool.release()
        }
        let addrss = CAddress.addressWithDisplayName(displayName?.mailCoreString() ?? MailCoreString(), mailbox.mailCoreString())
        guard addrss.instance != nil else {
            return nil
        }
        self.init(address: addrss)
    }
    
    /** Creates an address with only a mailbox.
     
     Example: [MCOAddress addressWithMailbox:@"hoa@etpan.org"]*/
    public convenience init?(mailbox: String) {
        let autoreleasePool = CAutoreleasePool_init()
        defer {
            autoreleasePool.release()
        }
        let addrss = CAddress.addressWithMailbox(mailbox.mailCoreString())
        self.init(address: addrss)
    }

    /** Creates an address with a RFC822 string.
     
     Example: [MCOAddress addressWithRFC822String:@"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"]*/
    public convenience init?(RFC822String: String) {
        let autoreleasePool = CAutoreleasePool_init()
        defer {
            autoreleasePool.release()
        }
        let addrss = CAddress.addressWithRFC822String(RFC822String.mailCoreString())
        self.init(address: addrss)
    }

    /** Creates an address with a non-MIME-encoded RFC822 string.
     
     Example: [MCOAddress addressWithNonEncodedRFC822String:@"DINH Viêt Hoà <hoa@etpan.org>"]*/
    public convenience init?(nonEncodedRFC822String: String) {
        let autoreleasePool = CAutoreleasePool_init()
        defer {
            autoreleasePool.release()
        }
        let addrss = CAddress.addressWithNonEncodedRFC822String(nonEncodedRFC822String.mailCoreString())
        self.init(address: addrss)
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of the RFC822 encoded addresses.
     
     For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]*/
    public static func addressesWithRFC822String(string: String) -> Array<MCOAddress>? {
        return mailCoreAutoreleasePool {
            return Array<MCOAddress>(mailCoreArray: CAddress.addressesWithRFC822String(string.mailCoreString()))
        }
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of non-encoded RFC822 addresses.
     
     For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]*/
    public static func addressesWithNonEncodedRFC822String(string: String) -> Array<MCOAddress>? {
        return mailCoreAutoreleasePool {
            return Array<MCOAddress>(mailCoreArray: CAddress.addressesWithNonEncodedRFC822String(string.mailCoreString()))
        }
    }
    
    /** Returns the display name of the address.*/
    public var displayName : String? {
        set {
            mailCoreAutoreleasePool {
                self.nativeInstance.displayName = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                self.nativeInstance.displayName.string()
            }
        }
    }
    
    /** Returns the mailbox of the address.*/
    public var mailbox : String! {
        set {
            mailCoreAutoreleasePool {
                self.nativeInstance.mailbox = newValue.mailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                self.nativeInstance.mailbox.string()
            }
        }
    }
    
    /** Returns the RFC822 encoding of the address.
     
     For example: "DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"*/
    public func RFC822String() -> String? {
        return mailCoreAutoreleasePool {
            return nativeInstance.RFC822String.string()
        }
    }
    
    /** Returns the non-MIME-encoded RFC822 encoding of the address.
     
     For example: "DINH Viêt Hoà <hoa@etpan.org>"*/
    public func nonEncodedRFC822String() -> String? {
        return mailCoreAutoreleasePool {
            return nativeInstance.nonEncodedRFC822String.string()
        }
    }
    
    override public var hash: Int {
        if let displayName = displayName, let mailbox = mailbox {
            return displayName.hashValue ^ mailbox.hashValue
        }
        if let displayName = displayName {
            return displayName.hashValue
        }
        if let mailbox = mailbox {
            return mailbox.hashValue
        }
        return 0
    }

    public override func isEqual(_ object: Any?) -> Bool {
        guard let other = object as? MCOAddress else {
            return false
        }

        return self.displayName == other.displayName && self.mailbox == other.mailbox;
    }

    public static func ==(lhs: MCOAddress, rhs: MCOAddress) -> Bool {
        return lhs.isEqual(rhs)
    }
    
    public convenience init?(coder aDecoder: NSCoder) {
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

public extension Array where Element: MCOAddress {
    
    public func mco_RFC822StringForAddresses() -> String? {
        return CAddress.RFC822StringForAddresses(self.mailCoreArray()).string()
    }
    
    public func mco_nonEncodedRFC822StringForAddresses() -> String? {
        return CAddress.nonEncodedRFC822StringForAddresses(self.mailCoreArray()).string()
    }

}
