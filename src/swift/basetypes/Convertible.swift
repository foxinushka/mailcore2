import Foundation
import CMailCore

internal protocol Convertible {
    func cast() -> CObject
    init(mailCoreObject: CObject)
}


