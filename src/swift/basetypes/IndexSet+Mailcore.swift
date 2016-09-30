import Foundation

extension IndexSet {
    
    static func cast(_ indexSet: CIndexSet) -> IndexSet {
        var result = IndexSet();
        func enumerateRanges(location: UInt64, length: UInt64) -> Void {
            result.insert(integersIn: Range<IndexSet.Element>(uncheckedBounds: (Int(location), Int(location + length))));
        }
        indexSet.enumerateRanges(indexSet, enumerateRanges);
        return result;
    }
    
    static func cast(_ indexSet: IndexSet) -> CIndexSet {
        let result = newCIndexSet();
        for range in indexSet.rangeView {
            result.addRange(result, UInt64(range.startIndex), UInt64(range.endIndex - range.startIndex));
        }
        return result;
    }
}
