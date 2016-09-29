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
}



