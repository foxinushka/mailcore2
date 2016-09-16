#ifndef MAILCORE_CARRAY_H
#define MAILCORE_CARRAY_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CArray {
        ref self;
    };
    typedef struct CArray CArray;

    CArray newCArray();
    void deleteCArray(CArray self);
    
#ifdef __cplusplus
}
#endif

#endif