#ifndef MAILCORE_CIMAP_NAMESPACE_H
#define MAILCORE_CIMAP_NAMESPACE_H

#include "CBase.h"
#include "CArray.h"
#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class IMAPNamespace;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CIMAPNamespace, mailcore::IMAPNamespace)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CIMAPNamespace)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, MailCoreString, mainPrefix)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, char, mainDelimiter)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, CArray, prefixes)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, MailCoreString, pathForComponents, CArray)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, MailCoreString, pathForComponentsAndPrefix, CArray, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, CArray, componentsFromPath, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CIMAPNamespace, bool, containsFolderPath, MailCoreString)
    
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CIMAPNamespace, CIMAPNamespace, namespaceWithPrefix, MailCoreString, char)

#ifdef __cplusplus
}
#endif

#endif
