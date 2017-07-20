import Foundation
import CCore

public class AbstractMessagePart : AbstractPart {
    
    private var nativeInstance:CAbstractMessagePart;
    
    internal init(abstractMessagePart:CAbstractMessagePart) {
        self.nativeInstance = abstractMessagePart;
        super.init(abstractMessagePart.abstractPart);
    }
    
    required public init(_ obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    // Returns the header of the embedded message.
    public var header : MessageHeader {
        set { nativeInstance.header = newValue.CMessageHeader() }
        get { return MessageHeader(nativeInstance.header) }
    }
    
    // Returns the main part of the embedded message. It can be MCOAbstractPart, MCOAbstractMultipart
    // or a MCOAbstractMessagePart.
    public var mainPart : AbstractPart {
        set { nativeInstance.mainPart = newValue._CAbstractPart() }
        get { return AbstractPart(nativeInstance.mainPart) }
    }

}
