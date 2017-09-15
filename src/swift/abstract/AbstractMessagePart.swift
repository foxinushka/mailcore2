import Foundation
import CMailCore

public class MCOAbstractMessagePart : MCOAbstractPart {
    
    private var nativeInstance:CAbstractMessagePart;
    
    required public init(mailCoreObject obj: CObject) {
        self.nativeInstance = CAbstractMessagePart.init(cobject: obj)
        self.nativeInstance.retain()
        super.init(mailCoreObject: obj);
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    internal override func cast() -> CObject {
        return nativeInstance.toCObject();
    }
    
    // Returns the header of the embedded message.
    public var header : MCOMessageHeader? {
        set { nativeInstance.header = newValue?.nativeInstance ?? CMessageHeader() }
        get { return createMCOObject(from: nativeInstance.header.toCObject()) }
    }
    
    // Returns the main part of the embedded message. It can be MCOAbstractPart, MCOAbstractMultipart
    // or a MCOAbstractMessagePart.
    public var mainPart : MCOAbstractPart? {
        set { nativeInstance.mainPart = newValue?._CAbstractPart() ?? CAbstractPart() }
        get { return createMCOObject(from: nativeInstance.mainPart.toCObject()) }
    }

}
