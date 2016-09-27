import Foundation

extension String {
    public init?(utf16 cString: UnsafePointer<UInt16>) {
        guard let (s, _) = String.decodeCString(cString, as: UTF16.self,
                                                repairingInvalidCodeUnits: false) else {
                                                    return nil
        }
        self = s
    }
    
    public var utf16CString: [UInt16] {
        get { return [UInt16](self.utf16); }
    }
}
