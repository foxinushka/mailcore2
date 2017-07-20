import Foundation
import CCore

extension Data {
    
    public init(cdata: CData) {
        self = Data.init(bytes: cdata.bytes, count: Int(cdata.length));
    }
    
    internal func bytes() -> UnsafePointer<Int8>?{
        let bytes = self.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> UnsafePointer<Int8> in
            return bytes;
        }
        return bytes;
    }
    
    internal func length() -> UInt32 {
        return UInt32(self.count);
    }
    
}
