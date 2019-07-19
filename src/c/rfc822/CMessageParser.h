#ifndef CMessageParser_h
#define CMessageParser_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAttachment.h"
#include "CDictionary.h"

#ifdef __cplusplus

namespace mailcore {
    class MessageParser;
}

extern "C" {
#endif
    
    C_SYNTHESIZE_STRUCT_DEFINITION(CMessageParser, mailcore::MessageParser)
    CMAILCORE_EXPORT C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMessageParser)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CAbstractPart, mainPart)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CData, data)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, htmlBodyRendering)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, plainTextRendering)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, plainTextBodyRenderingAndStripWhitespace, bool)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CDictionary, serializable)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, htmlRendering, struct CAbstractMessageRendererCallback)
    
    CMAILCORE_EXPORT C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CMessageParser, CMessageParser, init, CData)
    CMAILCORE_EXPORT C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, void, saveToFile, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif /* CMessageParser_h */
