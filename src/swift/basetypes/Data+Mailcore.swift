import Foundation
import CMailCore

extension Data {
    
    init?(cdata: CData) {
        guard cdata.instance != nil else {
            return nil
        }
        if let bytes = cdata.bytes {
            self = Data(bytes: bytes, count: Int(cdata.length))
        }
        else {
            self = Data()
        }
    }
    
    public func mailCoreData() -> CData {
        return self.withUnsafeBytes{(bytes: UnsafePointer<Int8>)-> CData in
            return CData.dataWithBytes(bytes, UInt32(self.count))
        }
    }
    
    init?(desctructiveCData data: CData) {
        guard data.instance != nil else {
            return nil
        }
        guard let pointer = UnsafeMutableRawPointer.init(mutating: data.bytes) else {
            return nil
        }
        let bytesDeallocator = data.bytesDeallocator
        let length = Int(data.length)
        let deallocator = data.externallyAllocatedMemory == false ? Data.Deallocator.free : Data.Deallocator.custom({ pointer, length in
            bytesDeallocator?(pointer.assumingMemoryBound(to: Int8.self), UInt32(length))
        })
        self = Data.init(bytesNoCopy: pointer, count: length, deallocator: deallocator)
    }
    
}

#if os(Android)
#else
    
extension NSData {
    
    public func mailCoreData() -> CData {
        let swiftData = self as Data
        return swiftData.mailCoreData()
    }
    
}
    
#endif
