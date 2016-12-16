import Foundation

public class IMAPFolder: Convertible {
    
    internal var nativeInstance:CIMAPFolder;
    
    internal init(folder:CIMAPFolder) {
        self.nativeInstance = folder;
    }
    
    deinit {
        deleteCIMAPFolder(self.nativeInstance);
    }

    /** The folder's path, like for example INBOX.Archive */
    public var path: String? {
        get { return String(utf16: nativeInstance.path(nativeInstance)); }
        set { String.utf16(newValue, { nativeInstance.setPath(nativeInstance, $0) }) }
    }

    /** It's the delimiter for each component of the path. Commonly . or / */
    public var delimiter: CChar {
        get { return nativeInstance.delimiter(nativeInstance); }
        set { nativeInstance.setDelimiter(nativeInstance, newValue); }
    }

    /**
     Any flags the folder may have, like if the folder is for Drafts, Spam, Junk, etc. Or
     it could be marked with metadata like that it has no children.
     */
    public var flags: IMAPFolderFlag {
        get { return nativeInstance.flags(nativeInstance); }
        set { nativeInstance.setFlags(nativeInstance, newValue); }
    }
    
    func cast() -> CObject {
        return nativeInstance.castToCObject(nativeInstance)
    }
    
    public required init(_ obj: CObject) {
        self.nativeInstance = CIMAPFolderCastFromCObject(obj)
    }

}
