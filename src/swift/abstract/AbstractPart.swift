import Foundation
import CMailCore

public class MCOAbstractPart : Convertible {
    
    private var nativeInstance:CAbstractPart;
    
    required public init(mailCoreObject obj: CObject) {
        self.nativeInstance = CAbstractPart.init(cobject: obj)
        self.nativeInstance.retain()
    }
    
    internal func cast() -> CObject {
        return nativeInstance.toCObject();
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    public func _CAbstractPart() -> CAbstractPart {
        return nativeInstance;
    }
    
    /** Returns type of the part (single / message part / multipart/mixed,
     multipart/related, multipart/alternative). See MCOPartType.*/
    public var partType : PartType {
        set { nativeInstance.partType = newValue }
        get { return nativeInstance.partType }
    }
    
    /** Returns filename of the part.*/
    public var filename : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.filename = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.filename.string()
            }
        }
    }
    
    /** Returns MIME type of the part. For example application/data.*/
    public var mimeType : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.mimeType = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.mimeType.string()
            }
        }
    }
    
    /** Returns charset of the part in case it's a text single part.*/
    public var charset : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.charset = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.charset.string()
            }
        }
    }
    
    /** Returns the unique ID generated for this part.
     It's a unique identifier that's created when the object is created manually
     or created by the parser.*/
    public var uniqueID : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.uniqueID = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.uniqueID.string()
            }
        }
    }
    
    /** Returns the value of the Content-ID field of the part.*/
    public var contentID : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.contentID = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.contentID.string()
            }
        }
    }
    
    /** Returns the value of the Content-Location field of the part.*/
    public var contentLocation : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.contentLocation = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.contentLocation.string()
            }
        }
    }
    
    /** Returns the value of the Content-Description field of the part.*/
    public var contentDescription : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.contentDescription = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.contentDescription.string ()
            }
        }
    }
    
    /** Returns whether the part is an explicit inline attachment.*/
    public var isInlineAttachment : Bool {
        set { nativeInstance.isInlineAttachment = newValue }
        get { return nativeInstance.isInlineAttachment }
    }
    
    /** Returns whether the part is an explicit attachment.*/
    public var isAttachment : Bool {
        set { nativeInstance.isAttachment = newValue }
        get { return nativeInstance.isAttachment }
    }
    
    /** Returns the part with the given Content-ID among this part and its subparts.*/
    public func partForContentID(contentID: String) -> MCOAbstractPart? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: nativeInstance.partForContentID(contentID.mailCoreString()).toCObject())
        }
    }
    
    /** Returns the part with the given unique identifier among this part and its subparts.*/
    public func partForUniqueID(uniqueID: String) -> MCOAbstractPart? {
        return mailCoreAutoreleasePool {
            return createMCOObject(from: nativeInstance.partForUniqueID(uniqueID.mailCoreString()).toCObject())
        }
    }
    
    /** Returns a string representation of the data according to charset.*/
    public func decodedStringForData(data: Data) -> String? {
        return mailCoreAutoreleasePool {
            return nativeInstance.decodedStringForData(data.mailCoreData()).string()
        }
    }
    
    /** Adds a content type parameter.*/
    public func setContentTypeParameterValue(_ value: String, name: String) {
        return mailCoreAutoreleasePool {
            nativeInstance.setContentTypeParameter(value.mailCoreString(), name.mailCoreString())
        }
    }
    
    /** Remove a given content type parameter.*/
    public func removeContentTypeParameterForName(name: String) {
        return mailCoreAutoreleasePool {
            nativeInstance.removeContentTypeParameter(name.mailCoreString())
        }
    }
    
    /** Returns the value of a given content type parameter.*/
    public func contentTypeParameterValueForName(name: String) -> String? {
        return mailCoreAutoreleasePool {
            return nativeInstance.contentTypeParameterValueForName(name.mailCoreString()).string()
        }
    }
    
    /** Returns an array with the names of all content type parameters.*/
    public func allContentTypeParametersNames() -> Array<String>? {
        return mailCoreAutoreleasePool {
            return Array<String>(mailCoreArray: nativeInstance.allContentTypeParametersNames());
        }
    }
    
    public static func getData(_ part: MCOAbstractPart) -> Data? {
        return mailCoreAutoreleasePool {
            return Data(cdata: CAbstractPart.getData(part.nativeInstance))
        }
    }
}

