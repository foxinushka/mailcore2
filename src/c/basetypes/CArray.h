#ifndef MAILCORE_CARRAY_H
#define MAILCORE_CARRAY_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"

#ifdef __cplusplus

namespace  mailcore {
    class Array;
}

extern "C" {
#endif

    struct CArray {
        #ifdef __cplusplus
        mailcore::Array*         nativeInstance;
        #endif
        
    	void        (*addObject)(struct CArray self, CObject object);
        uint32_t    (*size)(struct CArray self);
        CObject     (*getObject)(struct CArray self, uint32_t index);
        uint32_t    (*getUint)(struct CArray self, uint32_t index);
    };
    typedef struct CArray CArray;

    CArray newCArray();
    
#ifdef __cplusplus
}

CArray newCArray(mailcore::Array *array);
#endif

#endif
