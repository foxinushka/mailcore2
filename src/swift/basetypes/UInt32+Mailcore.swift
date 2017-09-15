import Foundation
import CMailCore

extension UInt32 : Convertible  {
    
    func cast() -> CObject {
        return CObject(uint32: self);
    }
    
    init(mailCoreObject obj: CObject) {
        self = obj.castToUInt32();
    }
}
