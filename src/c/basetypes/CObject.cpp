#include <MailCore/MCCore.h>
#include "CObject.h"

const UChar* castToString(struct CObject self);
uint32_t     castToUInt32(struct CObject self);

CObject newCObject(mailcore::Object *obj) {
    CObject self;
    self.nativeInstance = obj;
    
    self.castToString = &castToString;
    self.castToUInt32 = &castToUInt32;
    
    return self;
}


mailcore::Object* cast(CObject self) {
    return reinterpret_cast<mailcore::Object*>(self.nativeInstance);
}

void deleteCObject(CObject indexSet) {
    //delete reinterpret_cast<mailcore::Object *>(indexSet.nativeInstance);
}

CObject newCObjectWithString(const UChar* string) {
    return newCObject(new mailcore::String(string));
}

const UChar* castToString(struct CObject self) {
	return ((mailcore::String *) cast(self))->unicodeCharacters();
}

CObject newCObjectWithUInt32(uint32_t value) {
    return newCObject(mailcore::Value::valueWithUnsignedIntValue(value));
}

uint32_t castToUInt32(struct CObject self) {
    return ((mailcore::Value *) cast(self))->unsignedIntValue();
}
