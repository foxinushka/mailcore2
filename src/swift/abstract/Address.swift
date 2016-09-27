import Foundation

class Address : Hashable {
    
    var nativeInstance:CAddress;
    
    /** Creates an address with a display name and a mailbox.
     
     Example: [MCOAddress addressWithDisplayName:@"DINH Viêt Hoà" mailbox:@"hoa@etpan.org"] */
    static func addressWithDisplayName(displayName: String, mailbox: String) -> Address {
        return Address(address: CaddressWithDisplayName(displayName.utf16CString, mailbox.utf16CString));
    }
    
    /** Creates an address with only a mailbox.
     
     Example: [MCOAddress addressWithMailbox:@"hoa@etpan.org"]*/
    static func addressWithMailbox(mailbox: String) -> Address {
        return Address(address: CaddressWithMailbox(mailbox.utf16CString));
    }

    /** Creates an address with a RFC822 string.
     
     Example: [MCOAddress addressWithRFC822String:@"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>"]*/
    static func addressWithRFC822String(RFC822String: String) -> Address {
        return Address(address: CaddressWithRFC822String(RFC822String.utf16CString));
    }

    /** Creates an address with a non-MIME-encoded RFC822 string.
     
     Example: [MCOAddress addressWithNonEncodedRFC822String:@"DINH Viêt Hoà <hoa@etpan.org>"]*/
    static func addressWithNonEncodedRFC822String(nonEncodedRFC822String: String) -> Address {
        return Address(address: CaddressWithNonEncodedRFC822String(nonEncodedRFC822String.utf16CString));
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of the RFC822 encoded addresses.
     
     For example: @[ @"DINH Vi=C3=AAt Ho=C3=A0 <hoa@etpan.org>" ]*/
    static func addressesWithRFC822String(string: String) -> Array<Any>? {
        return arrayFromC(CaddressesWithRFC822String(string.utf16CString));
    }

    /**
     Returns an NSArray of MCOAddress objects that contain the parsed
     forms of non-encoded RFC822 addresses.
     
     For example: @[ "DINH Viêt Hoà <hoa@etpan.org>" ]*/
    static func addressesWithNonEncodedRFC822String(string: String) -> Array<Any>? {
        return arrayFromC(CaddressesWithNonEncodedRFC822String(string.utf16CString));
    }
    
    init() {
        self.nativeInstance = newCAddress();
    }
    
    init(address:CAddress) {
        self.nativeInstance = address;
    }
    
    deinit {
        deleteCAddress(&self.nativeInstance);
    }
    
    var displayName : String? {
        set { self.nativeInstance.setDisplayName(&nativeInstance, newValue?.utf16CString); }
        get { return String(utf16: self.nativeInstance.displayName(&self.nativeInstance)!); }
    }
    
    var mailbox : String? {
        set { self.nativeInstance.setMailbox(&nativeInstance, newValue?.utf16CString); }
        get { return String(utf16: self.nativeInstance.mailbox(&self.nativeInstance)!); }
    }
    
    func RFC822String() -> String? {
        return String(utf16: nativeInstance.RFC822String(&nativeInstance)!);
    }
    
    func nonEncodedRFC822String() -> String? {
        return String(utf16: nativeInstance.nonEncodedRFC822String(&nativeInstance)!);
    }
    
    var hashValue: Int {
        return (String(utf16: nativeInstance.displayName(&nativeInstance)!)?.hashValue)! ^ (String(utf16: nativeInstance.mailbox(&nativeInstance)!)?.hashValue)!;
    }
    
    public static func ==(lhs: Address, rhs: Address) -> Bool {
        return String(utf16: lhs.nativeInstance.displayName(&lhs.nativeInstance)!) == String(utf16: rhs.nativeInstance.displayName(&rhs.nativeInstance)!) &&
            String(utf16: lhs.nativeInstance.mailbox(&lhs.nativeInstance)!) == String(utf16: rhs.nativeInstance.mailbox(&rhs.nativeInstance)!);
    }
    
}

