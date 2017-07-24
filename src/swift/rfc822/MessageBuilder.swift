import Foundation


public class MessageBuilder : AbstractMessage {
    
    private var nativeInstance: CMessageBuilder;
    
    public convenience init() {
        self.init(CMessageBuilder())
    }
    
    internal init(_ builder: CMessageBuilder) {
        self.nativeInstance = builder;
        super.init(builder.abstractMessage);
    }
    
    /** Main HTML content of the message.*/
    public var htmlBody: String? {
        get { return String(utf16: nativeInstance.htmlBody); }
        set { String.utf16(newValue, { nativeInstance.htmlBody = $0 }) }
    }
    
    /** Plain text content of the message.*/
    public var textBody: String? {
        get { return String(utf16: nativeInstance.textBody); }
        set { String.utf16(newValue, { nativeInstance.textBody = $0 }) }
    }
    
    /** List of file attachments.*/
    public var attachments: Array<Attachment> {
        get { return Array<Attachment>.cast(nativeInstance.attachments); }
        set { nativeInstance.attachments = newValue.cast() }
    }
    
    /** List of related file attachments (included as cid: link in the HTML part).*/
    public var relatedAttachments: Array<Attachment> {
        get { return Array<Attachment>.cast(nativeInstance.relatedAttachments) }
        set { nativeInstance.relatedAttachments = newValue.cast() }
    }
    
    /** Prefix for the boundary identifier. Default value is nil.*/
    public var boundaryPrefix: String? {
        get { return String(utf16: nativeInstance.boundaryPrefix); }
        set { String.utf16(newValue, { nativeInstance.boundaryPrefix = $0 }) }
    }
    
    /** Add an attachment.*/
    public func addAttachment(attachment: Attachment) {
        nativeInstance.addAttachment(attachment: attachment.nativeInstance);
    }
    
    /** Add a related attachment.*/
    public func addRelatedAttachment(attachment: Attachment) {
        nativeInstance.addRelatedAttachment(attachment: attachment.nativeInstance);
    }
    
    /** RFC 822 formatted message.*/
    public func data() -> Data {
        return Data(cdata: nativeInstance.data());
    }
    
    /** RFC 822 formatted message for encryption.*/
    public func dataForEncryption() -> Data {
        return Data(cdata: nativeInstance.dataForEncryption());
    }
    
    /** Store RFC 822 formatted message to file. */
    public func writeToFile(filename: String) -> (successful: Bool, error: Error?) {
        let code = String.utf16(filename, { nativeInstance.writeToFile(filename: $0) })
        var error: Error?
        if code != ErrorNone {
            error = MailCoreError(code: code);
        }
        return (code == ErrorNone, error);
    }
    
    /**
     Returns an OpenPGP signed message with a given signature.
     The signature needs to be computed on the data returned by -dataForEncryption
     before calling this method.
     You could use http://www.netpgp.com to generate it.
     */
    public func openPGPSignedMessageDataWithSignatureData(signature: Data) -> Data {
        return Data(cdata: nativeInstance.openPGPSignedMessageDataWithSignatureData(bytes: signature.bytes(), length: signature.length()));
    }
    
    /**
     Returns an OpenPGP encrypted message with a given encrypted data.
     The encrypted data needs to be computed before calling this method.
     You could use http://www.netpgp.com to generate it.
     */
    public func openPGPEncryptedMessageDataWithEncryptedData(encryptedData: Data) -> Data {
        return Data(cdata: nativeInstance.openPGPEncryptedMessageDataWithEncryptedData(bytes: encryptedData.bytes(), length: encryptedData.length()));
    }
    
    /** HTML rendering of the message to be displayed in a web view. The delegate can be nil.*/
    //- (NSString *) htmlRenderingWithDelegate:(id <MCOHTMLRendererDelegate>)delegate;
    
    /** HTML rendering of the body of the message to be displayed in a web view.*/
    public func htmlBodyRendering() -> String? {
        return String(utf16: nativeInstance.htmlBodyRendering());
    }
    
    /** Text rendering of the message.*/
    public func plainTextRendering() -> String? {
        return String(utf16: nativeInstance.plainTextRendering());
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRendering() -> String? {
        return String(utf16: nativeInstance.plainTextBodyRendering());
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up if requested.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRenderingAndStripWhitespace(stripWhitespace: Bool) -> String? {
        return String(utf16: nativeInstance.plainTextBodyRenderingAndStripWhitespace(stripWhitespace: stripWhitespace));
    }

}
