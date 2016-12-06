import Foundation

public final class IMAPMessage : AbstractMessage, Convertible {
    
    private var nativeInstance:CIMAPMessage;
    
    internal init(message:CIMAPMessage) {
        self.nativeInstance = message;
        super.init(message.abstractMessage);
    }
    
    /** IMAP UID of the message. */
    //@property (nonatomic, assign) uint32_t uid;
    public var uid: UInt32 {
        get { return nativeInstance.uid(nativeInstance); }
        set { nativeInstance.setUid(nativeInstance, newValue); }
    }
    
    /** IMAP sequence number of the message.
     @warning *Important*: This property won't be serialized. */
    public var sequenceNumber: UInt32 {
        get { return nativeInstance.sequenceNumber(nativeInstance); }
        set { nativeInstance.setSequenceNumber(nativeInstance, newValue); }
    }
    
    /* Size of the entire message */
    public var size: UInt32 {
        get { return nativeInstance.size(nativeInstance); }
        set { nativeInstance.setSize(nativeInstance, newValue); }
    }
    
    /** Flags of the message, like if it is deleted, read, starred etc */
    public var flags: MessageFlag {
        get { return nativeInstance.flags(nativeInstance); }
        set { nativeInstance.setFlags(nativeInstance, newValue); }
    }
    
    /** The contents of the message flags when it was fetched from the server */
    public var originalFlags: MessageFlag {
        get { return nativeInstance.originalFlags(nativeInstance); }
        set { nativeInstance.setOriginalFlags(nativeInstance, newValue); }
    }
    
    /** Flag keywords of the message, mostly custom flags */
    public var customFlags: Array<String> {
        get { return Array<String>.cast(nativeInstance.customFlags(nativeInstance)); }
        set { nativeInstance.setCustomFlags(nativeInstance, Array<String>.cast(newValue)); }
    }
    
    /** It's the last modification sequence value of the message synced from the server. See RFC4551 */
    public var modSeqValue: UInt64 {
        get { return nativeInstance.modSeqValue(nativeInstance); }
        set { nativeInstance.setModSeqValue(nativeInstance, newValue); }
    }
    
    /** Main MIME part of the message */
    public var mainPart: AbstractPart {
        get { return AbstractPart(nativeInstance.mainPart(nativeInstance)); }
        set { nativeInstance.setMainPart(nativeInstance, newValue.CAbstractPart()); }
    }
    
    /** All Gmail labels of the message */
    public var gmailLabels: Array<String> {
        get { return Array<String>.cast(nativeInstance.gmailLabels(nativeInstance)); }
        set { nativeInstance.setGmailLabels(nativeInstance, Array<String>.cast(newValue)); }
    }
    
    /** Gmail message ID of the message */
    public var gmailMessageID: UInt64 {
        get { return nativeInstance.gmailMessageID(nativeInstance); }
        set { nativeInstance.setGmailMessageID(nativeInstance, newValue); }
    }
    
    /** Gmail thread ID of the message */
    public var gmailThreadID: UInt64 {
        get { return nativeInstance.gmailThreadID(nativeInstance); }
        set { nativeInstance.setGmailThreadID(nativeInstance, newValue); }
    }
    
    /**
     Returns the part with the given part identifier.
     @param partID A part identifier looks like 1.2.1
     */
    public func partForPartID(partID: String) -> AbstractPart {
        return AbstractPart( partID.utf16({ nativeInstance.partForPartID(nativeInstance, $0) }));
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
        return String(utf16: folder.utf16({ self.nativeInstance.htmlRendering(nativeInstance, $0, rendererCallback.cast()) }));
    }
    
    
    /** All attachments in the message. */
    public func attachments() -> Array<IMAPPart> {
        return Array<IMAPPart>.cast(nativeInstance.abstractMessage.attachments(nativeInstance.abstractMessage));
    }
    
    /** All image attachments included inline in the message through cid: URLs. */
    public func htmlInlineAttachments() -> Array<IMAPPart> {
        return Array<IMAPPart>.cast(nativeInstance.abstractMessage.htmlInlineAttachments(nativeInstance.abstractMessage));
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject(nativeInstance);
    }
    
    internal init(_ obj: CObject){
        let message = castCIMAPMessage(obj);
        self.nativeInstance = message;
        super.init(message.abstractMessage);
    }
    
}
