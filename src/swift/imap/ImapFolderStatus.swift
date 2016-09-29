import Foundation

public class ImapFolderStatus {
    
    private var nativeInstance:CIMAPFolderStatus;
    
    internal init(status: CIMAPFolderStatus) {
        self.nativeInstance = status;
    }
    
    deinit {
        deleteCIMAPFolderStatus(self.nativeInstance);
    }
    
    /** The folder's IMAP UIDNEXT value. Used to determine the uid for the next received message. */
    public var uidNext: UInt32 {
        get { return nativeInstance.uidNext(nativeInstance); }
        set { nativeInstance.setUidNext(nativeInstance, newValue); }
    }
    
    /** The folders IMAP UIDVALIDITY value. Must be used to determine if the server has changed assigned UIDs */
    public var uidValidity: UInt32 {
        get { return nativeInstance.uidValidity(nativeInstance); }
        set { nativeInstance.setUidValidity(nativeInstance, newValue); }
    }
    
    /** Number of recent messages received in the folder */
    public var recentCount: UInt32 {
        get { return nativeInstance.recentCount(nativeInstance); }
        set { nativeInstance.setRecentCount(nativeInstance, newValue); }
    }
    
    /** Number of unseen messages in the folder */
    public var unseenCount: UInt32 {
        get { return nativeInstance.unseenCount(nativeInstance); }
        set { nativeInstance.setUnseenCount(nativeInstance, newValue); }
    }
    
    /** Number of messages in the folder */
    public var messageCount: UInt32 {
        get { return nativeInstance.messageCount(nativeInstance); }
        set { nativeInstance.setMessageCount(nativeInstance, newValue); }
    }
    
    /** Highest modification sequence value for this folder. See CONDSTORE RFC 4551. */
    public var highestModSeqValue: UInt64 {
        get { return nativeInstance.highestModSeqValue(nativeInstance); }
        set { nativeInstance.setHighestModSeqValue(nativeInstance, newValue); }
    }
}
