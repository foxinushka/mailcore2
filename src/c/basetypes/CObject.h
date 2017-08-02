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
    };
    typedef struct CObject CObject;
    
    uint32_t        CObject_castToUInt32(struct CObject self)
                    CF_SWIFT_NAME(CObject.castToUInt32(self:));
    
    CObject         CObject_new_WithUInt32(uint32_t string)
                    CF_SWIFT_NAME(CObject.init(uint32:));
    
    void            CObject_release(CObject self)
                    CF_SWIFT_NAME(CObject.release(self:));
    
#ifdef __cplusplus
}

CObject CObject_new(mailcore::Object *obj);
#endif

#endif
