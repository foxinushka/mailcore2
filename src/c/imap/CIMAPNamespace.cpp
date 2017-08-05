#include <MailCore/MCAsync.h>
#include "CIMAPNamespace.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespace
#define structName CIMAPNamespace

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

CIMAPNamespace CIMAPNamespace_namespaceWithPrefix(MailCoreString prefix, char delimiter) {
    return CIMAPNamespace_new(mailcore::IMAPNamespace::namespaceWithPrefix(prefix.instance, delimiter));
}

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, mainPrefix)
C_SYNTHESIZE_FUNC_WITH_SCALAR(char, mainDelimiter)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, prefixes)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, pathForComponents, CArray)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, pathForComponentsAndPrefix, CArray, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, componentsFromPath, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_SCALAR(bool, containsFolderPath, MailCoreString)

