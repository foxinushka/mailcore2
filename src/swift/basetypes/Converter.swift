import Foundation

#if os(iOS) || os(OSX)
import CMailCore
#endif

func cFromSwift(array: Array<CObject>) -> CArray {
	var carray = newCArray();
	for element in array {
		var obj: CObject  = element;
   		carray.addObject(&carray, &obj);
	}
    return carray;
}
