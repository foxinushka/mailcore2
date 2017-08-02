import Foundation


public class MCOAbstractMessage: NSObject {
	
    private var nativeInstance:CAbstractMessage;

    internal init(_ abstractMessage:CAbstractMessage) {
        self.nativeInstance = abstractMessage;
	}
    
    deinit {
        nativeInstance.release()
    }
    
    /** Header of the message. */
    public var header : MCOMessageHeader? {
        set {
            if newValue != nil {
                nativeInstance.header =  newValue!.CMessageHeader()
            }
        }
        get {
            guard (nativeInstance.header.instance) != nil else {
                return nil
            }
            return MCOMessageHeader(nativeInstance.header)
        }
    }
    
    /** Returns the part with the given Content-ID.*/
    public func partForContentID(contentID: String) -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.part(forContentID: contentID.mailCoreString()))
    }
    
    /** Returns the part with the given unique identifier.*/
    public func partForUniqueID(uniqueID: String) -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.part(forUniqueID: uniqueID.mailCoreString()))
    }
    
    /** All attachments in the message.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func attachments() -> Array<MCOAbstractPart> {
        return Array<MCOAbstractPart>.cast(nativeInstance.attachments());
    }
    
    /** All image attachments included inline in the message through cid: URLs.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func htmlInlineAttachments() -> Array<MCOAbstractPart> {
        return Array<MCOAbstractPart>.cast(nativeInstance.htmlInlineAttachments());
    }
    
    /**
     Returns parts required to render the message as plain text or html.
     This does not include inline images and attachments, but only the text content
     */
    public func requiredPartsForRendering() -> Array<MCOAbstractPart> {
        return Array<MCOAbstractPart>.cast(nativeInstance.requiredPartsForRendering());
    }
}
