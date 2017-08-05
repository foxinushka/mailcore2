#ifndef MAILCORE_COBJECT_H
#define MAILCORE_COBJECT_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus

namespace  mailcore {
    class Object;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CObject, mailcore::Object)
    C_SYNTHESIZE_FUNC_DEFINITION(CObject, uint32_t, castToUInt32);
    
    CObject         CObject_new_WithUInt32(uint32_t string)
                    CF_SWIFT_NAME(CObject.init(uint32:));
    
#ifdef __cplusplus
}
#endif

#endif
