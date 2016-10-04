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
        
        CAbstractPart   (*mainPart)(struct CMessageParser self);
        CData           (*data)(struct CMessageParser self);
        const UChar*    (*htmlBodyRendering)(struct CMessageParser self);
        const UChar*    (*plainTextRendering)(struct CMessageParser self);
        const UChar*    (*plainTextBodyRendering)(struct CMessageParser self);
        const UChar*    (*plainTextBodyRenderingAndStripWhitespace)(struct CMessageParser self, bool stripWhitespace);
    };
    typedef struct CMessageParser CMessageParser;
    
    CMessageParser newCMessageParser(const char* bytes, unsigned int length);
    
#ifdef __cplusplus
}

CMessageParser newCMessageParser(mailcore::MessageParser *parser);
#endif

#endif /* CMessageParser_h */
