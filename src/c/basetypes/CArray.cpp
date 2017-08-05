#include <MailCore/MCCore.h>
#include <MailCore/MCValue.h>
#include "CArray.h"
#include "CBase+Private.h"

#define nativeType mailcore::Array
#define structName CArray

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_FUNC_WITH_VOID(addObject, CObject)
C_SYNTHESIZE_FUNC_WITH_SCALAR(uint32_t, count)

mailcore::Object* CArray_getObj(struct CArray self, uint32_t index) {
    return self.instance->objectAtIndex(index);
}

CObject CArray_getObject(struct CArray self, uint32_t index) {
    mailcore::Object* obj = CArray_getObj(self, index);
    return CObject_new(obj);
}

uint32_t CArray_getUint(struct CArray self, uint32_t index) {
    return (reinterpret_cast<mailcore::Value*>(self.instance->objectAtIndex(index)))->unsignedIntValue();
}

CArray CArray_init() {
    return CArray_new(new mailcore::Array());
}

