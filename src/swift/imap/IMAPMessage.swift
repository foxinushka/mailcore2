import Foundation


public final class MCOIMAPMessage : MCOAbstractMessage, NSCoding {
    
    internal var nativeInstance:CIMAPMessage;
    
    internal override func cast() -> CObject {
        return nativeInstance.toCObject();
    }
    
    public required init(mailCoreObject obj: CObject){
        let message = CIMAPMessage(cobject: obj);
        self.nativeInstance = message;
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    public init() {
        self.nativeInstance = CIMAPMessage_init()
        super.init(mailCoreObject: self.nativeInstance.toCObject())
    }
    
    deinit {
        self.nativeInstance.release()
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
    public var customFlags: Array<String>? {
        get { return Array<String>(mailCoreArray: nativeInstance.customFlags) }
        set { nativeInstance.customFlags = newValue?.mailCoreArray() ?? CArray() }
    }
    
    /** It's the last modification sequence value of the message synced from the server. See RFC4551 */
    public var modSeqValue: UInt64 {
        get { return nativeInstance.modSeqValue }
        set { nativeInstance.modSeqValue = newValue }
    }
    
    /** Main MIME part of the message */
    public var mainPart: MCOAbstractPart? {
        get { return createMCOObject(from: nativeInstance.mainPart.toCObject()) }
        set { nativeInstance.mainPart = newValue?._CAbstractPart() ?? CAbstractPart() }
    }
    
    /** All Gmail labels of the message */
    public var gmailLabels: Array<String>? {
        get { return Array<String>(mailCoreArray: nativeInstance.gmailLabels) }
        set { nativeInstance.gmailLabels = newValue?.mailCoreArray() ?? CArray() }
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
    public func partForPartID(partID: String) -> MCOAbstractPart? {
        return createMCOObject(from: nativeInstance.partForPartID(partID.mailCoreString()).toCObject())
    }
    
    /**
     HTML rendering of the message to be displayed in a web view.
     The delegate should implement at least
     [MCOAbstractMessage:dataForIMAPPart:folder:]
     so that the complete HTML rendering can take place.
     */
    public func htmlRendering(folder: String, delegate: MCOHTMLRendererIMAPDelegate & MCOHTMLRendererDelegate) -> String? {
        let rendererCallback: MCOAbstractMessageRendererCallback = MCOAbstractMessageRendererCallback(message: self);
        rendererCallback.setHtmlRenderDelegate(delegate: delegate)
        rendererCallback.setHtmlRenderImapDelegate(delegate: delegate)
        let result = self.nativeInstance.htmlRendering(folder.mailCoreString(), rendererCallback.cast()).string()
        return result
    }
    
    
    /** All attachments in the message. */
    public func attachments() -> Array<MCOIMAPPart>? {
        guard let attachments = super.attachments() else {
            return nil
        }
        return Array<MCOIMAPPart>(mailCoreArray: attachments.mailCoreArray());
    }
    
    /** All image attachments included inline in the message through cid: URLs. */
    public func htmlInlineAttachments() -> Array<MCOIMAPPart>? {
        guard let htmlInlineAttachments = super.htmlInlineAttachments() else {
            return nil
        }
        return Array<MCOIMAPPart>(mailCoreArray: htmlInlineAttachments.mailCoreArray());
    }
    
    public convenience init?(coder aDecoder: NSCoder) {
        guard let dict = aDecoder.decodeObject(forKey: "info") as? Dictionary<AnyHashable, Any> else {
            return nil
        }
        let serializable = dictionaryUnsafeCast(dict)
        self.init(mailCoreObject: CObject.objectWithSerializable(serializable))
        self.nativeInstance.retain()
    }
    
    public func encode(with aCoder: NSCoder) {
        let serialazable: CDictionary = self.cast().serializable()
        let dict = dictionaryUnsafeCast(serialazable)
        aCoder.encode(dict, forKey: "info")
    }
    
}
