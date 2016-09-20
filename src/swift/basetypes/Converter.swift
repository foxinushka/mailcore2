import Foundation
import Glibc

func cFromSwift(array: Array<CObject>) -> CArray {
	var carray = newCArray();
	for element in array {
		var obj: CObject  = element;
   		carray.addObject(&carray, &obj);
	}
    return carray;
}
