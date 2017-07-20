import Foundation
import CCore

public class IMAPFolder: Convertible {
    
    internal var nativeInstance:CIMAPFolder;
    
    internal init(folder:CIMAPFolder) {
        self.nativeInstance = folder;
    }
    
    deinit {
        self.nativeInstance.release()
    }

    /** The folder's path, like for example INBOX.Archive */
    public var path: String? {
        get { return String(utf16: nativeInstance.path ); }
        set { String.utf16(newValue, { nativeInstance.path = $0 }) }
    }

    /** It's the delimiter for each component of the path. Commonly . or / */
    public var delimiter: CChar {
        get { return nativeInstance.delimiter }
        set { nativeInstance.delimiter = newValue }
    }

    /**
     Any flags the folder may have, like if the folder is for Drafts, Spam, Junk, etc. Or
     it could be marked with metadata like that it has no children.
     */
    public var flags: IMAPFolderFlag {
        get { return nativeInstance.flags }
        set { nativeInstance.flags = newValue }
    }
    
    func cast() -> CObject {
        return nativeInstance.castToCObject()
    }
    
    public required init(_ obj: CObject) {
        self.nativeInstance = CIMAPFolder.init(cobject: obj)
    }

}
