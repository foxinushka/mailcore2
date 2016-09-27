import Foundation

public class MailCoreError : Error {
    
    var errorCode: UInt32;
    var errorMessage: String;
    
    init(code: ErrorCode) {
        self.errorCode = code.rawValue;
        //Add localization
        self.errorMessage = "";
    }
    
}
