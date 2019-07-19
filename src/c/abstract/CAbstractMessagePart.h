#ifndef MAILCORE_CABSTRACT_MESSAGE_PART_H
#define MAILCORE_CABSTRACT_MESSAGE_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"
#include "CMessageHeader.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessagePart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAbstractMessagePart, mailcore::AbstractMessagePart)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAbstractMessagePart)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractMessagePart, CMessageHeader, header, setHeader)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractMessagePart, CAbstractPart, mainPart, setMainPart)
    
#ifdef __cplusplus
}
#endif

#endif
