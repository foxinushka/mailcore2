import Foundation

extension String : Convertible  {
    
    init?(utf16 cString: UnsafePointer<UInt16>) {
        guard let (s, _) = String.decodeCString(cString, as: UTF16.self,
                                                repairingInvalidCodeUnits: false) else {
                                                    return nil
        }
        self = s
    }
    
    var utf16CString: [UInt16] {
        get { return [UInt16](self.utf16); }
    }
    
    func cast() -> CObject {
        return newCObjectWithString(self.utf16CString);
    }
    
    init(_ str: CObject) {
        self = String(utf16: str.castToString(str)!)!;
    }
}
