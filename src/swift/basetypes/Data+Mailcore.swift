import Foundation

extension Data {
    
    public init(cdata: CData) {
        self = Data.init(bytes: cdata.bytes, count: Int(cdata.lenght));
    }
    
}
