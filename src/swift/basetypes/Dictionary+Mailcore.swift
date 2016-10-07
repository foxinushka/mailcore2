import Foundation

extension Dictionary {
    
    static func cast<K: Convertible, T: Convertible>(_ dict:CDictionary) -> Dictionary<K, T> {
        var result = Dictionary<K, T>();
        let keys = dict.allKeys(dict);
        let size = keys.size(keys);
        for index in 1...size {
            let mcKey = keys.getObject(keys, index);
            let mcValue = dict.getValue(dict, mcKey);
            result[K(mcKey)] = T(mcValue);
        }
        return result;
    }
    
    static func cast<K: Convertible, T: Convertible>(_ dict:Dictionary<K, T>) -> CDictionary {
        let result = newCDictionary();
        for (key, value) in dict {
            result.setValue(result, key.cast(), value.cast());
        }
        return result;
    }
}



