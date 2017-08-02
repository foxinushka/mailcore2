#ifndef CMessageParser_h
#define CMessageParser_h

#include "CBase.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CAbstractMessage.h"
#include "CArray.h"
#include "CAttachment.h"

#ifdef __cplusplus

namespace mailcore {
    class MessageParser;
}

extern "C" {
#endif
    
    struct CMessageParser {
#ifdef __cplusplus
        mailcore::MessageParser*   instance;
#else
        void*                       instance;
#endif
        CAbstractMessage abstractMessage;
    };
    typedef struct CMessageParser CMessageParser;
    
    CAbstractPart   CMessageParser_mainPart(struct CMessageParser self)
                    CF_SWIFT_NAME(CMessageParser.mainPart(self:));
    
    CData           CMessageParser_data(struct CMessageParser self)
                    CF_SWIFT_NAME(CMessageParser.data(self:));
    
    MailCoreString    CMessageParser_htmlBodyRendering(struct CMessageParser self)
                    CF_SWIFT_NAME(CMessageParser.htmlBodyRendering(self:));
    
    MailCoreString    CMessageParser_plainTextRendering(struct CMessageParser self)
                    CF_SWIFT_NAME(CMessageParser.plainTextRendering(self:));
    
    MailCoreString    CMessageParser_plainTextBodyRendering(struct CMessageParser self)
                    CF_SWIFT_NAME(CMessageParser.plainTextBodyRendering(self:));
    
    MailCoreString    CMessageParser_plainTextBodyRenderingAndStripWhitespace(struct CMessageParser self, bool stripWhitespace)
                    CF_SWIFT_NAME(CMessageParser.plainTextBodyRenderingAndStripWhitespace(self:stripWhitespace:));
    
    CMessageParser  CMessageParser_new(CData data)
                    CF_SWIFT_NAME(CMessageParser.init(data:));
    
    MailCoreString    CMessageParser_htmlRendering(struct CMessageParser self, struct CAbstractMessageRendererCallback htmlCallback)
                    CF_SWIFT_NAME(CMessageParser.htmlRendering(self:delegate:));

    
#ifdef __cplusplus
}

CMessageParser CMessageParser_new(mailcore::MessageParser *parser);
#endif

#endif /* CMessageParser_h */
