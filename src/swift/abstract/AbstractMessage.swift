import Foundation
import CCore

public class AbstractMessage {
	
    private var nativeInstance:CAbstractMessage;

    internal init(_ abstractMessage:CAbstractMessage) {
        self.nativeInstance = abstractMessage;
	}
    
    deinit {
        nativeInstance.release()
    }
    
    /** Header of the message. */
    public var header : MessageHeader {
        set { nativeInstance.header =  newValue.CMessageHeader() }
        get { return MessageHeader(nativeInstance.header) }
    }
    
    /** Returns the part with the given Content-ID.*/
    public func partForContentID(contentID: String) -> AbstractPart {
        return AbstractPart(String.utf16(contentID, { nativeInstance.part(forContentID: $0) }));
    }
    
    /** Returns the part with the given unique identifier.*/
    public func partForUniqueID(uniqueID: String) -> AbstractPart {
        return AbstractPart(String.utf16(uniqueID, { nativeInstance.part(forUniqueID: $0) }));
    }
    
    /** All attachments in the message.
     It will return an array of IMAPPart for IMAPMessage.
     It will return an array of Attachment for MessageParser.
     It will return an array of Attachment for MessageBuilder. */
    public func attachments() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.attachments());
    }
    
    /** All image attachments included inline in the message through cid: URLs.
     It will return an array of IMAPPart for IMAPMessage.
     It will return an array of Attachment for MessageParser.
     It will return an array of Attachment for MessageBuilder. */
    public func htmlInlineAttachments() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.htmlInlineAttachments());
    }
    
    /**
     Returns parts required to render the message as plain text or html.
     This does not include inline images and attachments, but only the text content
     */
    public func requiredPartsForRendering() -> Array<AbstractPart> {
        return Array<AbstractPart>.cast(nativeInstance.requiredPartsForRendering());
    }
}
