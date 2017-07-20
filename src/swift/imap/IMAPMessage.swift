import Foundation
import CCore

public final class IMAPMessage : AbstractMessage, Convertible {
    
    internal var nativeInstance:CIMAPMessage;
    
    internal init(message:CIMAPMessage) {
        self.nativeInstance = message;
        super.init(message.abstractMessage);
    }
    
    /** IMAP UID of the message. */
    //@property (nonatomic, assign) uint32_t uid;
    public var uid: UInt32 {
        get { return nativeInstance.uid }
        set { nativeInstance.uid = newValue }
    }
    
    /** IMAP sequence number of the message.
     @warning *Important*: This property won't be serialized. */
    public var sequenceNumber: UInt32 {
        get { return nativeInstance.sequenceNumber }
        set { nativeInstance.sequenceNumber = newValue }
    }
    
    /* Size of the entire message */
    public var size: UInt32 {
        get { return nativeInstance.size }
        set { nativeInstance.size = newValue }
    }
    
    /** Flags of the message, like if it is deleted, read, starred etc */
    public var flags: MessageFlag {
        get { return nativeInstance.flags }
        set { nativeInstance.flags = newValue }
    }
    
    /** The contents of the message flags when it was fetched from the server */
    public var originalFlags: MessageFlag {
        get { return nativeInstance.originalFlags }
        set { nativeInstance.originalFlags = newValue }
    }
    
    /** Flag keywords of the message, mostly custom flags */
    public var customFlags: Array<String> {
        get { return Array<String>.cast(nativeInstance.customFlags) }
        set { nativeInstance.customFlags = Array<String>.cast(newValue) }
    }
    
    /** It's the last modification sequence value of the message synced from the server. See RFC4551 */
    public var modSeqValue: UInt64 {
        get { return nativeInstance.modSeqValue }
        set { nativeInstance.modSeqValue = newValue }
    }
    
    /** Main MIME part of the message */
    public var mainPart: AbstractPart {
        get { return AbstractPart(nativeInstance.mainPart) }
        set { nativeInstance.mainPart = newValue._CAbstractPart() }
    }
    
    /** All Gmail labels of the message */
    public var gmailLabels: Array<String> {
        get { return Array<String>.cast(nativeInstance.gmailLabels) }
        set { nativeInstance.gmailLabels = Array<String>.cast(newValue) }
    }
    
    /** Gmail message ID of the message */
    public var gmailMessageID: UInt64 {
        get { return nativeInstance.gmailMessageID }
        set { nativeInstance.gmailMessageID = newValue }
    }
    
    /** Gmail thread ID of the message */
    public var gmailThreadID: UInt64 {
        get { return nativeInstance.gmailThreadID }
        set { nativeInstance.gmailThreadID = newValue }
    }
    
    /**
     Returns the part with the given part identifier.
     @param partID A part identifier looks like 1.2.1
     */
    public func partForPartID(partID: String) -> AbstractPart {
        return AbstractPart( String.utf16(partID, { nativeInstance.partForPartID(partID: $0) }));
    }
    
    /**
     HTML rendering of the message to be displayed in a web view.
     The delegate should implement at least
     [MCOAbstractMessage:dataForIMAPPart:folder:]
     so that the complete HTML rendering can take place.
     */
    public func htmlRendering(folder: String, delegate: HTMLRendererImapDelegate) -> String? {
        let rendererCallback: AbstractMessageRendererCallback = AbstractMessageRendererCallback(message: self);
        rendererCallback.setHtmlRenderImapDelegate(delegate: delegate);
        return String(utf16: String.utf16(folder, { self.nativeInstance.htmlRendering(folder: $0, rendererCallback: rendererCallback.cast()) }));
    }
    
    
    /** All attachments in the message. */
    public func attachments() -> Array<IMAPPart> {
        return Array<IMAPPart>.cast(nativeInstance.abstractMessage.attachments());
    }
    
    /** All image attachments included inline in the message through cid: URLs. */
    public func htmlInlineAttachments() -> Array<IMAPPart> {
        return Array<IMAPPart>.cast(nativeInstance.abstractMessage.htmlInlineAttachments());
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject();
    }
    
    internal init(_ obj: CObject){
        let message = CIMAPMessage(cobject: obj);
        self.nativeInstance = message;
        super.init(message.abstractMessage);
    }
    
}
