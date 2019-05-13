//
//  MCOMailProvider.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class MCOMailProvider: NSObjectCompat, Convertible {
    
    internal var nativeInstance: CMailProvider
    
    required public init(mailCoreObject: CObject) {
        self.nativeInstance = CMailProvider(cobject: mailCoreObject)
        self.nativeInstance.retain()
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    func cast() -> CObject {
        return nativeInstance.toCObject()
    }
    
    public var imapServices: [MCONetService]? {
        return mailCoreAutoreleasePool {
            return Array<MCONetService>(mailCoreArray: self.nativeInstance.imapServices)
        }
    }
    
    public var smtpServices: [MCONetService]? {
        return mailCoreAutoreleasePool {
            return Array<MCONetService>(mailCoreArray: self.nativeInstance.smtpServices)
        }
    }
    
    public var identifier: String? {
        return mailCoreAutoreleasePool {
            return self.nativeInstance.identifier.string()
        }
    }

    
}
