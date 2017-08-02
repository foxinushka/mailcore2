import Foundation


extension Dictionary {
    
    static func cast<K: Convertible, T: Convertible>(_ dict:CDictionary) -> Dictionary<K, T> {
        var result = Dictionary<K, T>();
        let keys = dict.allKeys();
        let size = keys.size
        for index in 1...size {
            let mcKey = keys.getObject(index: index);
            let mcValue = dict.getValue(key: mcKey);
            result[K(cobject: mcKey)] = T(cobject: mcValue);
        }
        return result;
    }
    
    static func cast<K: Convertible, T: Convertible>(_ dict:Dictionary<K, T>) -> CDictionary {
        let result = CDictionary();
        for (key, value) in dict {
            result.setValue(key: key.cast(), value: value.cast());
        }
        return result;
    }
}



