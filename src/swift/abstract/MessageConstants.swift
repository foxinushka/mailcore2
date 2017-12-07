//
//  MessageConstants.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation


public struct MCOIMAPMessagesRequestKind : OptionSet {
    
    public let rawValue: Int
    
    public init(rawValue: Int) {
        self.rawValue = rawValue
    }
    
    public static let uid               = MCOIMAPMessagesRequestKind(rawValue: 0) // This is the default and it's always fetched
    public static let flags             = MCOIMAPMessagesRequestKind(rawValue: 1 << 0)
    public static let headers           = MCOIMAPMessagesRequestKind(rawValue: 1 << 1)
    public static let `structure`       = MCOIMAPMessagesRequestKind(rawValue: 1 << 2)
    public static let internalDate      = MCOIMAPMessagesRequestKind(rawValue: 1 << 3)
    public static let fullHeaders       = MCOIMAPMessagesRequestKind(rawValue: 1 << 4)
    public static let headerSubject     = MCOIMAPMessagesRequestKind(rawValue: 1 << 5)
    public static let gmailLabels       = MCOIMAPMessagesRequestKind(rawValue: 1 << 6)
    public static let gmailMessageID    = MCOIMAPMessagesRequestKind(rawValue: 1 << 7)
    public static let gmailThreadID     = MCOIMAPMessagesRequestKind(rawValue: 1 << 8)
    public static let extraHeaders      = MCOIMAPMessagesRequestKind(rawValue: 1 << 9)
    public static let size              = MCOIMAPMessagesRequestKind(rawValue: 1 << 10)
    
    internal func toCIMAPMessagesRequestKind() -> CIMAPMessagesRequestKind {
        return CIMAPMessagesRequestKind(rawValue: UInt32(self.rawValue))
    }
}

public struct MCOMessageFlag : OptionSet {

    public let rawValue: Int
    
    public init(rawValue: Int) {
        self.rawValue = rawValue
    }
    
    internal init(cMessageFlag: CMessageFlag) {
        self.rawValue = Int(cMessageFlag.rawValue)
    }
    
    public static let seen             = MCOMessageFlag(rawValue: 1 << 0)
    public static let answered         = MCOMessageFlag(rawValue: 1 << 1)
    public static let flagged          = MCOMessageFlag(rawValue: 1 << 2)
    public static let deleted          = MCOMessageFlag(rawValue: 1 << 3)
    public static let draft            = MCOMessageFlag(rawValue: 1 << 4)
    public static let mdnSent          = MCOMessageFlag(rawValue: 1 << 5)
    public static let forwarded        = MCOMessageFlag(rawValue: 1 << 6)
    public static let submitPending    = MCOMessageFlag(rawValue: 1 << 7)
    public static let submitted        = MCOMessageFlag(rawValue: 1 << 8)
    
    public static let maskAll: MCOMessageFlag = [.seen, .answered, .flagged, .deleted, .draft, .mdnSent, .forwarded, .submitPending, .submitted]
    
    internal func toCMessageFlag() -> CMessageFlag {
        return CMessageFlag(rawValue: UInt32(self.rawValue))
    }
}

public struct MCOAuthType : OptionSet {
    
    public let rawValue: Int
    
    public init(rawValue: Int) {
        self.rawValue = rawValue
    }
    
    internal init(cAuthType: CAuthType) {
        self.rawValue = Int(cAuthType.rawValue)
    }
    
    public static let SASLNone          = MCOAuthType(rawValue: 0)
    public static let SASLCRAMMD5       = MCOAuthType(rawValue: 1 << 0)
    public static let SASLPlain         = MCOAuthType(rawValue: 1 << 1)
    public static let SASLGSSAPI        = MCOAuthType(rawValue: 1 << 2)
    public static let SASLDIGESTMD5     = MCOAuthType(rawValue: 1 << 3)
    public static let SASLLogin         = MCOAuthType(rawValue: 1 << 4)
    public static let SASLSRP           = MCOAuthType(rawValue: 1 << 5)
    public static let SASLNTLM          = MCOAuthType(rawValue: 1 << 6)
    public static let SASLKerberosV4    = MCOAuthType(rawValue: 1 << 7)
    public static let XOAuth2           = MCOAuthType(rawValue: 1 << 8)
    public static let XOAuth2Outlook    = MCOAuthType(rawValue: 1 << 9)
    
    internal func toCAuthType() -> CAuthType {
        return CAuthType(rawValue: UInt32(self.rawValue))
    }
}

public struct MCOIMAPFolderFlag : OptionSet {

    public let rawValue: Int
    
    public init(rawValue: Int) {
        self.rawValue = rawValue
    }
    
    internal init(cIMAPFolderFlag: CIMAPFolderFlag) {
        self.rawValue = Int(cIMAPFolderFlag.rawValue)
    }
    
    public static let marked        = MCOIMAPFolderFlag(rawValue: 1 << 0)
    public static let unmarked      = MCOIMAPFolderFlag(rawValue: 1 << 1)
    public static let noSelect      = MCOIMAPFolderFlag(rawValue: 1 << 2)
    public static let noInferiors   = MCOIMAPFolderFlag(rawValue: 1 << 3)
    public static let inbox         = MCOIMAPFolderFlag(rawValue: 1 << 4)
    public static let sentMail      = MCOIMAPFolderFlag(rawValue: 1 << 5)
    public static let starred       = MCOIMAPFolderFlag(rawValue: 1 << 6)
    public static let allMail       = MCOIMAPFolderFlag(rawValue: 1 << 7)
    public static let trash         = MCOIMAPFolderFlag(rawValue: 1 << 8)
    public static let drafts        = MCOIMAPFolderFlag(rawValue: 1 << 9)
    public static let spam          = MCOIMAPFolderFlag(rawValue: 1 << 10)
    public static let important     = MCOIMAPFolderFlag(rawValue: 1 << 11)
    public static let archive       = MCOIMAPFolderFlag(rawValue: 1 << 12)
    
    public static let all: MCOIMAPFolderFlag       = [.allMail]
    public static let junk: MCOIMAPFolderFlag      = [.spam]
    public static let flagged: MCOIMAPFolderFlag   = [.starred]
    public static let typeMask: MCOIMAPFolderFlag  = [.inbox, .sentMail, .starred, .allMail, .trash, .drafts, .spam, .important, .archive]
    
    internal func toCIMAPFolderFlag() -> CIMAPFolderFlag {
        return CIMAPFolderFlag(rawValue: UInt32(self.rawValue))
    }
}
