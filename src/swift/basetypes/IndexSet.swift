import Foundation

/** similar to NSMutableIndexSet but supports int64_t.  MCRange has a location (uint64_t) and length (uint64_t). */
public class IndexSet {
    
    internal var nativeInstance: CIndexSet;
    
    internal func cast() -> CIndexSet {
        return nativeInstance;
    }
    
    public init() {
        self.nativeInstance = newCIndexSet();
    }
    
    internal init(_ indexSet: CIndexSet) {
        self.nativeInstance = indexSet;
    }
    
    /** Creates an empty index set.*/
    public static func indexSet() -> IndexSet {
        return IndexSet();
    }
    
    /** Creates an index set that contains a range of integers.*/
    public static func indexSet(range: SwiftMailCore.Range) -> IndexSet {
        return IndexSet(newCIndexSetWithRange(range));
    }
    
    /** Creates an index set with a single integer.*/
    public static func indexSet(index: UInt64) -> IndexSet {
        return IndexSet(newCIndexSetWithIndex(index));
    }
    
    /** Returns the number of integers in that index set.*/
    public func count() -> UInt32 {
        return nativeInstance.count(nativeInstance);
    }
    
    /** Adds an integer to the index set.*/
    public func add(index: UInt64) {
        nativeInstance.addIndex(nativeInstance, index);
    }
    
    /** Removes an integer from the index set.*/
    public func remove(index: UInt64) {
        nativeInstance.removeIndex(nativeInstance, index);
    }
    
    /** Returns YES if the index set contains the given integer.*/
    public func contains(index: UInt64) -> Bool {
        return nativeInstance.containsIndex(nativeInstance, index);
    }
    
    /** Adds a range of integers to the index set.*/
    public func add(range: SwiftMailCore.Range) {
        nativeInstance.addRange(nativeInstance, range);
    }
    
    /** Removes a range of integers from the index set.*/
    public func remove(range: SwiftMailCore.Range) {
        nativeInstance.removeRange(nativeInstance, range);
    }
    
    /** Removes all integers that are not in the given range.*/
    public func intersects(range: SwiftMailCore.Range) {
        nativeInstance.intersectsRange(nativeInstance, range);
    }
    
    /** Adds all indexes from an other index set to the index set.*/
    public func add(indexSet: IndexSet) {
        nativeInstance.addIndexSet(nativeInstance, indexSet.nativeInstance);
    }
    
    /** Remove all indexes from an other index set from the index set.*/
    public func remove(indexSet: IndexSet) {
        nativeInstance.removeIndexSet(nativeInstance, indexSet.nativeInstance);
    }
    
    /** Removes all integers that are not in the given index set.*/
    public func intersects(indexSet: IndexSet) {
        nativeInstance.intersectsIndexSet(nativeInstance, indexSet.nativeInstance);
    }
    
    /** Returns all the ranges of ths index set.*/
    public func allRanges() -> Array<SwiftMailCore.Range> {
        var array  = Array<SwiftMailCore.Range>();
        for index in 1...self.rangesCount() {
            array.append(nativeInstance.range(nativeInstance, index));
        }
        return array;
    }
    
    /** Returns the number of ranges in this index set.*/
    public func rangesCount() -> UInt32 {
        return nativeInstance.rangesCount(nativeInstance);
    }
    
    /** Enumerates all the indexes of the index set.*/
    //- (void) enumerateIndexes:(void (^)(uint64_t idx))block;
    
    /** Returns an NSIndexSet from a MCOIndexSet */
    //- (NSIndexSet *) nsIndexSet;
    public func foundationIndexSet() -> Foundation.IndexSet {
        var result = Foundation.IndexSet();
        let ranges = self.allRanges();
        for range in ranges {
            result.insert(integersIn: Int(range.location)...Int(range.location + range.length));
        }
        return result;
    }
}

