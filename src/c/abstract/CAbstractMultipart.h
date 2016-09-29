#ifndef MAILCORE_CABSTRACT_MULTIPART_H
#define MAILCORE_CABSTRACT_MULTIPART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CMessageHeader;
    struct CAbstractPart;
    
    struct CAbstractMultipart {
        CAbstractPart abstractPart;
        
        CArray      (*parts)(struct CAbstractMultipart self);
        void        (*setParts)(struct CAbstractMultipart self, CArray parts);
    };
    typedef struct CAbstractMultipart CAbstractMultipart;
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAbstractMultipart newCAbstractMultipart(mailcore::AbstractPart *part);
mailcore::AbstractMultipart* cast(CAbstractMultipart part);
#endif

#endif
