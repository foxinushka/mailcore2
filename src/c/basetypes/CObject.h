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

    struct CObject {
#ifdef __cplusplus
        mailcore::Object*   instance;
#else
        void*               instance;
#endif
        
        const UChar*    (*castToString)(struct CObject self);
        uint32_t        (*castToUInt32)(struct CObject self);
    };
    typedef struct CObject CObject;

    CObject newCObjectWithString(const UChar* string);
    CObject newCObjectWithUInt32(uint32_t string);
    void deleteCObject(CObject self);
    
#ifdef __cplusplus
}

CObject newCObject(mailcore::Object *obj);
#endif

#endif
