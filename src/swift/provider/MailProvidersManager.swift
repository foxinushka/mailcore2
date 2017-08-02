//
//  CMailProvidersManager.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation

public class MCOMailProvidersManager: NSObject {
        
    internal var nativeInstance: CMailProvidersManager
    
    private init(_ manger: CMailProvidersManager) {
        self.nativeInstance = manger
    }
    
    public class func shared() -> MCOMailProvidersManager {
        return MCOMailProvidersManager.init(CMailProvidersManager_shared())
    }
    
    public func provider(forEmail: String) -> MCOMailProvider? {
        return MCOMailProvider.init(nativeInstance.provider(forEmail: forEmail.mailCoreString()))
    }
    
    public func provider(forMX: String) -> MCOMailProvider? {
        return MCOMailProvider.init(nativeInstance.provider(forMX: forMX.mailCoreString()))
    }
    
    public func provider(forIdentifier: String) -> MCOMailProvider? {
        return MCOMailProvider.init(nativeInstance.provider(forIdentifier: forIdentifier.mailCoreString()))
    }
}
