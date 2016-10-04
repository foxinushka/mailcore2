import Foundation

public class MessageBuilder : AbstractMessage {
    
    private var nativeInstance: CMessageBuilder;
    
    internal init(_ builder: CMessageBuilder) {
        self.nativeInstance = builder;
        super.init(builder.abstractMessage);
    }
    
    /** Main HTML content of the message.*/
    public var htmlBody: String? {
        get { return String(utf16: nativeInstance.htmlBody(nativeInstance)); }
        set { nativeInstance.setHTMLBody(nativeInstance, newValue?.utf16CString); }
    }
    
    /** Plain text content of the message.*/
    public var textBody: String? {
        get { return String(utf16: nativeInstance.textBody(nativeInstance)); }
        set { nativeInstance.setTextBody(nativeInstance, newValue?.utf16CString); }
    }
    
    /** List of file attachments.*/
    public var attachments: Array<Attachment> {
        get { return Array<Attachment>.cast(nativeInstance.attachments(nativeInstance)); }
        set { nativeInstance.setAttachments(nativeInstance, newValue.cast()); }
    }
    
    /** List of related file attachments (included as cid: link in the HTML part).*/
    public var relatedAttachments: Array<Attachment> {
        get { return Array<Attachment>.cast(nativeInstance.relatedAttachments(nativeInstance)); }
        set { nativeInstance.setRelatedAttachments(nativeInstance, newValue.cast()); }
    }
    
    /** Prefix for the boundary identifier. Default value is nil.*/
    public var boundaryPrefix: String? {
        get { return String(utf16: nativeInstance.boundaryPrefix(nativeInstance)); }
        set { nativeInstance.setBoundaryPrefix(nativeInstance, newValue?.utf16CString); }
    }
    
    /** Add an attachment.*/
    public func addAttachment(attachment: Attachment) {
        nativeInstance.addAttachment(nativeInstance, attachment.nativeInstance);
    }
    
    /** Add a related attachment.*/
    public func addRelatedAttachment(attachment: Attachment) {
        nativeInstance.addRelatedAttachment(nativeInstance, attachment.nativeInstance);
    }
    
    /** RFC 822 formatted message.*/
    public func data() -> Data {
        return Data(cdata: nativeInstance.data(nativeInstance));
    }
    
    /** RFC 822 formatted message for encryption.*/
    public func dataForEncryption() -> Data {
        return Data(cdata: nativeInstance.dataForEncryption(nativeInstance));
    }
    
    /** Store RFC 822 formatted message to file. */
    public func writeToFile(filename: String) -> (successful: Bool, error: Error?) {
        let code = nativeInstance.writeToFile(nativeInstance, filename.utf16CString);
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
        return Data(cdata: nativeInstance.openPGPSignedMessageDataWithSignatureData(nativeInstance, signature.bytes(), signature.length()));
    }
    
    /**
     Returns an OpenPGP encrypted message with a given encrypted data.
     The encrypted data needs to be computed before calling this method.
     You could use http://www.netpgp.com to generate it.
     */
    public func openPGPEncryptedMessageDataWithEncryptedData(encryptedData: Data) -> Data {
        return Data(cdata: nativeInstance.openPGPEncryptedMessageDataWithEncryptedData(nativeInstance, encryptedData.bytes(), encryptedData.length()));
    }
    
    /** HTML rendering of the message to be displayed in a web view. The delegate can be nil.*/
    //- (NSString *) htmlRenderingWithDelegate:(id <MCOHTMLRendererDelegate>)delegate;
    
    /** HTML rendering of the body of the message to be displayed in a web view.*/
    public func htmlBodyRendering() -> String? {
        return String(utf16: nativeInstance.htmlBodyRendering(nativeInstance));
    }
    
    /** Text rendering of the message.*/
    public func plainTextRendering() -> String? {
        return String(utf16: nativeInstance.plainTextRendering(nativeInstance));
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRendering() -> String? {
        return String(utf16: nativeInstance.plainTextBodyRendering(nativeInstance));
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up if requested.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRenderingAndStripWhitespace(stripWhitespace: Bool) -> String? {
        return String(utf16: nativeInstance.plainTextBodyRenderingAndStripWhitespace(nativeInstance, stripWhitespace));
    }

}
