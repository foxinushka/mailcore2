#ifndef CIMAPFolder_h
#define CIMAPFolder_h

#include <stdio.h>

#include "CBase.h"
#include "CMessageConstants.h"
#include "CObject.h"

#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPFolder;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPFolder, mailcore::IMAPFolder)
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPFolder)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolder, MailCoreString, path, setPath)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolder, char, delimiter, setDelimiter)
    C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPFolder, CIMAPFolderFlag, flags, setFlags)
    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPFolder_h */
