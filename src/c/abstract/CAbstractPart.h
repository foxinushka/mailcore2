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
    
	CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAbstractPart)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, PartType, partType, setPartType)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, filename, setFilename)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, mimeType, setMimeType)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, charset, setCharset)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, uniqueID, setUniqueID)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentID, setContentID)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, uniqueID, setUniqueID)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentLocation, setContentLocation)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, MailCoreString, contentDescription, setContentDescription)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, bool, isInlineAttachment, setInlineAttachment)
	CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAbstractPart, bool, isAttachment, setAttachment)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CAbstractPart, partForContentID, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CAbstractPart, partForUniqueID, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, MailCoreString, decodedStringForData, CData)
    
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, void, setContentTypeParameter, MailCoreString, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, void, removeContentTypeParameter, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, MailCoreString, contentTypeParameterValueForName, MailCoreString)
	CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CAbstractPart, CArray, allContentTypeParametersNames)

	CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAbstractPart, CData, getData, CAbstractPart)
    
#ifdef __cplusplus
}
#endif

#endif
