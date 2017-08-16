import Foundation

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
