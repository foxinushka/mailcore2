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
	CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CDictionary)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, CArray, allKeys)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, CObject, objectForKey, CObject)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CDictionary, void, setObjectForKey, CObject, CObject)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CDictionary, CDictionary, init)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CObject, CDictionary, serializable);
	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CObject, CObject, objectWithSerializable, CDictionary);
    
#ifdef __cplusplus
}
#endif

#endif /* CDictionary_hpp */
