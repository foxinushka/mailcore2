#include "CIMAPNamespaceItem.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPNamespaceItem
#define structName CIMAPNamespaceItem

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STRING(setPrefix, prefix);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, pathForComponents, CArray)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, componentsForPath, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_SCALAR(bool, containsFolder, MailCoreString)
