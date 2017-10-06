import Foundation
import CMailCore

@objcMembers
public class MCOIMAPFolder: NSObject, Convertible {
    
    internal var nativeInstance:CIMAPFolder;
    
    func cast() -> CObject {
        return nativeInstance.toCObject()
    }
    
    public required init(mailCoreObject obj: CObject) {
        self.nativeInstance = CIMAPFolder.init(cobject: obj)
        self.nativeInstance.retain()
    }
    
    deinit {
        self.nativeInstance.release()
    }

    /** The folder's path, like for example INBOX.Archive */
    public var path: String? {
        get { return nativeInstance.path.string() }
        set { nativeInstance.path = newValue?.mailCoreString() ?? MailCoreString() }
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
    public var flags: MCOIMAPFolderFlag {
        get { return MCOIMAPFolderFlag(cIMAPFolderFlag: nativeInstance.flags) }
        set { nativeInstance.flags = newValue.toCIMAPFolderFlag() }
    }
    

}
