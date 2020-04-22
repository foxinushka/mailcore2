//
// Created by Alexander Smarus on 2019-07-22.
//

import Foundation

#if os(Windows)
// Windows compiler doesn't recognize Int in @objc enums
// error: '@objc' enum raw type 'Int' is not an integer type
public typealias IntEnum = Int32
#else
public typealias IntEnum = Int
#endif
