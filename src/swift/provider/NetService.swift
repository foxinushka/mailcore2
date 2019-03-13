//
//  CNetService.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class MCONetService: NSObjectCompat, Convertible {
    
    internal var nativeInstance: CNetService
    
    public required init(mailCoreObject obj: CObject) {
        self.nativeInstance = CNetService.init(cobject: obj)
        self.nativeInstance.retain()
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    public var port: UInt32 {
        get { return self.nativeInstance.port }
        set { self.nativeInstance.port = newValue }
    }
    
    public var hostname : String? {
        set {
            mailCoreAutoreleasePool {
                nativeInstance.hostname = newValue?.mailCoreString() ?? MailCoreString()
            }
        }
        get {
            return mailCoreAutoreleasePool {
                nativeInstance.hostname.string()
            }
        }
    }
    
    public var connectionType : ConnectionType {
        set { nativeInstance.connectionType = newValue }
        get { return nativeInstance.connectionType }
    }
    
    public func hostname(email: String) -> String? {
        return mailCoreAutoreleasePool {
            return nativeInstance.normalizedHostnameWithEmail(email.mailCoreString()).string()
        }
    }
    
}
