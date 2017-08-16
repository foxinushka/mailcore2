import Foundation


/** similar to NSMutableIndexSet but supports int64_t.  MCRange has a location (uint64_t) and length (uint64_t). */
public class MCOIndexSet: NSObject, NSCopying, NSCoding {
    
    internal var nativeInstance: CIndexSet;
    
    internal func cast() -> CIndexSet {
        return nativeInstance;
    }
    
    public override init() {
        self.nativeInstance = CIndexSet_init();
    }
    
    init?(_ indexSet: CIndexSet) {
        guard  indexSet.instance != nil else {
            return nil
        }
        self.nativeInstance = indexSet;
        self.nativeInstance.retain()
    }
    
    public convenience init(foundationIndexSet: IndexSet) {
        self.init()
        
        for range in foundationIndexSet.rangeView {
            self.add(range: RangeMake(UInt64(range.lowerBound), UInt64(range.upperBound - range.lowerBound)))
        }
    }
    
    deinit {
        self.nativeInstance.release()
    }
    
    /** Creates an index set that contains a range of integers.*/
    public convenience init(range: MailCore.Range) {
        self.init(CIndexSet(range: range))!;
    }
    
    /** Creates an index set with a single integer.*/
    public convenience init(index: UInt64) {
        self.init(CIndexSet(idx: index))!;
    }
    
    /** Returns the number of integers in that index set.*/
    public func count() -> UInt32 {
        return nativeInstance.count
    }
    
    /** Adds an integer to the index set.*/
    public func add(_ index: UInt64) {
        nativeInstance.addIndex(index);
    }
    
    /** Removes an integer from the index set.*/
    public func remove(_ index: UInt64) {
        nativeInstance.removeIndex(index);
    }
    
    /** Returns YES if the index set contains the given integer.*/
    public func contains(_ index: UInt64) -> Bool {
        return nativeInstance.containsIndex(index);
    }
    
    /** Adds a range of integers to the index set.*/
    public func add(range: MailCore.Range) {
        nativeInstance.addRange(range);
    }
    
    /** Removes a range of integers from the index set.*/
    public func remove(range: MailCore.Range) {
        nativeInstance.removeRange(range);
    }
    
    /** Removes all integers that are not in the given range.*/
    public func intersects(range: MailCore.Range) {
        nativeInstance.intersectsRange(range);
    }
    
    /** Adds all indexes from an other index set to the index set.*/
    public func add(indexSet: MCOIndexSet) {
        nativeInstance.addIndexSet(indexSet.nativeInstance);
    }
    
    /** Remove all indexes from an other index set from the index set.*/
    public func remove(indexSet: MCOIndexSet) {
        nativeInstance.removeIndexSet(indexSet.nativeInstance);
    }
    
    /** Removes all integers that are not in the given index set.*/
    public func intersects(indexSet: MCOIndexSet) {
        nativeInstance.intersectsIndexSet(indexSet.nativeInstance);
    }
    
    /** Returns all the ranges of ths index set.*/
    public func allRanges() -> Array<MailCore.Range> {
        var array  = Array<MailCore.Range>();
        for index in 0 ..< self.rangesCount() {
            array.append(nativeInstance.range(index));
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
        return nativeInstance.range(index)
    }
    
    public func copy(with zone: NSZone? = nil) -> Any {
        return copyIndexSet()
    }
    
    public func copyIndexSet() -> MCOIndexSet {
        return MCOIndexSet.init(CIndexSet.init(cobject: self.nativeInstance.copy()))!
    }
    
    public convenience required init?(coder aDecoder: NSCoder) {
        guard let dict = aDecoder.decodeObject(forKey: "info") as? Dictionary<AnyHashable, Any> else {
            return nil
        }
        let serializable = dictionaryUnsafeCast(dict)
        self.init(CIndexSet.init(cobject: CObject.objectWithSerializable(serializable)))
    }
    
    public func encode(with aCoder: NSCoder) {
        let serialazable: CDictionary = self.nativeInstance.toCObject().serializable()
        let dict = dictionaryUnsafeCast(serialazable)
        aCoder.encode(dict, forKey: "info")
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

