import Foundation


public class MCOIMAPIdentity {
    
    internal var nativeInstance:CIMAPIdentity;
    
    public init(vendor: String, name: String, version: String) {
        self.nativeInstance = CIMAPIdentity(vendor: vendor.mailCoreString(), name: name.mailCoreString(), version: version.mailCoreString())
    }
    
    internal init(_ identity:CIMAPIdentity) {
        self.nativeInstance = identity;
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** Vendor of the IMAP client */
    public var vendor: String? {
        get { return nativeInstance.vendor.string() }
        set { nativeInstance.vendor = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** Name of the IMAP client */
    public var name: String? {
        get { return nativeInstance.name.string() }
        set { nativeInstance.name = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** Version of the IMAP client */
    public var version: String? {
        get { return nativeInstance.version.string() }
        set { nativeInstance.version = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** All fields names of the identity of the client */
    public func allInfoKeys() -> [String] {
        return Array<String>.cast(nativeInstance.allInfoKeys())
    }
    
    /** Set a custom field in the identity */
    public func infoForKey(_ key: String) -> String? {
        return nativeInstance.infoForKey(key: key.mailCoreString()).string()
    }
    
    /** Retrieve a custom field in the identity */
    public func setInfo(_ value: String, forKey key: String) {
        nativeInstance.setInfoForKey(value: value.mailCoreString(), key: key.mailCoreString())
    }
    
    /** Remove all info keys including vendor, name and version */
    public func removeAllInfos() {
        nativeInstance.removeAllInfos()
    }
    
}
