import Foundation


public class MCOAttachment : MCOAbstractPart {

    internal var nativeInstance: CAttachment;
    
    public var data: Data {
        get { return Data(cdata: self.nativeInstance.data) }
        set { nativeInstance.data = newValue.mailCoreData() }
    }
    
    internal init(_ attachment: CAttachment) {
        self.nativeInstance = attachment;
        super.init(attachment.abstractPart);
    }
    
    required public init(cobject obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    public func decodedString() -> String? {
        return nativeInstance.decodedString().string()
    }
    
    /** Returns a MIME type for a filename.*/
    public static func mimeTypeForFilename(filename: String) -> String? {
        return CAttachment.mimeType(forFilename: filename.mailCoreString()).string()
    }
    
    /** Returns a file attachment with the content of the given file.*/
    public static func attachmentWithContentsOfFile(filename: String) -> MCOAttachment {
        return MCOAttachment(CAttachment(contentsOfFile: filename.mailCoreString()))
    }
    
    /** Returns a file attachment with the given data and filename.*/
    public convenience init( data: Data, filename: String) {
        self.init(CAttachment(data: data.mailCoreData(), filename: filename.mailCoreString()))
    }
    
    /** Returns a part with an HTML content.*/
    public static func attachmentWithHTMLString(htmlString: String) -> MCOAttachment {
        return MCOAttachment(CAttachment(htmlString: htmlString.mailCoreString()))
    }
    
    /** Returns a part with a RFC 822 messsage attachment.*/
    public static func attachmentWithRFC822Message(messageData: Data) -> MCOAttachment {
        return MCOAttachment(CAttachment(RFC822MessageData: messageData.mailCoreData()))
    }
    
    /** Returns a part with an plain text content.*/
    public static func attachmentWithText(text: String) -> MCOAttachment {
        return MCOAttachment(CAttachment(text: text.mailCoreString()))
    }
    
}
