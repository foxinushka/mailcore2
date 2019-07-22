#ifndef CDictionary_h
#define CDictionary_h

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CArray.h"
#include "CData.h"

#ifdef __cplusplus

namespace mailcore {
    class HashMap;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CDictionary, mailcore::HashMap)
	C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CDictionary)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, CArray, allKeys)
	C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, CObject, objectForKey, CObject)
	C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, void, setObjectForKey, CObject, CObject)
    
	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CDictionary, CDictionary, init)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CObject, CDictionary, serializable);
	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CObject, CObject, objectWithSerializable, CDictionary);
    
#ifdef __cplusplus
}
#endif

#endif /* CDictionary_hpp */
