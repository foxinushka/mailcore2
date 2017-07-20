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

CObject CObject_new_WithString(const UChar* string) {
    return CObject_new(new mailcore::String(string));
}

const UChar* CObject_castToString(struct CObject self) {
	return ((mailcore::String *) self.instance)->unicodeCharacters();
}

CObject CObject_new_WithUInt32(uint32_t value) {
    return CObject_new(mailcore::Value::valueWithUnsignedIntValue(value));
}

uint32_t CObject_castToUInt32(struct CObject self) {
    return ((mailcore::Value *) self.instance)->unsignedIntValue();
}

CData CData_new(mailcore::Data data) {
    CData result;
    result.bytes = data.bytes();
    result.length = data.length();
    return result;
}

CData CData_new(const char* bytes, unsigned int length) {
    CData result;
    result.bytes = bytes;
    result.length = length;
    return result;
}

