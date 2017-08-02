import Foundation


public class MCOAbstractPart : Convertible {
    
    private var nativeInstance:CAbstractPart;
    
    internal init(_ abstractPart:CAbstractPart) {
        self.nativeInstance = abstractPart;
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
        set { nativeInstance.filename = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.filename.string() }
    }
    
    /** Returns MIME type of the part. For example application/data.*/
    public var mimeType : String? {
        set { nativeInstance.mimeType = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.mimeType.string() }
    }
    
    /** Returns charset of the part in case it's a text single part.*/
    public var charset : String? {
        set { nativeInstance.charset = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.charset.string() }
    }
    
    /** Returns the unique ID generated for this part.
     It's a unique identifier that's created when the object is created manually
     or created by the parser.*/
    public var uniqueID : String? {
        set { nativeInstance.uniqueID = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.uniqueID.string() }
    }
    
    /** Returns the value of the Content-ID field of the part.*/
    public var contentID : String? {
        set { nativeInstance.contentID = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.contentID.string() }
    }
    
    /** Returns the value of the Content-Location field of the part.*/
    public var contentLocation : String? {
        set { nativeInstance.contentLocation = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.contentLocation.string() }
    }
    
    /** Returns the value of the Content-Description field of the part.*/
    public var contentDescription : String? {
        set { nativeInstance.contentDescription = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.contentDescription.string () }
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
    public func partForContentID(contentID: String) -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.part(forContentID: contentID.mailCoreString()))
    }
    
    /** Returns the part with the given unique identifier among this part and its subparts.*/
    public func partForUniqueID(uniqueID: String) -> MCOAbstractPart {
        return MCOAbstractPart(nativeInstance.part(forUniqueID: uniqueID.mailCoreString()))
    }
    
    /** Returns a string representation of the data according to charset.*/
    public func decodedStringForData(data: Data) -> String? {
        let array = data.withUnsafeBytes {
            [UInt8](UnsafeBufferPointer(start: $0, count: data.count))
        }
        return nativeInstance.decodedStringForData(bytes: array, lenght: UInt32(array.count)).string()
    }
    
    /** Adds a content type parameter.*/
    public func setContentTypeParameterValue(value: String, name: String) {
        nativeInstance.setContentTypeParameterValue(value: value.mailCoreString(), name: name.mailCoreString())
    }
    
    /** Remove a given content type parameter.*/
    public func removeContentTypeParameterForName(name: String) {
        nativeInstance.removeContentTypeParameter(forName: name.mailCoreString())
    }
    
    /** Returns the value of a given content type parameter.*/
    public func contentTypeParameterValueForName(name: String) -> String? {
        return nativeInstance.contentTypeParameterValue(forName: name.mailCoreString()).string()
    }
    
    /** Returns an array with the names of all content type parameters.*/
    public func allContentTypeParametersNames() -> Array<String> {
        return Array<String>.cast(nativeInstance.allContentTypeParametersNames());
    }
    
    required public init(cobject obj: CObject) {
        self.nativeInstance = CAbstractPart(cObject: obj)
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject();
    }

}

