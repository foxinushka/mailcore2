//
//  MCOMessagePart.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation

public class MCOMessagePart : MCOAbstractMessagePart {
    
    private var nativeInstance:CMessagePart;
    
    // public for smartmailcore
    public init(part:CMessagePart) {
        self.nativeInstance = part;
        super.init(abstractMessagePart: part.abstractMessagePart);
    }
    
    required public init(cobject obj: CObject) {
        fatalError("init has not been implemented")
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get { return nativeInstance.partID.string() }
        set { nativeInstance.partID = newValue?.mailCoreString() ?? MailCoreString() }
    }
    
}
