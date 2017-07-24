import Foundation


extension Array {
    
    static func cast<T: Convertible>(_ cArray: CArray) -> Array<T> {
        var array = Array<T>();
        let size = cArray.size
        for index in 0..<size {
            array.append(T(cArray.getObject(index: index)));
        }
        return array;
    }
    
    static func cast<T: Convertible>(_ array: Array<T>) -> CArray {
        let cArray = CArray();
        for convertable in array {
            cArray.addObject(cobject: convertable.cast());
        }
        return cArray;
    }
    
    func cast() -> CArray {
        let cArray = CArray();
        for convertable in self {
            cArray.addObject(cobject: (convertable as! Convertible).cast());
        }
        return cArray;
    }
    
}
