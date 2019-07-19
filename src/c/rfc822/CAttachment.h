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
    
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CAttachment)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CAttachment, CData, data, setData)
    CMAILCORE_EXPORT C_SYNTHESIZE_READONLY_PROPERTY_DEFINITION(CAttachment, MailCoreString, decodedString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, MailCoreString, mimeTypeForFilename, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithContentsOfFile, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithData, MailCoreString, CData)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithHTMLString, MailCoreString)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithRFC822Message, CData)
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CAttachment, CAttachment, attachmentWithText, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif /* CAttachment_h */
