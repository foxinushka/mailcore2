#include "CIMAPFolder.h"
#include "CBase+Private.h"

#include <MailCore/MCCore.h>

#define nativeType mailcore::IMAPFolder
#define structName CIMAPFolder

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_STRING(setPath, path);
C_SYNTHESIZE_CHAR(setDelimiter, delimiter);
C_SYNTHESIZE_ENUM(CIMAPFolderFlag, mailcore::IMAPFolderFlag, setFlags, flags)
