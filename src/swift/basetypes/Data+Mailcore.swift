import Foundation


extension Data {
    
    init?(cdata: CData) {
        guard cdata.instance != nil else {
            return nil
        }
        self = Data.init(bytes: cdata.bytes, count: Int(cdata.length));
    }
    
    public func mailCoreData() -> CData {
        return self.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> CData in
            return CData.dataWithBytes(bytes, UInt32(self.count))
        }
    }
    
}

extension NSData {
    
    public func mailCoreData() -> CData {
        let swiftData = self as Data
        return swiftData.mailCoreData()
    }
    
}
