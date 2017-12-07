import Foundation


extension Dictionary {
    
    static func cast<K: Convertible, T: Convertible>(_ dict:CDictionary) -> Dictionary<K, T> {
        var result = Dictionary<K, T>();
        if dict.instance == nil {
            return result
        }
        let keys = dict.allKeys();
        let size = keys.count
        for index in 0 ..< size {
            let mcKey = keys.getObject(index)
            if let key: K = createMCOObject(from: keys.getObject(index)),
                let value: T = createMCOObject(from: dict.objectForKey(mcKey)) {
                result[key] = value
            }
        }
        return result;
    }
    
    static func cast<K: Convertible, T: Convertible>(_ dict:Dictionary<K, T>?) -> CDictionary {
        guard let dict = dict else {
            return CDictionary()
        }
        let result = CDictionary_init();
        for (key, value) in dict {
            result.setObjectForKey(key.cast(), value.cast());
        }
        return result;
    }
}

extension Dictionary: Convertible {
    
    func cast() -> CObject {
        return dictionaryUnsafeCast(self).toCObject()
    }
    
    init(mailCoreObject: CObject) {
        self = dictionaryUnsafeCast(CDictionary(cobject: mailCoreObject)) as! Dictionary
    }
}

func dictionaryUnsafeCast(_ dict:CDictionary) -> Dictionary<AnyHashable, Any> {
    var result = Dictionary<AnyHashable, Any>();
    if dict.instance == nil {
        return result
    }
    let keys = dict.allKeys();
    let size = keys.count
    for index in  0 ..< size {
        let mcKey = keys.getObject(index)
        if let key = createMCOObjectWithoutConversion(from: keys.getObject(index)) as? AnyHashable,
            let value = createMCOObjectWithoutConversion(from: dict.objectForKey(mcKey)) {
            result[key] = value
        }
        else {
            assert(false, "Unknwon MCO type found")
        }
    }
    return result;
}

func dictionaryUnsafeCast(_ dict:Dictionary<AnyHashable, Any>?) -> CDictionary {
    guard let dict = dict else {
        return CDictionary()
    }
    let result = CDictionary_init();
    for (key, value) in dict {
        if let key = key as? Convertible, let value = value as? Convertible {
            result.setObjectForKey(key.cast(), value.cast());
        }
        else {
            assert(false, "Unknwon MCO type found")
        }
    }
    return result;
}



