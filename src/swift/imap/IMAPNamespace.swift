import Foundation
import CMailCore

public class MCOIMAPNamespace : Convertible {

	var nativeInstance:CIMAPNamespace;
    
    func cast() -> CObject {
        return nativeInstance.toCObject()
    }
    
    public required init(mailCoreObject obj: CObject) {
        self.nativeInstance = CIMAPNamespace(cobject: obj)
        self.nativeInstance.retain()
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /**
     Returns a simple namespace with only one item.
     */
    static func namespace(prefix: String, delimiter: CChar) -> MCOIMAPNamespace? {
        let namespace = CIMAPNamespace.namespaceWithPrefix(prefix.mailCoreString(), delimiter)
        guard namespace.instance != nil else {
            return nil
        }
        return MCOIMAPNamespace(mailCoreObject: namespace.toCObject())
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
    public func prefixes() -> Array<String>? {
        return Array<String>(mailCoreArray: nativeInstance.prefixes());
    }
    
    /**
     Returns the folder path for the given list of path components in the context
     of the main item of the namespace.
     */
    public func path(components: Array<String>) -> String? {
        return nativeInstance.pathForComponents(components.mailCoreArray()).string()
    }
    
    /**
     Returns the folder path for the given list of path components and a prefix.
     It will use the best item matching the prefix to compute the path.
     */
    public func path(components: Array<String>, prefix: String) -> String? {
        return nativeInstance.pathForComponentsAndPrefix(components.mailCoreArray(), prefix.mailCoreString()).string()
    }
    
    /** Returns the components given a folder path. */
    public func componentsFromPath(path: String) -> Array<String>? {
        return Array<String>(mailCoreArray: nativeInstance.componentsFromPath(path.mailCoreString()))
    }
    
    /** Returns YES if the namespace contains the given folder path. */
    public func containsFolderPath(path: String) -> Bool {
        return nativeInstance.containsFolderPath(path.mailCoreString())
    }
}
