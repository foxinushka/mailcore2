import Foundation

class IndexSet {
	
	var indexSet:CIndexSet;
    
    init(cindexset: CIndexSet) {
        self.indexSet = cindexset;
    }

	init(start:UInt64, end:UInt64) {
 		self.indexSet = newCIndexSetWithRange(start, end);
	}

	deinit {
		deleteCIndexSet(indexSet);
	}
}
