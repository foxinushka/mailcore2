#ifndef MAILCORE_COBJECT_H
#define MAILCORE_COBJECT_H

#include "stdint.h"
#include "CBase.h"

#ifdef __cplusplus
extern "C" {
#endif

    struct CObject {
        ref nativeInstance;
        
        const UChar*    (*castToString)(struct CObject self);
    };
    typedef struct CObject CObject;

    CObject newCObjectWithString(const UChar* string);
    void deleteCObject(CObject self);
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#include <MailCore/MCCore.h>
CObject newCObject(mailcore::Object *obj);
mailcore::Object* cast(CObject self);
#endif

#endif
