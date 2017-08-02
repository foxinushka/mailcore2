#include <MailCore/MCCore.h>
#include "CObject.h"

CObject CObject_new(mailcore::Object *obj) {
    CObject self;
    self.instance = obj;
    return self;
}

void CObject_release(CObject indexSet) {
    //delete reinterpret_cast<mailcore::Object *>(indexSet.nativeInstance);
}

CObject CObject_new_WithUInt32(uint32_t value) {
    return CObject_new(mailcore::Value::valueWithUnsignedIntValue(value));
}

uint32_t CObject_castToUInt32(struct CObject self) {
    return (reinterpret_cast<mailcore::Value*>(self.instance))->unsignedIntValue();
}
