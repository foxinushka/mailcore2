//
//  CNetService.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation

public class MCONetService: NSObject, Convertible {
    
    internal var nativeInstance: CNetService
    
    internal init(service: CNetService) {
        self.nativeInstance = service
    }
    
    public required init(cobject obj: CObject) {
        self.nativeInstance = CNetService(cobject: obj)
    }
    
    func cast() -> CObject {
        return self.nativeInstance.toCObject()
    }
    
    public var port: UInt32 {
        get { return self.nativeInstance.port }
        set { self.nativeInstance.port = newValue }
    }
    
    public var hostname : String? {
        set { nativeInstance.hostname = newValue?.mailCoreString() ?? MailCoreString() }
        get { return nativeInstance.hostname.string() }
    }
    
    public var connectionType : ConnectionType {
        set { nativeInstance.connectionType = newValue }
        get { return nativeInstance.connectionType }
    }
    
    public func hostname(email: String) -> String? {
        return nativeInstance.normalizedHostname(email: email.mailCoreString()).string()
    }
    
}
