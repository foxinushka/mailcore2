//
//  MCONSObjectCompat.swift
//  mailcore2
//
//  Created by Anton Pogonets on 17.10.17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation
import CMailCore

#if swift(>=4) && !os(Android)
    @objc(mco_NSObjectCompat)
    @objcMembers
    public class NSObjectCompat: NSObject {}
#else
    public class NSObjectCompat: NSObject {}
#endif

public func mailCoreAutoreleasePool<Result>(invoking body: () throws -> Result) rethrows -> Result {
    let autoreleasePool = CAutoreleasePool_init()
    defer {
        autoreleasePool.release()
    }
    return try body()
}
