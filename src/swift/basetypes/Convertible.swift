import Foundation

#if os(Android)
    import CMailCore
#endif

internal protocol Convertible {
    func cast() -> CObject
    init(mailCoreObject: CObject)
}


