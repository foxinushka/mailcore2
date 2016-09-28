import Foundation

public class AbsrtactMessage {
	
    private var nativeInstance:CAbstractMessage;

    init(abstractMessage:CAbstractMessage) {
        self.nativeInstance = abstractMessage;
	}
    
    deinit {
        deleteCAbstractMessage(&nativeInstance);
    }
    
    /** Header of the message. */
    public var header : MessageHeader {
        set { nativeInstance.setHeader(&nativeInstance, &newValue.nativeInstance); }
        get { return MessageHeader(header: nativeInstance.header(&nativeInstance)); }
    }
    
    /** Returns the part with the given Content-ID.*/
    public func partForContentID(contentID: String) -> AbstractPart {
        return AbstractPart(nativeInstance.partForContentID(&nativeInstance, contentID.utf16CString));
    }
    
    /** Returns the part with the given unique identifier.*/
    public func partForUniqueID(uniqueID: String) -> AbstractPart {
        return AbstractPart(nativeInstance.partForUniqueID(&nativeInstance, uniqueID.utf16CString));
    }
    
    /** All attachments in the message.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func attachments() -> Array<Any>? {
        return arrayFromC(nativeInstance.attachments(&nativeInstance));
    }
    
    /** All image attachments included inline in the message through cid: URLs.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func htmlInlineAttachments() -> Array<Any>? {
        return arrayFromC(nativeInstance.htmlInlineAttachments(&nativeInstance));
    }
    
    /**
     Returns parts required to render the message as plain text or html.
     This does not include inline images and attachments, but only the text content
     */
    public func requiredPartsForRendering() -> Array<Any>? {
        return arrayFromC(nativeInstance.requiredPartsForRendering(&nativeInstance));
    }
}
