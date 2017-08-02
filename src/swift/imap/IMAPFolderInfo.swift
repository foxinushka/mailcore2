import Foundation


public class MCOIMAPFolderInfo {
    
    private var nativeInstance:CIMAPFolderInfo;
    
    internal init(info: CIMAPFolderInfo) {
        self.nativeInstance = info;
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
    
    /** An advanced value used for doing quick flag syncs if the server supports it. The MODSEQ value. */
    public var modSequenceValue: UInt64 {
        get { return nativeInstance.modSequenceValue }
        set { nativeInstance.modSequenceValue = newValue }
    }
    
    /** Total number of messages in the folder */
    public var messageCount: Int32 {
        get { return nativeInstance.messageCount }
        set { nativeInstance.messageCount = newValue }
    }
    
    // first uid of the unseen messages.
    public var firstUnseenUid: UInt32 {
        get { return nativeInstance.firstUnseenUid }
        set { nativeInstance.firstUnseenUid = newValue }
    }
    
    /** An boolean indicates that this folder or IMAP server allows to add a new permanent flags */
    public var allowsNewPermanentFlags: Bool {
        get { return nativeInstance.allowsNewPermanentFlags }
        set { nativeInstance.allowsNewPermanentFlags = newValue }
    }
    
}
