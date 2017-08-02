#ifndef MAILCORE_CARRAY_H
#define MAILCORE_CARRAY_H

#include "stdint.h"
#include "CBase.h"
#include "CObject.h"

#ifdef __cplusplus

namespace mailcore {
    class Array;
}

extern "C" {
#endif

    struct CArray {
#ifdef __cplusplus
        mailcore::Array*    instance;
#else
        void*               instance;
#endif
    };
    typedef struct CArray CArray;
    
    void        CArray_addObject(struct CArray self, CObject object)
                CF_SWIFT_NAME(CArray.addObject(self:cobject:));
    
    uint32_t    CArray_size(struct CArray self)
                CF_SWIFT_NAME(getter:CArray.size(self:));
    
    CObject     CArray_getObject(struct CArray self, uint32_t index)
                CF_SWIFT_NAME(CArray.getObject(self:index:));
    
    uint32_t    CArray_getUint(struct CArray self, uint32_t index)
                CF_SWIFT_NAME(CArray.getUint(self:index:));
    
    CArray      CArray_new()
                /* CF_SWIFT_NAME(CArray.init()) */;
    
#ifdef __cplusplus
}

CArray CArray_new(mailcore::Array *array);
#endif

#endif
