import Foundation

extension String : Convertible  {
    
    init?(utf16 cString: UnsafePointer<UInt16>?) {
        guard let (s, _) = String.decodeCString(cString, as: UTF16.self,
                                                repairingInvalidCodeUnits: true) else {
                                                    return nil
        }
        self = s
    }
    
    func cast() -> CObject {
        return self.utf16({ newCObjectWithString($0) })
    }
    
    init(_ str: CObject) {
        self = String(utf16: str.castToString(str))!;
    }
    
    func utf16<T>(_ block: (_ ptr: UnsafePointer<UInt16>?)->T ) -> T {
        let utf16Optional = self.data(using: .utf16LittleEndian)
        if utf16Optional == nil {
            NSLog("\(self) can't be converted to utf16?")
            return block(nil);
        }
        var utf16 = utf16Optional!
        utf16.append(contentsOf: [0,0]) //Append U+0000 as terminator.
        return utf16.withUnsafeBytes({ (uint16p: UnsafePointer<UInt16>) -> T in
            return block(uint16p);
        })
    }
}
