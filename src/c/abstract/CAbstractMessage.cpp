#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessage
#define structName CAbstractMessage

C_SYNTHESIZE_CONSTRUCTOR()
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_MAILCORE_OBJ(CMessageHeader, CMessageHeader_new, setHeader, header)

C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, partForContentID, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, partForUniqueID, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, attachments)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, htmlInlineAttachments)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, requiredPartsForRendering)
