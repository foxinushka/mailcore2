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
    C_SYNTHESIZE_COBJECT_CAST_DEFINITION(CMessageParser)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CAbstractPart, mainPart)
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CData, data)
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, htmlBodyRendering)
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, plainTextRendering)
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, plainTextBodyRenderingAndStripWhitespace, bool)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, CDictionary, serializable)
    
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, MailCoreString, htmlRendering, struct CAbstractMessageRendererCallback)
    
    C_SYNTHESIZE_STATIC_FUNC_DEFINITION(CMessageParser, CMessageParser, init, CData)
    C_SYNTHESIZE_FUNC_DEFINITION(CMessageParser, void, saveToFile, MailCoreString)
    
#ifdef __cplusplus
}
#endif

#endif /* CMessageParser_h */
