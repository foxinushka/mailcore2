import Foundation


public class IMAPNamespace : Convertible {

	private var nativeInstance:CIMAPNamespace;
    
    internal func _CIMAPNamespace() -> CIMAPNamespace {
        return nativeInstance;
    }

    internal init(namespace:CIMAPNamespace) {
        self.nativeInstance = namespace;
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /**
     Returns a simple namespace with only one item.
     */
    static func namespace(prefix: String, delimiter: CChar) -> IMAPNamespace {
        return IMAPNamespace(namespace: String.utf16(prefix, { CIMAPNamespace(prefix: $0, delimiter: delimiter) }));
    }
    
    /** Returns the prefix of the main item of this namespace. */
    public func mainPrefix() -> String? {
        return String(utf16: nativeInstance.mainPrefix());
    }
    
    /** Returns the path delimiter of the main item of this namespace */
    public func mainDelimiter() -> CChar {
        return nativeInstance.mainDelimiter();
    }
    
    /** Returns the list of prefixes of this namespace. */
    public func prefixes() -> Array<String> {
        return Array<String>.cast(nativeInstance.prefixes());
    }
    
    /**
     Returns the folder path for the given list of path components in the context
     of the main item of the namespace.
     */
    public func path(components: Array<String>) -> String? {
        return String(utf16: nativeInstance.pathForComponents(components: Array<String>.cast(components)));
    }
    
    /**
     Returns the folder path for the given list of path components and a prefix.
     It will use the best item matching the prefix to compute the path.
     */
    public func path(components: Array<String>, prefix: String) -> String? {
        return String(utf16: String.utf16(prefix, { nativeInstance.pathForComponentsAndPrefix(components: Array<String>.cast(components), prefix: $0) }));
    }
    
    /** Returns the components given a folder path. */
    public func componentsFromPath(path: String) -> Array<String> {
        return Array<String>.cast(String.utf16(path, { nativeInstance.componentsFromPath(path: $0) }));
    }
    
    /** Returns YES if the namespace contains the given folder path. */
    public func containsFolderPath(path: String) -> Bool {
        return String.utf16(path, { nativeInstance.containsFolderPath(path: $0) })
    }
    
    func cast() -> CObject {
        return nativeInstance.castToCObject()
    }
    
    public required init(_ obj: CObject) {
        self.nativeInstance = CIMAPNamespace(cobject: obj)
    }
}
