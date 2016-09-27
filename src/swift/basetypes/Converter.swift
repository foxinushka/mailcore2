import Foundation

func arrayFromC(_ arg: CArray) -> Array<Any> {
    var cArray: CArray = arg;
    var array = Array<Any>();
    let size = cArray.size(&cArray);
    for index in 1...size {
        array.append(cArray.getObject(&cArray, index));
    }
    return array;
}

func cArray(_ array: Array<Any>) -> UnsafeMutablePointer<CArray>?? {
    return nil;
}


