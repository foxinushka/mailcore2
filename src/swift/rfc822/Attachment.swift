import Foundation
import CMailCore

public class MCOAttachment : MCOAbstractPart {

    internal var nativeInstance: CAttachment;
    
    public var data: Data? {
        get {
            return mailCoreAutoreleasePool {
                Data(cdata: self.nativeInstance.data)
            }
        }
        set {
            mailCoreAutoreleasePool {
                nativeInstance.data = newValue?.mailCoreData() ?? CData()
            }
        }
    }
    
    required public init(mailCoreObject obj: CObject) {
        let attachment = CAttachment.init(cobject: obj)
        self.nativeInstance = attachment;
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    public func decodedString() -> String? {
        return nativeInstance.decodedString.string()
    }
    
    /** Returns a MIME type for a filename.*/
    public static func mimeTypeForFilename(filename: String) -> String? {
        return mailCoreAutoreleasePool {
            return CAttachment.mimeTypeForFilename(filename.mailCoreString()).string()
        }
    }
    
    /** Returns a file attachment with the content of the given file.*/
    public static func attachmentWithContentsOfFile(filename: String) -> MCOAttachment? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: CAttachment.attachmentWithContentsOfFile(filename.mailCoreString()).toCObject())
        }
    }
    
    /** Returns a file attachment with the given data and filename.*/
    public convenience init( data: Data, filename: String) {
        let attachment = mailCoreAutoreleasePool {
            CAttachment.attachmentWithData(filename.mailCoreString(), data.mailCoreData()).toCObject()
        }
        self.init(mailCoreObject: attachment)
    }
    
    /** Returns a part with an HTML content.*/
    public static func attachmentWithHTMLString(htmlString: String) -> MCOAttachment? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: CAttachment.attachmentWithHTMLString(htmlString.mailCoreString()).toCObject())
        }
    }
    
    /** Returns a part with a RFC 822 messsage attachment.*/
    public static func attachmentWithRFC822Message(messageData: Data) -> MCOAttachment? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: CAttachment.attachmentWithRFC822Message(messageData.mailCoreData()).toCObject())
        }
    }
    
    /** Returns a part with an plain text content.*/
    public static func attachmentWithText(text: String) -> MCOAttachment? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: CAttachment.attachmentWithText(text.mailCoreString()).toCObject())
        }
    }
    
}
