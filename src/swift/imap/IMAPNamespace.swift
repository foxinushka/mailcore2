import Foundation


public class MCOIMAPNamespace : Convertible {

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
    static func namespace(prefix: String, delimiter: CChar) -> MCOIMAPNamespace {
        return MCOIMAPNamespace(namespace: CIMAPNamespace(prefix: prefix.mailCoreString(), delimiter: delimiter))
    }
    
    /** Returns the prefix of the main item of this namespace. */
    public func mainPrefix() -> String? {
        return nativeInstance.mainPrefix().string()
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
        return nativeInstance.pathForComponents(components: Array<String>.cast(components)).string()
    }
    
    /**
     Returns the folder path for the given list of path components and a prefix.
     It will use the best item matching the prefix to compute the path.
     */
    public func path(components: Array<String>, prefix: String) -> String? {
        return nativeInstance.pathForComponentsAndPrefix(components: Array<String>.cast(components), prefix: prefix.mailCoreString()).string()
    }
    
    /** Returns the components given a folder path. */
    public func componentsFromPath(path: String) -> Array<String> {
        return Array<String>.cast(nativeInstance.componentsFromPath(path: path.mailCoreString()))
    }
    
    /** Returns YES if the namespace contains the given folder path. */
    public func containsFolderPath(path: String) -> Bool {
        return nativeInstance.containsFolderPath(path: path.mailCoreString())
    }
    
    func cast() -> CObject {
        return nativeInstance.castToCObject()
    }
    
    public required init(cobject obj: CObject) {
        self.nativeInstance = CIMAPNamespace(cobject: obj)
    }
}
