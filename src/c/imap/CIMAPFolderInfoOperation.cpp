#include "CIMAPFolderInfoOperation.h"
#include "CBase+Private.h"
#include <MailCore/MCAsync.h>

#define nativeType mailcore::IMAPFolderInfoOperation
#define structName CIMAPFolderInfoOperation

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_FUNC_WITH_OBJ(CIMAPFolderInfo, info)
