//
//  CEnumInt.swift
//  SmartMailMessageParser
//
//  Created by Alexander Smarus on 03/06/19.
//  Copyright © 2019 Readdle. All rights reserved.
//

#if os(Windows)
public typealias CEnumInt = Int32
#else
public typealias CEnumInt = UInt32
#endif
