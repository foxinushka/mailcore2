import Foundation
import CCore

extension String : Convertible  {
    
    init?(utf16 cString: UnsafePointer<UInt16>?) {
        guard let (s, _) = String.decodeCString(cString, as: UTF16.self,
                                                repairingInvalidCodeUnits: true) else {
                                                    return nil
        }
        self = s
    }
    
    func cast() -> CObject {
        return String.utf16(self, { CObject(string: $0) })
    }
    
    init(_ str: CObject) {
        self = String(utf16: str.castToString())!;
    }
    
    static func utf16<T>(_ str1: String?, _ str2: String?, _ block: (_ ptr1: UnsafePointer<UInt16>?, _ ptr2: UnsafePointer<UInt16>?)->T ) -> T {
        return String.utf16(str1, { ptr1 in
            String.utf16(str2, { ptr2 in
                block(ptr1, ptr2)
            })
        })
    }
    
    static func utf16<T>(_ str: String?, _ block: (_ ptr: UnsafePointer<UInt16>?)->T ) -> T {
        let utf16Optional = str?.data(using: .utf16LittleEndian)
        if utf16Optional == nil {
            // if str is empty send nil to block
            return block(nil);
        }
        var utf16 = utf16Optional!
        utf16.append(contentsOf: [0,0]) //Append U+0000 as terminator.
        return utf16.withUnsafeBytes({ (uint16p: UnsafePointer<UInt16>) -> T in
            return block(uint16p);
        })
    }
    
//    func utf16<T>(_ block: (_ ptr: UnsafePointer<UInt16>?)->T ) -> T {
//        let utf16Optional = self.data(using: .utf16LittleEndian)
//        if utf16Optional == nil {
//            NSLog("\(self) can't be converted to utf16?")
//            return block(nil);
//        }
//        var utf16 = utf16Optional!
//        utf16.append(contentsOf: [0,0]) //Append U+0000 as terminator.
//        return utf16.withUnsafeBytes({ (uint16p: UnsafePointer<UInt16>) -> T in
//            return block(uint16p);
//        })
//    }
}
