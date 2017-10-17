//
//  CMailProvidersManager.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

public class MCOMailProvidersManager: NSObjectCompat {
    
    public static let sharedManager = MCOMailProvidersManager()
    
    private override init() {
        super.init()
        if let filename = Bundle.init(for: MCOMailProvidersManager.self).path(forResource: "providers", ofType: "json") {
            CMailProvidersManager_shared().registerProvidersWithFilename(filename.mailCoreString())
        }
    }
    
    public func provider(forEmail: String) -> MCOMailProvider? {
        return createMCOObject(from: CMailProvidersManager_shared().providerForEmail(forEmail.mailCoreString()).toCObject())
    }
    
    public func provider(forMX: String) -> MCOMailProvider? {
        return createMCOObject(from: CMailProvidersManager_shared().providerForMX(forMX.mailCoreString()).toCObject())
    }
    
    public func provider(forIdentifier: String) -> MCOMailProvider? {
        return createMCOObject(from: CMailProvidersManager_shared().providerForIdentifier(forIdentifier.mailCoreString()).toCObject())
    }
}
