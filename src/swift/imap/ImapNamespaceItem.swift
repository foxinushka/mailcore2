import Foundation

public class ImapNamespaceItem {
    
    private var nativeInstance:CIMAPNamespaceItem;
    
    internal func CIMAPNamespaceItem() -> CIMAPNamespaceItem {
        return nativeInstance;
    }
    
    internal init(namespace:CIMAPNamespaceItem) {
        self.nativeInstance = namespace;
    }
    
    deinit {
        deleteCIMAPNamespaceItem(self.nativeInstance);
    }
    
    /** This is the prefix for this namespace item */
    public var prefix: String {
        get { return String(utf16: nativeInstance.prefix(nativeInstance)!)!; }
        set { nativeInstance.setPrefix(nativeInstance, newValue.utf16CString); }
    }
    
    /** This is the delimiter of the path for this namespace item */
    public var delimiter: CChar {
        get { return nativeInstance.delimiter(nativeInstance); }
        set { nativeInstance.setDelimiter(nativeInstance, newValue); }
    }
    
    /** Returns folder path for given path components in the context of this namespace item */
    public func path(component: Array<Any>) -> String {
        return String(utf16: nativeInstance.pathForComponents(nativeInstance, cArray(component))!)!;
    }
    
    /** Returns components for the given path in the context of this namespace */
    public func components(path: String) -> Array<Any> {
        return arrayFromC(nativeInstance.componentForPath(nativeInstance, path.utf16CString));
    }
    
    /** Returns YES if the namespace contains this folder path */
    public func containsFolder(folder: String) -> Bool {
        return nativeInstance.containsFolder(nativeInstance, folder.utf16CString);
    }

}
