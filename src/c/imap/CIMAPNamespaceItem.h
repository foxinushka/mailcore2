#ifndef CIMAPNamespaceItem_h
#define CIMAPNamespaceItem_h

#include "CBase.h"
#include "CArray.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPNamespaceItem;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPNamespaceItem, mailcore::IMAPNamespaceItem)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPNamespaceItem)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPNamespaceItem, MailCoreString, prefix, setPrefix)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CIMAPNamespaceItem, char, delimiter, setDelimiter)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespaceItem, MailCoreString, pathForComponents, CArray)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespaceItem, CArray, componentsForPath, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespaceItem, bool, containsFolder, MailCoreString)

    
#ifdef __cplusplus
}
#endif

#endif /* CIMAPNamespaceItem_h */
