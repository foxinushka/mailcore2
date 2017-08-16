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

#include "CAbstractMessageRendererCallbackWrapper.h"


#ifdef __cplusplus
extern "C" {
#endif
    
    struct CAbstractMessageRendererCallback {
#ifdef __cplusplus
        AbstractMessageRendererCallback*        callbackBridge;
#else
        void*                                   callbackBridge;
#endif
    };
    typedef struct CAbstractMessageRendererCallback CAbstractMessageRendererCallback;
    
    CAbstractMessageRendererCallback    CAbstractMessageRendererCallback_new(CanPreviewPartBlock canPreviewPartBlock,
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
                                                                         FilterHTMLForMessageBlock filterHTMLForMessageBlock,
                                                                         DataForIMAPPartBlock dataForIMAPPartBlock,
                                                                         PrefetchAttachmentIMAPPartBlock prefetchAttachmentIMAPPartBlock,
                                                                         PrefetchImageIMAPPartBlock prefetchImageIMAPPartBlock,
                                                                         const void* userInfo)
                                        CF_SWIFT_NAME(CAbstractMessageRendererCallback.init(canPreviewPartBlock:shouldShowPartBlock:templateValuesForHeaderBlock:templateValuesForPartBlock:templateForMainHeaderBlock:templateForImageBlock:templateForAttachmentBlock:templateForMessageBlock:templateForEmbeddedMessageBlock:templateForEmbeddedMessageHeaderBlock:templateForAttachmentSeparatorBlock:cleanHTMLForPartBlock:filterHTMLForPartBlock:filterHTMLForMessageBlock:dataForIMAPPartBlock:prefetchAttachmentIMAPPartBlock:prefetchImageIMAPPartBlock:userInfo:));
    
    void    CAbstractMessageRendererCallback_retain(CAbstractMessageRendererCallback self)
    CF_SWIFT_NAME(CAbstractMessageRendererCallback.retain(self:));
    
    void    CAbstractMessageRendererCallback_release(CAbstractMessageRendererCallback self)
            CF_SWIFT_NAME(CAbstractMessageRendererCallback.release(self:));
    
#ifdef __cplusplus
}
#endif

#endif /* CAbstractMessageRendererCallback_h */
