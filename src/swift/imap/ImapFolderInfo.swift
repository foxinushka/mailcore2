import Foundation

public class ImapFolderInfo {
    
    private var nativeInstance:CIMAPFolderInfo;
    
    internal init(info: CIMAPFolderInfo) {
        self.nativeInstance = info;
    }
    
    deinit {
        deleteCIMAPFolderInfo(self.nativeInstance);
    }
    
    /** The folder's IMAP UIDNEXT value. Used to determine the uid for the next received message. */
    public var uidNext: UInt32 {
        get { return nativeInstance.uidNext(&nativeInstance); }
        set { nativeInstance.setUidNext(&nativeInstance, newValue); }
    }
    
    /** The folders IMAP UIDVALIDITY value. Must be used to determine if the server has changed assigned UIDs */
    public var uidValidity: UInt32 {
        get { return nativeInstance.uidValidity(&nativeInstance); }
        set { nativeInstance.setUidValidity(&nativeInstance, newValue); }
    }
    
    /** An advanced value used for doing quick flag syncs if the server supports it. The MODSEQ value. */
    public var modSequenceValue: UInt64 {
        get { return nativeInstance.modSequenceValue(&nativeInstance); }
        set { nativeInstance.setModSequenceValue(&nativeInstance, newValue); }
    }
    
    /** Total number of messages in the folder */
    public var messageCount: Int32 {
        get { return nativeInstance.messageCount(&nativeInstance); }
        set { nativeInstance.setMessageCount(&nativeInstance, newValue); }
    }
    
    // first uid of the unseen messages.
    public var firstUnseenUid: UInt32 {
        get { return nativeInstance.firstUnseenUid(&nativeInstance); }
        set { nativeInstance.setFirstUnseenUid(&nativeInstance, newValue); }
    }
    
    /** An boolean indicates that this folder or IMAP server allows to add a new permanent flags */
    public var allowsNewPermanentFlags: Bool {
        get { return nativeInstance.allowsNewPermanentFlags(&nativeInstance); }
        set { nativeInstance.setAllowsNewPermanentFlags(&nativeInstance, newValue); }
    }
    
}
