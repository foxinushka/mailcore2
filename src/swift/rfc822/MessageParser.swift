import Foundation
import CCore

/**
 This class implements a parsed message.
 When the full content of a message has been fetched using POP or IMAP,
 you need to parse it.
 */
public class MessageParser : AbstractMessage {
    
    internal var nativeInstance: CMessageParser;
    
    internal init(_ parser: CMessageParser) {
        self.nativeInstance = parser;
        super.init(parser.abstractMessage);
    }
    
    /** returns a parsed message from the given RFC 822 data.*/
    static public func messageParserWithData(data: Data) -> MessageParser {
        return MessageParser(data: data);
    }
    
    /** data is the RFC 822 formatted message.*/
    public convenience init (data: Data) {
        self.init(CMessageParser(bytes: data.bytes(), length: data.length()));
    }
    
    /** It's the main part of the message. It can be MCOMessagePart, MCOMultipart or MCOAttachment.*/
    public func mainPart() -> AbstractPart {
        return AbstractPart(nativeInstance.mainPart());
    }
    
    /** data of the RFC 822 formatted message. It's the input of the parser.*/
    public func data() -> Data {
        return Data(cdata: nativeInstance.data());
    }
    
    /** HTML rendering of the message to be displayed in a web view. delegate can be nil.*/
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
