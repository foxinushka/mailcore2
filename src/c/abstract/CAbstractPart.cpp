#include <MailCore/MCCore.h>
#include "CAbstractPart.h"
#include "CBase+Private.h"
#include "CData.h"

#define nativeType mailcore::AbstractPart
#define structName CAbstractPart

C_SYNTHESIZE_STRING(setFilename, filename);
C_SYNTHESIZE_STRING(setMimeType, mimeType);
C_SYNTHESIZE_STRING(setCharset, charset);
C_SYNTHESIZE_STRING(setUniqueID, uniqueID);
C_SYNTHESIZE_STRING(setContentID, contentID);
C_SYNTHESIZE_STRING(setContentLocation, contentLocation);
C_SYNTHESIZE_STRING(setContentDescription, contentDescription);
C_SYNTHESIZE_BOOL(setInlineAttachment, isInlineAttachment);
C_SYNTHESIZE_BOOL(setAttachment, isAttachment);
C_SYNTHESIZE_ENUM(PartType, mailcore::PartType, setPartType, partType)
C_SYNTHESIZE_COBJECT_CAST()

C_SYNTHESIZE_CONSTRUCTOR()

C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, partForContentID, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CAbstractPart, partForUniqueID, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_VOID(setContentTypeParameter, MailCoreString, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_VOID(removeContentTypeParameter, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, contentTypeParameterValueForName, MailCoreString)
C_SYNTHESIZE_FUNC_WITH_OBJ(CArray, allContentTypeParametersNames)

C_SYNTHESIZE_FUNC_WITH_OBJ(MailCoreString, decodedStringForData, CData)

CData CAbstractPart_getData(CAbstractPart part) {
    mailcore::AbstractPart *mcPart = reinterpret_cast<mailcore::AbstractPart*>(part.instance);
    if (mcPart->className()->isEqual(MCSTR("mailcore::Attachment"))) {
        mailcore::Attachment *att = reinterpret_cast<mailcore::Attachment*>(mcPart);
        return CData_new(att->data());
    }
    return CData_dataWithBytes(NULL, 0);
}


