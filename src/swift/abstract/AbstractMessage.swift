import Foundation
import CMailCore

public class MCOAbstractMessage: NSObjectCompat, Convertible {
	
    private var nativeInstance:CAbstractMessage;
    
    public required init(mailCoreObject: CObject) {
        self.nativeInstance = CAbstractMessage.init(cobject: mailCoreObject)
        self.nativeInstance.retain()
    }
    
    func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    deinit {
        nativeInstance.release()
    }
    
    /** Header of the message. */
    public var header : MCOMessageHeader! {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.header =  newValue?.nativeInstance ?? CMessageHeader()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                createMCOObject(from: nativeInstance.header.toCObject())
            }
        }
    }
    
    /** Returns the part with the given Content-ID.*/
    public func partForContentID(contentID: String) -> MCOAbstractPart? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: nativeInstance.partForContentID(contentID.mailCoreString()).toCObject())
        }
    }
    
    /** Returns the part with the given unique identifier.*/
    public func partForUniqueID(uniqueID: String) -> MCOAbstractPart? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: nativeInstance.partForUniqueID(uniqueID.mailCoreString()).toCObject())
        }
    }
    
    /** All attachments in the message.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func attachments() -> Array<MCOAbstractPart>? {
        return mailCoreAutoreleasePool {
            return Array<MCOAbstractPart>(mailCoreArray: nativeInstance.attachments());
        }
    }
    
    /** All image attachments included inline in the message through cid: URLs.
     It will return an array of MCOIMAPPart for MCOIMAPMessage.
     It will return an array of MCOAttachment for MCOMessageParser.
     It will return an array of MCOAttachment for MCOMessageBuilder. */
    public func htmlInlineAttachments() -> Array<MCOAbstractPart>? {
        return mailCoreAutoreleasePool {
            return Array<MCOAbstractPart>(mailCoreArray: nativeInstance.htmlInlineAttachments());
        }
    }
    
    /**
     Returns parts required to render the message as plain text or html.
     This does not include inline images and attachments, but only the text content
     */
    public func requiredPartsForRendering() -> Array<MCOAbstractPart>? {
        return mailCoreAutoreleasePool {
            return Array<MCOAbstractPart>(mailCoreArray: nativeInstance.requiredPartsForRendering());
        }
    }
}
