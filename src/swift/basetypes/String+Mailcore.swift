import Foundation

#if os(Android)
    import CMailCore
#endif

extension String : Convertible  {
    
    //FIXME
    public func mailCoreString() -> MailCoreString {
        guard let uchars = self.data(using: .utf16LittleEndian) else {
            // instead of nil
            return MailCoreString()
        }
        return uchars.withUnsafeBytes({ (bytes: UnsafePointer<Int8>) -> MailCoreString in
            return MailCoreString.stringWithCharacters(bytes, UInt32(uchars.count / 2))
        })
    }
    
    func cast() -> CObject {
        return self.mailCoreString().toCObject()
    }
    
    init(mailCoreObject str: CObject) {
        let mailCoreString = MailCoreString.init(cobject: str)
        self = String(utf16CodeUnits: mailCoreString.unicodeCharacters, count: Int(mailCoreString.length))
    }
}

extension MailCoreString {

    public func string() -> String? {
        guard self.instance != nil else {
            return nil
        }
        if let unicodeCharacters = self.unicodeCharacters {
            return String(utf16CodeUnits: unicodeCharacters, count: Int(self.length))
        }
        else {
            return String()
        }
        
    }
    
}
