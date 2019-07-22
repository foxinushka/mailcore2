#ifndef CAttachment_h
#define CAttachment_h

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class Attachment;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CAttachment, mailcore::Attachment)
    
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAttachment)
    
    C_SYNTHESIZE_PROPERTY_DEFINITION(CAttachment, CData, data, setData)
    C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CAttachment, MailCoreString, decodedString)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, MailCoreString, mimeTypeForFilename, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithContentsOfFile, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithData, MailCoreString, CData)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithHTMLString, MailCoreString)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithRFC822Message, CData)
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithText, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif /* CAttachment_h */
