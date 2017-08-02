import Foundation


/**
 This class implements a parsed message.
 When the full content of a message has been fetched using POP or IMAP,
 you need to parse it.
 */
public class MCOMessageParser : MCOAbstractMessage {
    
    internal var nativeInstance: CMessageParser;
    
    internal init(parser: CMessageParser) {
        self.nativeInstance = parser;
        super.init(parser.abstractMessage);
    }
    
    /** returns a parsed message from the given RFC 822 data.*/
    static public func messageParserWithData(data: Data) -> MCOMessageParser {
        return MCOMessageParser(data: data);
    }
    
    /** data is the RFC 822 formatted message.*/
    public convenience init (data: Data) {
        self.init(parser: CMessageParser(data: data.mailCoreData()))
    }
    
    /** It's the main part of the message. It can be MCOMessagePart, MCOMultipart or MCOAttachment.*/
    public func mainPart() -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.mainPart());
    }
    
    /** data of the RFC 822 formatted message. It's the input of the parser.*/
    public func data() -> Data {
        return Data(cdata: nativeInstance.data());
    }
    
    /** HTML rendering of the message to be displayed in a web view. delegate can be nil.*/
    public func htmlRendering(withDelegate delegate: MCOHTMLRendererDelegate?) -> String? {
        let htmlRenderCallback = MCOAbstractMessageRendererCallback(message: self)
        htmlRenderCallback.setHtmlRenderDelegate(delegate: delegate!)
        let result = self.nativeInstance.htmlRendering(delegate: htmlRenderCallback.cast()).string()
        htmlRenderCallback.release()
        return result
    }
    
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
