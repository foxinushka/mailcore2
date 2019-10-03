//
//  Multipart.swift
//  mailcore2
//
//  Created by Andrew on 8/15/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class MCOMultipart : MCOAbstractMultipart {
    
    private var nativeInstance: CMultipart
    
    public required init(mailCoreObject: CObject) {
        self.nativeInstance = CMultipart(cobject: mailCoreObject)
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
