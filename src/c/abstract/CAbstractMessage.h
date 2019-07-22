#ifndef MAILCORE_CABSTRACT_MESSAGE_H
#define MAILCORE_CABSTRACT_MESSAGE_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessage;
}

extern "C" {
#endif
    
	C_SYNTHESIZE_STRUCT_DEFINITION(CAbstractMessage, mailcore::AbstractMessage)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAbstractMessage)
    
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractMessage, struct CMessageHeader, header, setHeader)

	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractMessage, CAbstractPart, partForContentID, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractMessage, CAbstractPart, partForUniqueID, MailCoreString)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractMessage, CArray, attachments)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractMessage, CArray, htmlInlineAttachments)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractMessage, CArray, requiredPartsForRendering)
    
#ifdef __cplusplus
}
#endif

#endif
