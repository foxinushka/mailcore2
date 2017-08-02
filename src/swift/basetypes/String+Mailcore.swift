import Foundation


extension String : Convertible  {
    
    init(mailCoreString: MailCoreString) {
        self = String.init(utf16CodeUnits: mailCoreString.unicodeCharacters, count: Int(mailCoreString.length))
    }
    
    func mailCoreString() -> MailCoreString {
        guard let uchars = self.data(using: .utf16LittleEndian) else {
            // instead of nil
            return MailCoreString()
        }
        return uchars.withUnsafeBytes({ (bytes: UnsafePointer<Int8>) -> MailCoreString in
            return MailCoreString(uchar: bytes, length: UInt32(uchars.count / 2))
        })
    }
    
    func cast() -> CObject {
        return self.mailCoreString().toCObject()
    }
    
    init(cobject str: CObject) {
        self = String(mailCoreString: MailCoreString.init(cobject: str))
    }
}

extension MailCoreString {

    public func string() -> String? {
        guard self.instance != nil else {
            return nil
        }
        return String.init(utf16CodeUnits: self.unicodeCharacters, count: Int(self.length))
    }
    
}
