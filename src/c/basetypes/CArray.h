#ifndef MAILCORE_CARRAY_H
#define MAILCORE_CARRAY_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CArray {
        ref self;
    	void (*addObject)(struct CArray *self, CObject *object);
    };
    typedef struct CArray CArray;

    CArray newCArray();
    void deleteCArray(CArray self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CArray newCArray2(mailcore::Array *array);
mailcore::Array* cast(CArray *array);
#endif

#endif
