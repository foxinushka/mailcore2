#ifndef MAILCORE_CABSTRACT_MULTIPART_H
#define MAILCORE_CABSTRACT_MULTIPART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMultipart;
}

extern "C" {
#endif
    
    typedef struct CAbstractMultipart {
#ifdef __cplusplus
        mailcore::AbstractMultipart*    instance;
#else
        void*                           instance;
#endif
        CAbstractPart abstractPart;
    } CAbstractMultipart;
    
    CArray      CAbstractMultipart_parts(struct CAbstractMultipart self)
                CF_SWIFT_NAME(getter:CAbstractMultipart.parts(self:));
    
    void        CAbstractMultipart_setParts(struct CAbstractMultipart self, CArray parts)
                CF_SWIFT_NAME(setter:CAbstractMultipart.parts(self:newValue:));
    
#ifdef __cplusplus
}

CAbstractMultipart CAbstractMultipart_new(mailcore::AbstractMultipart *part);
#endif

#endif
