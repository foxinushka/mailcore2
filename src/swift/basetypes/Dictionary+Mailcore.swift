import Foundation

func dictFromMailcoreUInt32UInt32(_ dict:CDictionary) -> Dictionary<UInt32, UInt32>? {
    var result = Dictionary<UInt32, UInt32>();
    var keys = dict.allKeys(dict);
    let size = keys.size(keys);
    for index in 1...size {
        let mcKey = keys.getUint(keys, index);
        let mcValue = dict.uintForKey(dict, mcKey);
        result[mcKey] = mcValue;
    }
    return result;
}



