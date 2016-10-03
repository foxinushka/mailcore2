#include <MailCore/MCCore.h>
#include "CArray.h"

void addObject(struct CArray array, CObject object) {
    array.instance->addObject(reinterpret_cast<mailcore::Object *>(object.instance));
}

CArray newCArray() {
    return newCArray(new mailcore::Array());
}

void deleteCArray(CArray array) {

}

CArray newCArray(mailcore::Array *array) {
    CArray self;
    self.instance = array;
    self.addObject = &addObject;
    return self;
}
