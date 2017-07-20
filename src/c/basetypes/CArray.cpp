#include <MailCore/MCCore.h>
#include <MailCore/MCValue.h>
#include "CArray.h"

void CArray_addObject(struct CArray array, CObject object) {
    array.instance->addObject(reinterpret_cast<mailcore::Object *>(object.instance));
}

uint32_t CArray_size(struct CArray self) {
    return self.instance->count();
}

mailcore::Object* CArray_getObj(struct CArray self, uint32_t index) {
    return self.instance->objectAtIndex(index);
}

CObject CArray_getObject(struct CArray self, uint32_t index) {
    mailcore::Object* obj = CArray_getObj(self, index);
    return CObject_new(obj);
}

uint32_t CArray_getUint(struct CArray self, uint32_t index) {
    return ((mailcore::Value*)self.instance->objectAtIndex(index))->unsignedIntValue();
}

CArray CArray_new() {
    return CArray_new(new mailcore::Array());
}

void deleteCArray(CArray array) {

}

CArray CArray_new(mailcore::Array *array) {
    CArray self;
    self.instance = array;
    return self;
}
