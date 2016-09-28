#include <MailCore/MCCore.h>
#include "CArray.h"

extern "C" void addObject(struct CArray *array, CObject *object) {
    reinterpret_cast<mailcore::Array *>(array->self)->addObject(reinterpret_cast<mailcore::Object *>(object->self));
}

extern "C" CArray newCArray() {
    return newCArray2(new mailcore::Array());
}

extern "C" void deleteCArray(CArray array) {
    delete reinterpret_cast<mailcore::Array *>(array.self);
}

CArray newCArray2(mailcore::Array *array) {
    CArray self;
    self.self = array;
    self.addObject = &addObject;
    return self;
}

mailcore::Array* cast(CArray *array){
    return reinterpret_cast<mailcore::Array*>(array->self);
}

mailcore::Array* nativeInstance(CArray array) {
    return reinterpret_cast<mailcore::Array*>(array.self);
}
