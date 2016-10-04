import Foundation

extension Array {
    
    static func cast<T: Convertible>(_ cArray: CArray) -> Array<T> {
        var array = Array<T>();
        let size = cArray.size(cArray);
        for index in 1...size {
            array.append(T(cArray.getObject(cArray, index)));
        }
        return array;
    }
    
    static func cast<T: Convertible>(_ array: Array<T>) -> CArray {
        let cArray = newCArray();
        for convertable in array {
            cArray.addObject(cArray, convertable.cast());
        }
        return cArray;
    }
    
    func cast() -> CArray {
        let cArray = newCArray();
        for convertable in self {
            cArray.addObject(cArray, (convertable as! Convertible).cast());
        }
        return cArray;
    }
    
}
