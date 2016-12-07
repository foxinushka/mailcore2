import Foundation

public class IMAPIdentity {
    
    internal var nativeInstance:CIMAPIdentity;
    
    public init(vendor: String, name: String, version: String) {
        self.nativeInstance = vendor.utf16({ vendorPtr in
            name.utf16({ namePtr in
                version.utf16({ versionPtr in
                    newCIMAPIdentity(vendorPtr, namePtr, versionPtr);
                })
            })
        })
    }
    
    internal init(_ identity:CIMAPIdentity) {
        self.nativeInstance = identity;
    }
    
    deinit {
        deleteCIMAPIdentity(self.nativeInstance);
    }
    
    /** Vendor of the IMAP client */
    public var vendor: String? {
        get { return String(utf16: nativeInstance.vendor(nativeInstance)); }
        set { newValue?.utf16({ nativeInstance.setVendor(nativeInstance, $0) }) }
    }
    
    /** Name of the IMAP client */
    public var name: String? {
        get { return String(utf16: nativeInstance.name(nativeInstance)); }
        set { newValue?.utf16({ nativeInstance.setName(nativeInstance, $0) }) }
    }
    
    /** Version of the IMAP client */
    public var version: String? {
        get { return String(utf16: nativeInstance.version(nativeInstance)); }
        set { newValue?.utf16({ nativeInstance.setVersion(nativeInstance, $0) }) }
    }
    
    /** All fields names of the identity of the client */
    public func allInfoKeys() -> [String] {
        return Array<String>.cast(nativeInstance.allInfoKeys(nativeInstance))
    }
    
    /** Set a custom field in the identity */
    public func infoForKey(_ key: String) -> String? {
        return key.utf16({ String(utf16: nativeInstance.infoForKey(nativeInstance, $0)) })
    }
    
    /** Retrieve a custom field in the identity */
    public func setInfo(_ value: String, forKey key: String) {
        value.utf16({ valuePtr in
            key.utf16({ keyPtr in
                nativeInstance.setInfoForKey(nativeInstance, valuePtr, keyPtr)
            })
        })
    }
    
    /** Remove all info keys including vendor, name and version */
    public func removeAllInfos() {
        nativeInstance.removeAllInfos(nativeInstance)
    }
    
}
