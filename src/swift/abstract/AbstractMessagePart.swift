import Foundation


public class MCOAbstractMessagePart : MCOAbstractPart {
    
    private var nativeInstance:CAbstractMessagePart;
    
    internal init(abstractMessagePart:CAbstractMessagePart) {
        self.nativeInstance = abstractMessagePart;
        super.init(abstractMessagePart.abstractPart);
    }
    
    required public init(cobject obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    // Returns the header of the embedded message.
    public var header : MCOMessageHeader {
        set { nativeInstance.header = newValue.CMessageHeader() }
        get { return MCOMessageHeader(nativeInstance.header) }
    }
    
    // Returns the main part of the embedded message. It can be MCOAbstractPart, MCOAbstractMultipart
    // or a MCOAbstractMessagePart.
    public var mainPart : MCOAbstractPart {
        set { nativeInstance.mainPart = newValue._CAbstractPart() }
        get { return MCOAbstractPart(nativeInstance.mainPart) }
    }

}
