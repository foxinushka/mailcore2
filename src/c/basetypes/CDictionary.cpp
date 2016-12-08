#include <MailCore/MCCore.h>

#include "CDictionary.h"
#include "CBase+Private.h"

#define nativeType mailcore::HashMap
#define structName CDictionary

CObject getValue(struct CDictionary self, CObject key);
void setValue(struct CDictionary self, CObject key, CObject value);

CArray allKeys(struct CDictionary self) {
    return newCArray(self.instance->allKeys());
}

CDictionary newCDictionary() {
    return newCDictionary(new mailcore::HashMap());
}

CDictionary newCDictionary(mailcore::HashMap *dict){
    CDictionary self;
    self.instance = dict;
    
    self.allKeys = &allKeys;
    self.getValue = &getValue;
    self.setValue = &setValue;
    
    return self;
}

CObject getValue(struct CDictionary self, CObject key) {
    return newCObject(self.instance->objectForKey(key.instance));
}

void setValue(struct CDictionary self, CObject key, CObject value) {
    self.instance->setObjectForKey(key.instance, value.instance);
}
