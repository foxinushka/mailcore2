#ifndef MAILCORE_CABSTRACT_MULTIPART_H
#define MAILCORE_CABSTRACT_MULTIPART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMultipart;
}

extern "C" {
#endif
    
    struct CMessageHeader;
    struct CAbstractPart;
    
    struct CAbstractMultipart {
#ifdef __cplusplus
        mailcore::AbstractMultipart*    instance;
#else
        void*                           instance;
#endif
        CAbstractPart abstractPart;
        
        CArray      (*parts)(struct CAbstractMultipart self);
        void        (*setParts)(struct CAbstractMultipart self, CArray parts);
    };
    typedef struct CAbstractMultipart CAbstractMultipart;
    
#ifdef __cplusplus
}

CAbstractMultipart newCAbstractMultipart(mailcore::AbstractMultipart *part);
#endif

#endif
