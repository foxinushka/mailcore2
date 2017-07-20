import Foundation
import CCore

extension UInt32 : Convertible  {
    
    func cast() -> CObject {
        return CObject(uint32: self);
    }
    
    init(_ obj: CObject) {
        self = obj.castToUInt32();
    }
}
