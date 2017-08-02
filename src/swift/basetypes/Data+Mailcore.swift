import Foundation


extension Data {
    
    public init(cdata: CData) {
        self = Data.init(bytes: cdata.bytes, count: Int(cdata.length));
    }
    
    public func mailCoreData() -> CData {
        return self.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> CData in
            return CData(bytes: bytes, length: UInt32(self.count))
        }
    }
    
}

extension NSData {
    
    public func mailCoreData() -> CData {
        let swiftData = self as Data
        return swiftData.mailCoreData()
    }
    
}
