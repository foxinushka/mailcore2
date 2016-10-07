import Foundation

public class AbstractMessage {
	
    private var nativeInstance:CAbstractMessage;

    internal init(_ abstractMessage:CAbstractMessage) {
        self.nativeInstance = abstractMessage;
	}
    
    deinit {
        deleteCAbstractMessage(nativeInstance);
    }
    
    /** Header of the message. */
    public var header : MessageHeader {
        set { nativeInstance.setHeader(nativeInstance, newValue.CMessageHeader()); }
        get { return MessageHeader(nativeInstance.header(nativeInstance)); }
    }
    
    /** Returns the part with the given Content-ID.*/
    public func partForContentID(contentID: String) -> AbstractPart {
        return AbstractPart(nativeInstance.partForContentID(nativeInstance, contentID.utf16CString));
    }
    
    /** Returns the part with the given unique identifier.*/
    public func partForUniqueID(uniqueID: String) -> AbstractPart {
        return AbstractPart(nativeInstance.partForUniqueID(nativeInstance, uniqueID.utf16CString));
    }
    
    /** All attachments in the message.
     It will return an array of IMAPPart for IMAPMessage.
     It will return an array of Attachment for MessageParser.
     It will return an array of Attachment for MessageBuilder. */
    public func attachments() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.attachments(nativeInstance));
    }
    
    /** All image attachments included inline in the message through cid: URLs.
     It will return an array of IMAPPart for IMAPMessage.
     It will return an array of Attachment for MessageParser.
     It will return an array of Attachment for MessageBuilder. */
    public func htmlInlineAttachments() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.htmlInlineAttachments(nativeInstance));
    }
    
    /**
     Returns parts required to render the message as plain text or html.
     This does not include inline images and attachments, but only the text content
     */
    public func requiredPartsForRendering() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.requiredPartsForRendering(nativeInstance));
    }
}
