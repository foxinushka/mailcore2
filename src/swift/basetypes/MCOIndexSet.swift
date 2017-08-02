import Foundation


/** similar to NSMutableIndexSet but supports int64_t.  MCRange has a location (uint64_t) and length (uint64_t). */
public class MCOIndexSet: NSObject, NSCopying {
    
    internal var nativeInstance: CIndexSet;
    
    internal func cast() -> CIndexSet {
        return nativeInstance;
    }
    
    public override init() {
        self.nativeInstance = CIndexSet_new();
    }
    
    internal init(_ indexSet: CIndexSet) {
        self.nativeInstance = indexSet;
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** Creates an index set that contains a range of integers.*/
    public convenience init(range: MailCore.Range) {
        self.init(CIndexSet(range: range));
    }
    
    /** Creates an index set with a single integer.*/
    public convenience init(index: UInt64) {
        self.init(CIndexSet(idx: index));
    }
    
    /** Returns the number of integers in that index set.*/
    public func count() -> UInt32 {
        return nativeInstance.count
    }
    
    /** Adds an integer to the index set.*/
    public func add(index: UInt64) {
        nativeInstance.addIndex(idx: index);
    }
    
    /** Removes an integer from the index set.*/
    public func remove(index: UInt64) {
        nativeInstance.removeIndex(idx: index);
    }
    
    /** Returns YES if the index set contains the given integer.*/
    public func contains(index: UInt64) -> Bool {
        return nativeInstance.containsIndex(idx: index);
    }
    
    /** Adds a range of integers to the index set.*/
    public func add(range: MailCore.Range) {
        nativeInstance.addRange(range: range);
    }
    
    /** Removes a range of integers from the index set.*/
    public func remove(range: MailCore.Range) {
        nativeInstance.removeRange(range: range);
    }
    
    /** Removes all integers that are not in the given range.*/
    public func intersects(range: MailCore.Range) {
        nativeInstance.intersectsRange(range: range);
    }
    
    /** Adds all indexes from an other index set to the index set.*/
    public func add(indexSet: MCOIndexSet) {
        nativeInstance.addIndexSet(indexSet: indexSet.nativeInstance);
    }
    
    /** Remove all indexes from an other index set from the index set.*/
    public func remove(indexSet: MCOIndexSet) {
        nativeInstance.removeIndexSet(indexSet: indexSet.nativeInstance);
    }
    
    /** Removes all integers that are not in the given index set.*/
    public func intersects(indexSet: MCOIndexSet) {
        nativeInstance.intersectsIndexSet(indexSet: indexSet.nativeInstance);
    }
    
    /** Returns all the ranges of ths index set.*/
    public func allRanges() -> Array<MailCore.Range> {
        var array  = Array<MailCore.Range>();
        for index in 0 ..< self.rangesCount() {
            array.append(nativeInstance.range(idx: index));
        }
        return array;
    }
    
    /** Returns the number of ranges in this index set.*/
    public func rangesCount() -> UInt32 {
        return nativeInstance.rangesCount();
    }
    
    /** Returns an NSIndexSet from a MCOIndexSet */
    public func foundationIndexSet() -> IndexSet {
        var result = IndexSet();
        let ranges = self.allRanges();
        for range in ranges {
            result.insert(integersIn: Int(range.location)...Int(range.location + range.length));
        }
        return result;
    }
    
    public func enumerate(_ block: (_ idx: UInt64) -> Void) {
        let ranges = allRanges()
        for i in 0 ..< Int(rangesCount()) {
            for k in 0 ... ranges[i].length {
                block(ranges[i].location + k)
            }
        }
    }
    
    public subscript(index: UInt32) -> MailCore.Range {
        return nativeInstance.range(idx: index)
    }
    
    public func copy(with zone: NSZone? = nil) -> Any {
        return copyIndexSet()
    }
    
    public func copyIndexSet() -> MCOIndexSet {
        return MCOIndexSet.init(self.nativeInstance.copy())
    }
}

public extension IndexSet {

    public func mcoIndexSet() -> MCOIndexSet {
        let mcoIndexSet = MCOIndexSet()
        for range in self.rangeView {
            mcoIndexSet.add(range: RangeMake(UInt64(range.lowerBound), UInt64(range.upperBound - range.lowerBound)))
        }
        return mcoIndexSet
    }
}

