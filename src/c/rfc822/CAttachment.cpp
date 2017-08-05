#include <MailCore/MCCore.h>
#include "CAttachment.h"
#include "CBase+Private.h"

#define nativeType mailcore::Attachment
#define structName CAttachment

C_SYNTHESIZE_MAILCORE_OBJ(CData, CData_new, setData, data);
C_SYNTHESIZE_COBJECT_CAST()
C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, decodedString)

C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(MailCoreString, mimeTypeForFilename, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAttachment, attachmentWithContentsOfFile, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAttachment, attachmentWithData, MailCoreString, CData)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAttachment, attachmentWithHTMLString, MailCoreString)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAttachment, attachmentWithRFC822Message, CData)
C_SYNTHESIZE_STATIC_FUNC_WITH_OBJ(CAttachment, attachmentWithText, MailCoreString)


