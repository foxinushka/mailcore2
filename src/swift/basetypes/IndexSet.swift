import Foundation
import Glibc

class IndexSet {
	
	var indexSet:CIndexSet;

	init(start:UInt64, end:UInt64) {
 		self.indexSet = newCIndexSetWithRange(start, end);
	}

	deinit {
		deleteCIndexSet(indexSet);
	}
}