import Foundation

internal protocol Convertible {
    func cast() -> CObject
    init(_: CObject)
}


