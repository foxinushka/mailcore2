import Foundation

public class AbstractPart : Convertible {
    
    private var nativeInstance:CAbstractPart;
    
    internal init(_ abstractPart:CAbstractPart) {
        self.nativeInstance = abstractPart;
    }
    
    deinit {
        deleteCAbstractPart(self.nativeInstance);
    }
    
    internal func CAbstractPart() -> CAbstractPart {
        return nativeInstance;
    }
    
    /** Returns type of the part (single / message part / multipart/mixed,
     multipart/related, multipart/alternative). See MCOPartType.*/
    public var partType : PartType {
        set { nativeInstance.setPartType(nativeInstance, newValue); }
        get { return nativeInstance.partType(nativeInstance); }
    }
    
    /** Returns filename of the part.*/
    public var filename : String? {
        set { String.utf16(newValue, { nativeInstance.setFilename(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.filename(nativeInstance)); }
    }
    
    /** Returns MIME type of the part. For example application/data.*/
    public var mimeType : String? {
        set { String.utf16(newValue, { nativeInstance.setMimeType(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.mimeType(nativeInstance)); }
    }
    
    /** Returns charset of the part in case it's a text single part.*/
    public var charset : String? {
        set { String.utf16(newValue, { nativeInstance.setCharset(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.charset(nativeInstance)); }
    }
    
    /** Returns the unique ID generated for this part.
     It's a unique identifier that's created when the object is created manually
     or created by the parser.*/
    public var uniqueID : String? {
        set { String.utf16(newValue, { nativeInstance.setUniqueID(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.uniqueID(nativeInstance)); }
    }
    
    /** Returns the value of the Content-ID field of the part.*/
    public var contentID : String? {
        set { String.utf16(newValue, { nativeInstance.setContentID(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.contentID(nativeInstance)); }
    }
    
    /** Returns the value of the Content-Location field of the part.*/
    public var contentLocation : String? {
        set { String.utf16(newValue, { nativeInstance.setContentLocation(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.contentLocation(nativeInstance)); }
    }
    
    /** Returns the value of the Content-Description field of the part.*/
    public var contentDescription : String? {
        set { String.utf16(newValue, { nativeInstance.setContentDescription(nativeInstance, $0) }) }
        get { return String(utf16: nativeInstance.contentDescriprion(nativeInstance)); }
    }
    
    /** Returns whether the part is an explicit inline attachment.*/
    public var isInlineAttachment : Bool {
        set { nativeInstance.setInlineAttachment(nativeInstance, newValue); }
        get { return nativeInstance.isInlineAttachment(nativeInstance); }
    }
    
    /** Returns whether the part is an explicit attachment.*/
    public var isAttachment : Bool {
        set { nativeInstance.setAttachment(nativeInstance, newValue); }
        get { return nativeInstance.isAttachment(nativeInstance); }
    }
    
    /** Returns the part with the given Content-ID among this part and its subparts.*/
    public func partForContentID(contentID: String) -> AbstractPart {
        return AbstractPart(String.utf16(contentID, { nativeInstance.partForContentID(nativeInstance, $0) }));
    }
    
    /** Returns the part with the given unique identifier among this part and its subparts.*/
    public func partForUniqueID(uniqueID: String) -> AbstractPart {
        return AbstractPart(String.utf16(uniqueID, { nativeInstance.partForUniqueID(nativeInstance, $0) }));
    }
    
    /** Returns a string representation of the data according to charset.*/
    public func decodedStringForData(data: Data) -> String? {
        let array = data.withUnsafeBytes {
            [UInt8](UnsafeBufferPointer(start: $0, count: data.count))
        }
        return String(utf16: nativeInstance.decodedStringForData(nativeInstance, array, UInt32(array.count)));
    }
    
    /** Adds a content type parameter.*/
    public func setContentTypeParameterValue(value: String, name: String) {
        String.utf16(value, name, { valuePtr, namePtr in
            nativeInstance.setContentTypeParameterValue(nativeInstance, valuePtr, namePtr)
        })
    }
    
    /** Remove a given content type parameter.*/
    public func removeContentTypeParameterForName(name: String) {
        String.utf16(name, { nativeInstance.removeContentTypeParameterForName(nativeInstance, $0) })
    }
    
    /** Returns the value of a given content type parameter.*/
    public func contentTypeParameterValueForName(name: String) -> String? {
        return String.utf16(name, { String(utf16: nativeInstance.contentTypeParameterValueForName(nativeInstance, $0)) })
    }
    
    /** Returns an array with the names of all content type parameters.*/
    public func allContentTypeParametersNames() -> Array<String> {
        return Array<String>.cast(nativeInstance.allContentTypeParametersNames(nativeInstance));
    }
    
    required public init(_ obj: CObject) {
        self.nativeInstance = castFromCObject(obj);
    }
    
    internal func cast() -> CObject {
        return nativeInstance.castToCObject(nativeInstance);
    }

}

