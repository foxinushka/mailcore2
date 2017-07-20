#include <MailCore/MCCore.h>

#include "CDictionary.h"
#include "CBase+Private.h"

#define nativeType mailcore::HashMap
#define structName CDictionary

CObject CDictionary_getValue(struct CDictionary self, CObject key);
void setValue(struct CDictionary self, CObject key, CObject value);

CArray CDictionary_allKeys(struct CDictionary self) {
    return CArray_new(self.instance->allKeys());
}

CDictionary CDictionary_new() {
    return CDictionary_new(new mailcore::HashMap());
}

CDictionary CDictionary_new(mailcore::HashMap *dict){
    CDictionary self;
    self.instance = dict;
    return self;
}

CObject CDictionary_getValue(struct CDictionary self, CObject key) {
    return CObject_new(self.instance->objectForKey(key.instance));
}

void CDictionary_setValue(struct CDictionary self, CObject key, CObject value) {
    self.instance->setObjectForKey(key.instance, value.instance);
}
