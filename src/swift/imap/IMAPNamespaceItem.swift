import Foundation


public class IMAPNamespaceItem {
    
    private var nativeInstance:CIMAPNamespaceItem;
    
    internal func CIMAPNamespaceItem() -> CIMAPNamespaceItem {
        return nativeInstance;
    }
    
    internal init(namespace:CIMAPNamespaceItem) {
        self.nativeInstance = namespace;
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** This is the prefix for this namespace item */
    public var prefix: String? {
        get { return String(utf16: nativeInstance.prefix) }
        set { String.utf16(newValue, { nativeInstance.prefix = $0 }) }
    }
    
    /** This is the delimiter of the path for this namespace item */
    public var delimiter: CChar {
        get { return nativeInstance.delimiter }
        set { nativeInstance.delimiter = newValue }
    }
    
    /** Returns folder path for given path components in the context of this namespace item */
    public func path(component: Array<String>) -> String? {
        return String(utf16: nativeInstance.pathForComponents(components: Array<String>.cast(component)));
    }
    
    /** Returns components for the given path in the context of this namespace */
    public func components(path: String) -> Array<String> {
        return Array<String>.cast( String.utf16(path, { nativeInstance.componentForPath(path: $0) }));
    }
    
    /** Returns YES if the namespace contains this folder path */
    public func containsFolder(folder: String) -> Bool {
        return String.utf16(folder, { nativeInstance.containsFolder(folder: $0) })
    }

}
