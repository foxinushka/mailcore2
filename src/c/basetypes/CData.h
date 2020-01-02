#ifndef MAILCORE_CDATA_H
#define MAILCORE_CDATA_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"

#ifdef __cplusplus

#include <typeinfo>

namespace mailcore {
    class Data;
}

extern "C" {
#endif
    
    typedef void (*CBytesDeallocator)(char * bytes, unsigned int length);
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CData, mailcore::Data)
	C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CData)
    
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CData, const char*, bytes)
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CData, unsigned int, length)
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CData, bool, externallyAllocatedMemory)
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CData, CBytesDeallocator, bytesDeallocator)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CData, void, destructiveDataClear)
    
	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CData, CData, dataWithBytes, const char*, unsigned int)

	CMAILCORE_EXPORT CData Value_mailCoreTypeInfo(void);
	CMAILCORE_EXPORT CData getTypeNameFromObject(CObject obj);
    
#ifdef __cplusplus
}
CMAILCORE_EXPORT CData getTypeNameFromObject(const std::type_info * info);
#endif

#endif
