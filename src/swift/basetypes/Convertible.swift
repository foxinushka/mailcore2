import Foundation
import CCore

internal protocol Convertible {
    func cast() -> CObject
    init(_: CObject)
}


