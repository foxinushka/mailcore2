import Foundation
import CMailCore

extension Array where Element: Convertible {
    
    init?(mailCoreArray cArray: CArray) {
        guard cArray.instance != nil else {
            return nil
        }
        self.init()
        let size = cArray.count
        for index in 0 ..< size {
            if let obj: Element = createMCOObject(from: cArray.getObject(index)) {
                self.append(obj)
            }
        }
    }
    
    func mailCoreArray() -> CArray {
        let cArray = CArray_init();
        for convertable in self {
            cArray.addObject(convertable.cast());
        }
        return cArray;
    }
}

extension Array: Convertible {
    
    init(mailCoreObject: CObject) {
        self = arrayUnsafeCast(CArray(cobject: mailCoreObject)) as! Array
    }
    
    func cast() -> CObject {
        return arrayUnsafeCast(self).toCObject()
    }
}

func arrayUnsafeCast(_ cArray: CArray) -> Array<Any>? {
    guard cArray.instance != nil else {
        return nil
    }
    var array = Array<Any>()
    let size = cArray.count
    for index in 0 ..< size {
        if let obj = createMCOObjectWithoutConversion(from: cArray.getObject(index)) {
            array.append(obj)
        }
    }
    return array
}

func arrayUnsafeCast(_ array: Array<Any>?) -> CArray {
    let cArray = CArray_init();
    for obj in array ?? [] {
        if let convertible = obj as? Convertible {
            cArray.addObject(convertible.cast());
        }
    }
    return cArray;
}
