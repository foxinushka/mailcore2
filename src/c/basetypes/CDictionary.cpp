#include <MailCore/MCCore.h>

#include "CDictionary.h"
#include "CBase+Private.h"

#define nativeType mailcore::HashMap
#define structName CDictionary


extern "C" CDictionary newCDictionary(){
    return newCDictionary(new mailcore::HashMap());
}

extern "C" void deleteCDictionary(CDictionary self){
    //delete cast(self);
}

CObject getValue(struct CDictionary self, CObject key);

CDictionary newCDictionary(mailcore::HashMap *dict){
    CDictionary self;
    self.nativeInstance = dict;
    return self;
}

mailcore::HashMap* cast(CDictionary self){
    return reinterpret_cast<mailcore::HashMap*>(self.nativeInstance);
}

CObject getValue(struct CDictionary self, CObject key) {
    return newCObject(cast(self)->objectForKey(cast(key)));
}
