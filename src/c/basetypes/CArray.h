#ifndef MAILCORE_CARRAY_H
#define MAILCORE_CARRAY_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"
#include "CData.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class Array;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CArray, mailcore::Array)
	CMAILCORE_EXPORT  C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CArray)
    
	C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CArray, uint32_t, count)

	C_SYNTHESIZE_FUNC_DEFINITION(CArray, void, addObject, CObject)
	C_SYNTHESIZE_FUNC_DEFINITION(CArray, CObject, getObject, uint32_t)
	C_SYNTHESIZE_FUNC_DEFINITION(CArray, uint32_t, getUint, uint32_t)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CArray, MailCoreString, description)
    
	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CArray, CArray, init)
    
#ifdef __cplusplus
}
#endif

#endif
