import Foundation

extension UInt32 : Convertible  {
    
    func cast() -> CObject {
        return newCObjectWithUInt32(self);
    }
    
    init(_ obj: CObject) {
        self = obj.castToUInt32(obj);
    }
}
