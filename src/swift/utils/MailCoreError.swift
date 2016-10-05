import Foundation

public class MailCoreError : Error {
    
    public var errorCode: UInt32;
    public var errorMessage: String;
    
    internal init(code: ErrorCode) {
        self.errorCode = code.rawValue;
        //Add localization
        self.errorMessage = "";
    }
    
}
