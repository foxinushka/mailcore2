import Foundation
import CMailCore

public class MCOIMAPFolderStatus: Convertible {
    
    private var nativeInstance:CIMAPFolderStatus;
    
    public required init(mailCoreObject: CObject) {
        self.nativeInstance = CIMAPFolderStatus.init(cobject: mailCoreObject)
        self.nativeInstance.retain()
    }
    
    func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** The folder's IMAP UIDNEXT value. Used to determine the uid for the next received message. */
    public var uidNext: UInt32 {
        get { return nativeInstance.uidNext }
        set { nativeInstance.uidNext = newValue }
    }
    
    /** The folders IMAP UIDVALIDITY value. Must be used to determine if the server has changed assigned UIDs */
    public var uidValidity: UInt32 {
        get { return nativeInstance.uidValidity }
        set { nativeInstance.uidValidity = newValue }
    }
    
    /** Number of recent messages received in the folder */
    public var recentCount: UInt32 {
        get { return nativeInstance.recentCount }
        set { nativeInstance.recentCount = newValue }
    }
    
    /** Number of unseen messages in the folder */
    public var unseenCount: UInt32 {
        get { return nativeInstance.unseenCount }
        set { nativeInstance.unseenCount = newValue }
    }
    
    /** Number of messages in the folder */
    public var messageCount: UInt32 {
        get { return nativeInstance.messageCount }
        set { nativeInstance.messageCount = newValue }
    }
    
    /** Highest modification sequence value for this folder. See CONDSTORE RFC 4551. */
    public var highestModSeqValue: UInt64 {
        get { return nativeInstance.highestModSeqValue }
        set { nativeInstance.highestModSeqValue = newValue }
    }
}
