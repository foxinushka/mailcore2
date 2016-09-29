#include <MailCore/MCCore.h>
#include "CArray.h"

void addObject(struct CArray array, CObject object) {
    cast(array)->addObject(reinterpret_cast<mailcore::Object *>(object.nativeInstance));
}

CArray newCArray() {
    return newCArray(new mailcore::Array());
}

void deleteCArray(CArray array) {

}

CArray newCArray(mailcore::Array *array) {
    CArray self;
    self.nativeInstance = array;
    self.addObject = &addObject;
    return self;
}

mailcore::Array* cast(CArray array){
    return reinterpret_cast<mailcore::Array*>(array.nativeInstance);
}
