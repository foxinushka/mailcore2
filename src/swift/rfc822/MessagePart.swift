//
//  MCOMessagePart.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class MCOMessagePart : MCOAbstractMessagePart {
    
    private var nativeInstance:CMessagePart;
    
    public required init(mailCoreObject: CObject) {
        self.nativeInstance = CMessagePart.init(cobject: mailCoreObject)
        self.nativeInstance.retain()
        super.init(mailCoreObject: mailCoreObject)
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    override func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    /** A part identifier is of the form 1.2.1*/
    public var partID: String? {
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.partID.string()
            }
        }
        set {
            mailCoreAutoreleasePool {
                nativeInstance.partID = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
    }
    
}
