import Foundation

public class AbstractMessagePart : AbstractPart {
    
    var abstractMessagePart:CAbstractMessagePart;
    
    init(abstractMessagePart:CAbstractMessagePart) {
        self.abstractMessagePart = abstractMessagePart;
        super.init(abstractMessagePart.abstractPart);
    }
    
    public var header : MessageHeader {
        set { abstractMessagePart.setHeader(abstractMessagePart, newValue.nativeInstance); }
        get { return MessageHeader(header: abstractMessagePart.header(abstractMessagePart)); }
    }
    
    public var mainPart : AbstractPart {
        set { abstractMessagePart.setMainPart(abstractMessagePart, newValue.CAbstractPart()); }
        get { return AbstractPart(abstractMessagePart.mainPart(abstractMessagePart)); }
    }

}
