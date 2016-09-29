import Foundation

public class ImapNamespace {
	
	private var nativeInstance:CIMAPNamespace;
    
    internal func CIMAPNamespace() -> CIMAPNamespace {
        return nativeInstance;
    }

    internal init(namespace:CIMAPNamespace) {
        self.nativeInstance = namespace;
    }
    
    deinit {
        deleteCIMAPNamespace(self.nativeInstance);
    }
    
    /**
     Returns a simple namespace with only one item.
     */
    static func namespace(prefix: String, delimiter: CChar) -> ImapNamespace {
        return ImapNamespace(namespace: newCIMAPNamespace(prefix.utf16CString, delimiter));
    }
    
    /** Returns the prefix of the main item of this namespace. */
    public func mainPrefix() -> String {
        return String(utf16: nativeInstance.mainPrefix(nativeInstance)!)!;
    }
    
    /** Returns the path delimiter of the main item of this namespace */
    public func mainDelimiter() -> CChar {
        return nativeInstance.mainDelimiter(nativeInstance);
    }
    
    /** Returns the list of prefixes of this namespace. */
    public func prefixes() -> Array<Any> {
        return arrayFromC(nativeInstance.prefixes(nativeInstance));
    }
    
    /**
     Returns the folder path for the given list of path components in the context
     of the main item of the namespace.
     */
    public func path(components: Array<Any>) -> String {
        return String(utf16: nativeInstance.pathForComponents(nativeInstance, cArray(components))!)!;
    }
    
    /**
     Returns the folder path for the given list of path components and a prefix.
     It will use the best item matching the prefix to compute the path.
     */
    public func path(components: Array<Any>, prefix: String) -> String {
        return String(utf16: nativeInstance.pathForComponentsAndPrefix(nativeInstance, cArray(components), prefix.utf16CString)!)!;
    }
    
    /** Returns the components given a folder path. */
    public func componentsFromPath(path: String) -> Array<Any> {
        return arrayFromC(nativeInstance.componentsFromPath(nativeInstance, path.utf16CString));
    }
    
    /** Returns YES if the namespace contains the given folder path. */
    public func containsFolderPath(path: String) -> Bool {
        return nativeInstance.containsFolderPath(nativeInstance, path.utf16CString);
    }
}
