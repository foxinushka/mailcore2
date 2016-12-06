#ifndef CAbstractMessageRendererCallback_h
#define CAbstractMessageRendererCallback_h

#include "CBase.h"
#include "CArray.h"
#include "CMessageConstants.h"
#include "CAbstractPart.h"
#include "CDictionary.h"
#include "CMessageHeader.h"
#include "CAbstractMessage.h"
#include "CAbstractMessagePart.h"
#include "CIMAPPart.h"

#ifdef __cplusplus

class AbstractMessageRendererCallback;

extern "C" {
#endif
    
    typedef uint8_t         (^CanPreviewPartBlock)(CAbstractPart part);
    typedef uint8_t         (^ShouldShowPartBlock)(CAbstractPart part);
    typedef CDictionary     (^TemplateValuesForHeaderBlock)(CMessageHeader header);
    typedef CDictionary     (^TemplateValuesForPartBlock)(CAbstractPart part);
    typedef CObject         (^TemplateForMainHeaderBlock)(CMessageHeader header);
    typedef CObject         (^TemplateForImageBlock)(CAbstractPart part);
    typedef CObject         (^TemplateForAttachmentBlock)(CAbstractPart part);
    typedef CObject         (^TemplateForMessageBlock)(CAbstractMessage message);
    typedef CObject         (^TemplateForEmbeddedMessageBlock)(CAbstractMessagePart part);
    typedef CObject         (^TemplateForEmbeddedMessageHeaderBlock)(CMessageHeader header);
    typedef CObject         (^TemplateForAttachmentSeparatorBlock)();
    typedef CObject         (^CleanHTMLForPartBlock)(const UChar* html);
    typedef CObject         (^FilterHTMLForPartBlock)(const UChar* html);
    typedef CObject         (^FilterHTMLForMessageBlock)(const UChar* html);
    
    typedef CData           (^DataForIMAPPartBlock)(const UChar* folder, CIMAPPart part);
    typedef void            (^PrefetchAttachmentIMAPPartBlock)(const UChar* folder, CIMAPPart part);
    typedef void            (^PrefetchImageIMAPPartBlock)(const UChar* folder, CIMAPPart part);
    
    struct CAbstractMessageRendererCallback {
#ifdef __cplusplus
        AbstractMessageRendererCallback*        callbackBridge;
#else
        void*                                   callbackBridge;
#endif
        
        void (*setHtmlRendererDelegateCallbacks)(struct CAbstractMessageRendererCallback self,
                                                              CanPreviewPartBlock canPreviewPartBlock,
                                                              ShouldShowPartBlock shouldShowPartBlock,
                                                              TemplateValuesForHeaderBlock templateValuesForHeaderBlock,
                                                              TemplateValuesForPartBlock templateValuesForPartBlock,
                                                              TemplateForMainHeaderBlock templateForMainHeaderBlock,
                                                              TemplateForImageBlock templateForImageBlock,
                                                              TemplateForAttachmentBlock templateForAttachmentBlock,
                                                              TemplateForMessageBlock templateForMessageBlock,
                                                              TemplateForEmbeddedMessageBlock templateForEmbeddedMessageBlock,
                                                              TemplateForEmbeddedMessageHeaderBlock templateForEmbeddedMessageHeaderBlock,
                                                              TemplateForAttachmentSeparatorBlock templateForAttachmentSeparatorBlock,
                                                              CleanHTMLForPartBlock cleanHTMLForPartBlock,
                                                              FilterHTMLForPartBlock filterHTMLForPartBlock,
                                                              FilterHTMLForMessageBlock filterHTMLForMessageBlock);
        
        void (*setHtmlRedererImapDelefate)(struct CAbstractMessageRendererCallback self,
                                 DataForIMAPPartBlock dataForIMAPPartBlock,
                                 PrefetchAttachmentIMAPPartBlock prefetchAttachmentIMAPPartBlock,
                                 PrefetchImageIMAPPartBlock prefetchImageIMAPPartBlock);
    };
    typedef struct CAbstractMessageRendererCallback CAbstractMessageRendererCallback;
    
    CAbstractMessageRendererCallback newCAbstractMessageRendererCallback();
    
    void deleteCAbstractMessageRendererCallback(CAbstractMessageRendererCallback self);
    
#ifdef __cplusplus
}
#endif

#endif /* CAbstractMessageRendererCallback_h */
