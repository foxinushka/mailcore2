import Foundation
import CCore

public class IMAPIdentity {
    
    internal var nativeInstance:CIMAPIdentity;
    
    public init(vendor: String, name: String, version: String) {
        self.nativeInstance = String.utf16(vendor, name, { vendorPtr, namePtr in
            String.utf16(version, { versionPtr in
                CIMAPIdentity(vendor: vendorPtr, name: namePtr, version: versionPtr);
            })
        })
    }
    
    internal init(_ identity:CIMAPIdentity) {
        self.nativeInstance = identity;
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** Vendor of the IMAP client */
    public var vendor: String? {
        get { return String(utf16: nativeInstance.vendor); }
        set { String.utf16(newValue, { nativeInstance.vendor = $0 }) }
    }
    
    /** Name of the IMAP client */
    public var name: String? {
        get { return String(utf16: nativeInstance.name) }
        set { String.utf16(newValue, { nativeInstance.name = $0 }) }
    }
    
    /** Version of the IMAP client */
    public var version: String? {
        get { return String(utf16: nativeInstance.version) }
        set { String.utf16(newValue, { nativeInstance.version = $0 }) }
    }
    
    /** All fields names of the identity of the client */
    public func allInfoKeys() -> [String] {
        return Array<String>.cast(nativeInstance.allInfoKeys())
    }
    
    /** Set a custom field in the identity */
    public func infoForKey(_ key: String) -> String? {
        return String.utf16(key, { String(utf16: nativeInstance.infoForKey(key: $0)) })
    }
    
    /** Retrieve a custom field in the identity */
    public func setInfo(_ value: String, forKey key: String) {
        String.utf16(value, key, { valuePtr, keyPtr in
            nativeInstance.setInfoForKey(value: valuePtr, key: keyPtr)
        })
    }
    
    /** Remove all info keys including vendor, name and version */
    public func removeAllInfos() {
        nativeInstance.removeAllInfos()
    }
    
}
