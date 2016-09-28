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
        
    	void        (*addObject)(struct CArray *self, CObject *object);
        uint32_t    (*size)(struct CArray *self);
        CObject     (*getObject)(struct CArray *self, uint32_t index);
        
        uint32_t    (*getUint)(struct CArray *self, uint32_t index);
    };
    typedef struct CArray CArray;

    CArray newCArray();
    void deleteCArray(CArray self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCCore.h>
CArray newCArray2(mailcore::Array *array);
mailcore::Array* cast(CArray *array);
mailcore::Array* nativeInstance(CArray array);
#endif

#endif
