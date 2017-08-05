import Foundation


extension Array {
    
    static func cast<T: Convertible>(_ cArray: CArray) -> Array<T> {
        var array = Array<T>()
        if cArray.instance != nil {
            let size = cArray.count
            for index in 0 ..< size {
                if let obj: T = createMCOObject(from: cArray.getObject(index)) {
                    array.append(obj)
                }
            }
        }
        return array;
    }
    
    static func cast<T: Convertible>(_ array: Array<T>?) -> CArray {
        guard let array = array else {
            return CArray()
        }
        let cArray = CArray_init();
        for convertable in array {
            cArray.addObject(convertable.cast());
        }
        return cArray;
    }
    
    func cast() -> CArray {
        let cArray = CArray_init();
        for convertable in self {
            cArray.addObject((convertable as! Convertible).cast());
        }
        return cArray;
    }
    
}
