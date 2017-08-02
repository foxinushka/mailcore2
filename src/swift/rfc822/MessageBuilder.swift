import Foundation


public class MCOMessageBuilder : MCOAbstractMessage {
    
    private var nativeInstance: CMessageBuilder;
    
    public convenience init() {
        self.init(builder: CMessageBuilder_new())
    }
    
    internal init(builder: CMessageBuilder) {
        self.nativeInstance = builder;
        super.init(builder.abstractMessage);
    }
    
    /** Main HTML content of the message.*/
    public var htmlBody: String? {
        get { return nativeInstance.htmlBody.string() }
        set { nativeInstance.htmlBody = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** Plain text content of the message.*/
    public var textBody: String? {
        get { return nativeInstance.textBody.string() }
        set { nativeInstance.textBody = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** List of file attachments.*/
    public var attachments: Array<MCOAttachment> {
        get { return Array<MCOAttachment>.cast(nativeInstance.attachments); }
        set { nativeInstance.attachments = newValue.cast() }
    }
    
    /** List of related file attachments (included as cid: link in the HTML part).*/
    public var relatedAttachments: Array<MCOAttachment> {
        get { return Array<MCOAttachment>.cast(nativeInstance.relatedAttachments) }
        set { nativeInstance.relatedAttachments = newValue.cast() }
    }
    
    /** Prefix for the boundary identifier. Default value is nil.*/
    public var boundaryPrefix: String? {
        get { return nativeInstance.boundaryPrefix.string() }
        set { nativeInstance.boundaryPrefix = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
    /** Add an attachment.*/
    public func addAttachment(attachment: MCOAttachment) {
        nativeInstance.addAttachment(attachment: attachment.nativeInstance);
    }
    
    /** Add a related attachment.*/
    public func addRelatedAttachment(attachment: MCOAttachment) {
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
        let code = nativeInstance.writeToFile(filename: filename.mailCoreString())
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
        return Data(cdata: nativeInstance.openPGPSignedMessageData(signatureData: signature.mailCoreData()))
    }
    
    /**
     Returns an OpenPGP encrypted message with a given encrypted data.
     The encrypted data needs to be computed before calling this method.
     You could use http://www.netpgp.com to generate it.
     */
    public func openPGPEncryptedMessageDataWithEncryptedData(encryptedData: Data) -> Data {
        return Data(cdata: nativeInstance.openPGPEncryptedMessageData(encryptedData: encryptedData.mailCoreData()))
    }
    
    /** HTML rendering of the message to be displayed in a web view. The delegate can be nil.*/
    //- (NSString *) htmlRenderingWithDelegate:(id <MCOHTMLRendererDelegate>)delegate;
    
    /** HTML rendering of the body of the message to be displayed in a web view.*/
    public func htmlBodyRendering() -> String? {
        return nativeInstance.htmlBodyRendering().string()
    }
    
    /** Text rendering of the message.*/
    public func plainTextRendering() -> String? {
        return nativeInstance.plainTextRendering().string()
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRendering() -> String? {
        return nativeInstance.plainTextBodyRendering().string()
    }
    
    /** Text rendering of the body of the message. All end of line will be removed and white spaces cleaned up if requested.
     This method can be used to generate the summary of the message.*/
    public func plainTextBodyRenderingAndStripWhitespace(stripWhitespace: Bool) -> String? {
        return nativeInstance.plainTextBodyRenderingAndStripWhitespace(stripWhitespace: stripWhitespace).string()
    }

}
