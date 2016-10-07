import Foundation

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
        set { nativeInstance.setHeader(nativeInstance, newValue.CMessageHeader()); }
        get { return MessageHeader(nativeInstance.header(nativeInstance)); }
    }
    
    // Returns the main part of the embedded message. It can be MCOAbstractPart, MCOAbstractMultipart
    // or a MCOAbstractMessagePart.
    public var mainPart : AbstractPart {
        set { nativeInstance.setMainPart(nativeInstance, newValue.CAbstractPart()); }
        get { return AbstractPart(nativeInstance.mainPart(nativeInstance)); }
    }

}
