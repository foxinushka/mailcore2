import Foundation


public final class MCOIMAPMessage : MCOAbstractMessage, Convertible {
    
    internal var nativeInstance:CIMAPMessage;
    
    public convenience init() {
        self.init(message: CIMAPMessage_new())
    }
    
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
    public var flags: MCOMessageFlag {
        get { return MCOMessageFlag(cMessageFlag: nativeInstance.flags) }
        set { nativeInstance.flags = newValue.toCMessageFlag() }
    }
    
    /** The contents of the message flags when it was fetched from the server */
    public var originalFlags: MCOMessageFlag {
        get { return MCOMessageFlag(cMessageFlag: nativeInstance.originalFlags) }
        set { nativeInstance.originalFlags = newValue.toCMessageFlag() }
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
    public var mainPart: MCOAbstractPart {
        get { return MCOAbstractPart(nativeInstance.mainPart) }
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
    public func partForPartID(partID: String) -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.partForPartID(partID: partID.mailCoreString()))
    }
    
    /**
     HTML rendering of the message to be displayed in a web view.
     The delegate should implement at least
     [MCOAbstractMessage:dataForIMAPPart:folder:]
     so that the complete HTML rendering can take place.
     */
    public func htmlRendering(folder: String, delegate: MCOHTMLRendererIMAPDelegate) -> String? {
        let rendererCallback: MCOAbstractMessageRendererCallback = MCOAbstractMessageRendererCallback(message: self);
        rendererCallback.setHtmlRenderImapDelegate(delegate: delegate);
        return self.nativeInstance.htmlRendering(folder: folder.mailCoreString(), rendererCallback: rendererCallback.cast()).string()
    }
    
    
    /** All attachments in the message. */
    public func attachments() -> Array<MCOIMAPPart> {
        return Array<MCOIMAPPart>.cast(nativeInstance.abstractMessage.attachments());
    }
    
    /** All image attachments included inline in the message through cid: URLs. */
    public func htmlInlineAttachments() -> Array<MCOIMAPPart> {
        return Array<MCOIMAPPart>.cast(nativeInstance.abstractMessage.htmlInlineAttachments());
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject();
    }
    
    internal init(cobject obj: CObject){
        let message = CIMAPMessage(cobject: obj);
        self.nativeInstance = message;
        super.init(message.abstractMessage);
    }
    
}
