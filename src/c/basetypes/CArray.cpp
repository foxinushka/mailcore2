#include <MailCore/MCCore.h>
#include <MailCore/MCValue.h>
#include "CArray.h"

void addObject(struct CArray array, CObject object) {
    array.instance->addObject(reinterpret_cast<mailcore::Object *>(object.instance));
}

uint32_t size(struct CArray self) {
    return self.instance->count();
}

mailcore::Object* getObj(struct CArray self, uint32_t index) {
    return self.instance->objectAtIndex(index);
}

CObject getObject(struct CArray self, uint32_t index) {
    mailcore::Object* obj = getObj(self, index);
    return newCObject(obj);
}

uint32_t getUint(struct CArray self, uint32_t index) {
    return ((mailcore::Value*)self.instance->objectAtIndex(index))->unsignedIntValue();
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
    self.size = &size;
    self.getObject = &getObject;
    self.getUint = &getUint;
    
    return self;
}
