import Foundation

func arrayFromC(_ cArray: CArray) -> Array<Any> {
    var array = Array<Any>();
    let size = cArray.size(cArray);
    for index in 1...size {
        array.append(cArray.getObject(cArray, index));
    }
    return array;
}

func cArray(_ array: Array<Any>) -> CArray {
    return newCArray();
}


