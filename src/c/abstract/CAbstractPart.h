#ifndef MAILCORE_CABSTRACT_PART_H
#define MAILCORE_CABSTRACT_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageConstants.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractPart;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAbstractPart, mailcore::AbstractPart)
    
	C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAbstractPart)
    
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, PartType, partType, setPartType)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, filename, setFilename)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, mimeType, setMimeType)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, charset, setCharset)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, uniqueID, setUniqueID)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentID, setContentID)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, uniqueID, setUniqueID)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentLocation, setContentLocation)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentDescription, setContentDescription)
    
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, bool, isInlineAttachment, setInlineAttachment)
	C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, bool, isAttachment, setAttachment)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CAbstractPart, partForContentID, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CAbstractPart, partForUniqueID, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, MailCoreString, decodedStringForData, CData)
    
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, void, setContentTypeParameter, MailCoreString, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, void, removeContentTypeParameter, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, MailCoreString, contentTypeParameterValueForName, MailCoreString)
	C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CArray, allContentTypeParametersNames)

	C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAbstractPart, CData, getData, CAbstractPart)
    
#ifdef __cplusplus
}
#endif

#endif
