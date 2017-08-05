//
//  SwiftConnectionLogger.swift
//  mailcore2
//
//  Created by Andrew on 7/31/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

import Foundation

public typealias ConnectionLogger = (_:UnsafeMutableRawPointer?, _:ConnectionLogType, _:Data?) -> Void

public class MCOConnectionLogger: NSObject {
    
    fileprivate var logger: ConnectionLogger
    
    public init(_ logger: @escaping ConnectionLogger) {
        self.logger = logger
    }
    
    func getRetainedPointer() -> UnsafeMutableRawPointer {
        // Make unbalanced retain
        return Unmanaged.passRetained(self).toOpaque()
    }
    
}

public func MCOConnectionLoggerLog(_ sender: UnsafeMutableRawPointer?, _ logType:ConnectionLogType, _ data: CData, _ userInfo: UnsafeMutableRawPointer?) {
    if let userInfo = userInfo {
        let selfSelf = Unmanaged<MCOConnectionLogger>.fromOpaque(userInfo).takeUnretainedValue()
        selfSelf.logger(sender, logType, Data(cdata: data))
    }
}

public func MCOConnectionLoggerRelease(_ userInfo: UnsafeMutableRawPointer?) {
    if let userInfo = userInfo {
        // Make unbalanced release
        Unmanaged<MCOConnectionLogger>.fromOpaque(userInfo).release()
    }
}

