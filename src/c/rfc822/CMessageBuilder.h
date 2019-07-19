#ifndef CMessageBuilder_h
#define CMessageBuilder_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAttachment.h"

#include "MailCoreString.h"

#ifdef __cplusplus

namespace mailcore {
    class MessageBuilder;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CMessageBuilder, mailcore::MessageBuilder)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMessageBuilder)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CMessageBuilder, MailCoreString, htmlBody, setHTMLBody)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CMessageBuilder, MailCoreString, textBody, setTextBody)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CMessageBuilder, CArray, attachments, setAttachments)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CMessageBuilder, CArray, relatedAttachments, setRelatedAttachments)
    CMAILCORE_EXPORT C_SYNTHESIZE_PROPERTY_DEFINITION(CMessageBuilder, MailCoreString, boundaryPrefix, setBoundaryPrefix)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, void, addAttachment, CAttachment)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, void, addRelatedAttachment, CAttachment)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, CData, data)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, CData, dataForEncryption)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, ErrorCode, writeToFile, MailCoreString)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, CData, openPGPSignedMessageDataWithSignatureData, CData)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, CData, openPGPEncryptedMessageDataWithEncryptedData, CData)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, MailCoreString, htmlBodyRendering)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, MailCoreString, plainTextRendering)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, MailCoreString, plainTextBodyRenderingAndStripWhitespace, bool)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageBuilder, void, setBoundaries, CArray)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CMessageBuilder, CMessageBuilder, init)
    
#ifdef __cplusplus
}
#endif

#endif /* CMessageBuilder_h */
