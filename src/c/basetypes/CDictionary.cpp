#include <MailCore/MCCore.h>

#include "CDictionary.h"
#include "CBase+Private.h"

#define nativeType mailcore::HashMap
#define structName CDictionary

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, allKeys)
C_SYNTHESIZE_FUNC_WITH_OBJ(CObject, objectForKey, CObject)
C_SYNTHESIZE_FUNC_WITH_VOID(setObjectForKey, CObject, CObject)

CDictionary CDictionary_init() {
    return CDictionary_new(mailcore::HashMap::hashMap());
}
