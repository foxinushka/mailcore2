import Foundation

public final class Address : Hashable, Convertible {
    
    private var nativeInstance:CAddress;
    
    /** Creates an address with a display name and a mailbox.
     
     Example: [MCOAddress addressWithDisplayName:@"DINH Viêt Hoà" mailbox:@"hoa@etpan.org"] */
    public static func addressWithDisplayName(displayName: String, mailbox: String) -> Address? {
        let address = Address(address: CaddressWithDisplayName(displayName.utf16CString, mailbox.utf16CString));
        return address.nativeInstance.instance != nil ? address : nil;
    }
    
    /** Creates an address with only a mailbox.
     
     Example: [MCOAddress addressWithMailbox:@"hoa@etpan.org"]*/
    public static func addressWithMailbox(mailbox: String) -> Address? {
        let address = Address(address: CaddressWithMailbox(mailbox.utf16CString));
        return address.nativeInstance.instance != nil ? address : nil;
    }

    /** Creates an address with a RFC822 string.
     
     Example: [MCOAddress addressWithRFC822String:@"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"]*/
    public static func addressWithRFC822String(RFC822String: String) -> Address? {
        let address = Address(address: CaddressWithRFC822String(RFC822String.utf16CString));
        return address.nativeInstance.instance != nil ? address : nil;
    }

    /** Creates an address with a non-MIME-encoded RFC822 string.
     
     Example: [MCOAddress addressWithNonEncodedRFC822String:@"DINH Viêt Hoà <hoa@etpan.org>"]*/
    public static func addressWithNonEncodedRFC822String(nonEncodedRFC822String: String) -> Address? {
        let address = Address(address: CaddressWithNonEncodedRFC822String(nonEncodedRFC822String.utf16CString));
        return address.nativeInstance.instance != nil ? address : nil;
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of the RFC822 encoded addresses.
     
     For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]*/
    public static func addressesWithRFC822String(string: String) -> Array<Address> {
        return Array<Address>.cast(CaddressesWithRFC822String(string.utf16CString));
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of non-encoded RFC822 addresses.
     
     For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]*/
    public static func addressesWithNonEncodedRFC822String(string: String) -> Array<Address> {
        return Array<Address>.cast(CaddressesWithNonEncodedRFC822String(string.utf16CString));
    }
    
    public init() {
        self.nativeInstance = newCAddress();
    }
    
    internal init(address:CAddress) {
        self.nativeInstance = address;
    }
    
    deinit {
        deleteCAddress(self.nativeInstance);
    }
    
    public var displayName : String? {
        set { self.nativeInstance.setDisplayName(nativeInstance, newValue?.utf16CString); }
        get { return String(utf16: self.nativeInstance.displayName(self.nativeInstance)!); }
    }
    
    public var mailbox : String? {
        set { self.nativeInstance.setMailbox(nativeInstance, newValue?.utf16CString); }
        get { return String(utf16: self.nativeInstance.mailbox(self.nativeInstance)!); }
    }
    
    public func RFC822String() -> String? {
        return String(utf16: nativeInstance.RFC822String(nativeInstance)!);
    }
    
    public func nonEncodedRFC822String() -> String? {
        return String(utf16: nativeInstance.nonEncodedRFC822String(nativeInstance)!);
    }
    
    public var hashValue: Int {
        return (String(utf16: nativeInstance.displayName(nativeInstance)!)?.hashValue)! ^ (String(utf16: nativeInstance.mailbox(nativeInstance)!)?.hashValue)!;
    }
    
    public static func ==(lhs: Address, rhs: Address) -> Bool {
        return String(utf16: lhs.nativeInstance.displayName(lhs.nativeInstance)!) == String(utf16: rhs.nativeInstance.displayName(rhs.nativeInstance)!) &&
            String(utf16: lhs.nativeInstance.mailbox(lhs.nativeInstance)!) == String(utf16: rhs.nativeInstance.mailbox(rhs.nativeInstance)!);
    }
    
    internal init(_ obj: CObject) {
        self.nativeInstance = castCAddress(obj);
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject(nativeInstance);
    }
    
}

