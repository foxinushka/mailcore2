import Foundation

#if os(Android)
    import CMailCore
#endif

public class MCOIMAPNamespaceItem: Convertible {
    
    var nativeInstance:CIMAPNamespaceItem;
    
    public required init(mailCoreObject: CObject) {
        self.nativeInstance = CIMAPNamespaceItem.init(cobject: mailCoreObject)
        self.nativeInstance.retain()
    }
    
    func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** This is the prefix for this namespace item */
    public var prefix: String? {
        get { return nativeInstance.prefix.string() }
        set { nativeInstance.prefix = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** This is the delimiter of the path for this namespace item */
    public var delimiter: CChar {
        get { return nativeInstance.delimiter }
        set { nativeInstance.delimiter = newValue }
    }
    
    /** Returns folder path for given path components in the context of this namespace item */
    public func path(component: Array<String>) -> String? {
        return nativeInstance.pathForComponents(component.mailCoreArray()).string()
    }
    
    /** Returns components for the given path in the context of this namespace */
    public func components(path: String) -> Array<String>? {
        return Array<String>(mailCoreArray: nativeInstance.componentsForPath(path.mailCoreString()))
    }
    
    /** Returns YES if the namespace contains this folder path */
    public func containsFolder(folder: String) -> Bool {
        return nativeInstance.containsFolder(folder.mailCoreString())
    }

}
