import Foundation


public final class MCOAddress : NSObject, Convertible {
    
    private var nativeInstance:CAddress;
    
    internal func getNativeInstance() -> CAddress {
        return self.nativeInstance;
    }
    
    public func isNil() -> Bool {
        return nativeInstance.instance == nil
    }
    
    /** Creates an address with a display name and a mailbox.
     
     Example: [MCOAddress addressWithDisplayName:@"DINH Viêt Hoà" mailbox:@"hoa@etpan.org"] */
    public convenience init?(displayName: String, mailbox: String) {
        let addrss = CAddress(displayName: displayName.mailCoreString(), mailbox: mailbox.mailCoreString())
        guard addrss.instance != nil else {
            return nil
        }
        self.init(address: addrss)
    }
    
    /** Creates an address with only a mailbox.
     
     Example: [MCOAddress addressWithMailbox:@"hoa@etpan.org"]*/
    public convenience init?(mailbox: String) {
        self.init(address: CAddress(mailbox: mailbox.mailCoreString()))
    }

    /** Creates an address with a RFC822 string.
     
     Example: [MCOAddress addressWithRFC822String:@"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"]*/
    public convenience init?(RFC822String: String) {
        self.init(address: CAddress(RFC822String: RFC822String.mailCoreString()))
    }

    /** Creates an address with a non-MIME-encoded RFC822 string.
     
     Example: [MCOAddress addressWithNonEncodedRFC822String:@"DINH Viêt Hoà <hoa@etpan.org>"]*/
    public convenience init?(nonEncodedRFC822String: String) {
        self.init(address: CAddress(nonEncodedRFC822String: nonEncodedRFC822String.mailCoreString()))
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of the RFC822 encoded addresses.
     
     For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]*/
    public static func addressesWithRFC822String(string: String) -> Array<MCOAddress> {
        return Array<MCOAddress>.cast(CAddress.addresses(RFC822String: string.mailCoreString()))
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of non-encoded RFC822 addresses.
     
     For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]*/
    public static func addressesWithNonEncodedRFC822String(string: String) -> Array<MCOAddress> {
        return Array<MCOAddress>.cast(CAddress.addresses(nonEncodedRFC822String: string.mailCoreString()))
    }
    
    public override init() {
        self.nativeInstance = CAddress_new();
        super.init()
    }
    
    internal init?(address:CAddress?) {
        guard let address = address else {
            return nil
        }
        self.nativeInstance = address;
    }
    
    deinit {
        self.nativeInstance.release();
    }
    
    /** Returns the display name of the address.*/
    public var displayName : String? {
        set { self.nativeInstance.displayName = newValue?.mailCoreString() ?? MailCoreString() }
        get { return self.nativeInstance.displayName.string() }
    }
    
    /** Returns the mailbox of the address.*/
    public var mailbox : String? {
        set { self.nativeInstance.mailbox = newValue?.mailCoreString() ?? MailCoreString() }
        get { return self.nativeInstance.mailbox.string() }
    }
    
    /** Returns the RFC822 encoding of the address.
     
     For example: "DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"*/
    public func RFC822String() -> String? {
        return nativeInstance.RFC822String.string()
    }
    
    /** Returns the non-MIME-encoded RFC822 encoding of the address.
     
     For example: "DINH Viêt Hoà <hoa@etpan.org>"*/
    public func nonEncodedRFC822String() -> String? {
        return nativeInstance.nonEncodedRFC822String.string()
    }
    
    public override var hashValue: Int {
        if displayName != nil && mailbox != nil {
            return displayName!.hashValue ^ mailbox!.hashValue;
        }
        if displayName != nil {
            return displayName!.hashValue;
        }
        if mailbox != nil {
            return mailbox!.hashValue;
        }
        return 0;
    }
    
    public static func ==(lhs: MCOAddress, rhs: MCOAddress) -> Bool {
        return lhs.displayName == rhs.displayName && lhs.mailbox == rhs.mailbox;
    }
    
    internal init(cobject obj: CObject) {
        self.nativeInstance = CAddress(cObject: obj);
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject()
    }
    
}

