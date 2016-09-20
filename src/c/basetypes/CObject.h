#ifndef MAILCORE_COBJECT_H
#define MAILCORE_COBJECT_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CObject {
        ref self;
    };
    typedef struct CObject CObject;

    CObject newCObject();
    void deleteCObject(CObject self);
    
#ifdef __cplusplus
}
#endif

#endif