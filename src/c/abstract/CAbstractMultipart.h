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
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAbstractMultipart, mailcore::AbstractMultipart)
    
	C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAbstractMultipart)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractMultipart, CArray, parts, setParts)
    
#ifdef __cplusplus
}
#endif

#endif
