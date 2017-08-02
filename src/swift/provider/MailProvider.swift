//
//  MCOMailProvider.swift
//  mailcore2
//
//  Created by Andrew on 7/26/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation

public class MCOMailProvider: NSObject {
    
    internal var nativeInstance: CMailProvider
    
    internal init?(_ provider: CMailProvider) {
        guard provider.instance != nil else {
            return nil
        }
        self.nativeInstance = provider
    }
    
    public var imapServices: [MCONetService] {
        return Array<MCONetService>.cast(self.nativeInstance.imapServices)
    }
    
    public var smtpServices: [MCONetService] {
        return Array<MCONetService>.cast(self.nativeInstance.smtpServices)
    }

    
}
