#include <MailCore/MCCore.h>

#include "CDictionary.h"
#include "CBase+Private.h"

#define nativeType mailcore::HashMap
#define structName CDictionary

CObject getValue(struct CDictionary self, CObject key);

CDictionary newCDictionary(mailcore::HashMap *dict){
    CDictionary self;
    self.nativeInstance = dict;
    return self;
}

CObject getValue(struct CDictionary self, CObject key) {
    return newCObject(self.nativeInstance->objectForKey(key.nativeInstance));
}
