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
    
    typedef uint8_t         (*CanPreviewPartBlock)(const void* userInfo, CAbstractPart part);
    typedef uint8_t         (*ShouldShowPartBlock)(const void* userInfo, CAbstractPart part);
    typedef CDictionary     (*TemplateValuesForHeaderBlock)(const void* userInfo, CMessageHeader header);
    typedef CDictionary     (*TemplateValuesForPartBlock)(const void* userInfo, CAbstractPart part);
    typedef CObject         (*TemplateForMainHeaderBlock)(const void* userInfo, CMessageHeader header);
    typedef CObject         (*TemplateForImageBlock)(const void* userInfo, CAbstractPart part);
    typedef CObject         (*TemplateForAttachmentBlock)(const void* userInfo, CAbstractPart part);
    typedef CObject         (*TemplateForMessageBlock)(const void* userInfo, CAbstractMessage message);
    typedef CObject         (*TemplateForEmbeddedMessageBlock)(const void* userInfo, CAbstractMessagePart part);
    typedef CObject         (*TemplateForEmbeddedMessageHeaderBlock)(const void* userInfo, CMessageHeader header);
    typedef CObject         (*TemplateForAttachmentSeparatorBlock)(const void* userInfo);
    typedef CObject         (*CleanHTMLForPartBlock)(const void* userInfo, MailCoreString html);
    typedef CObject         (*FilterHTMLForPartBlock)(const void* userInfo, MailCoreString html);
    typedef CObject         (*FilterHTMLForMessageBlock)(const void* userInfo, MailCoreString html);
    
    typedef CData           (*DataForIMAPPartBlock)(const void* userInfo, MailCoreString folder, CIMAPPart part);
    typedef void            (*PrefetchAttachmentIMAPPartBlock)(const void* userInfo, MailCoreString folder, CIMAPPart part);
    typedef void            (*PrefetchImageIMAPPartBlock)(const void* userInfo, MailCoreString folder, CIMAPPart part);
    
    struct CAbstractMessageRendererCallback {
#ifdef __cplusplus
        AbstractMessageRendererCallback*        callbackBridge;
#else
        void*                                   callbackBridge;
#endif
    };
    typedef struct CAbstractMessageRendererCallback CAbstractMessageRendererCallback;
    
	CMAILCORE_EXPORT CAbstractMessageRendererCallback CAbstractMessageRendererCallback_new(CanPreviewPartBlock canPreviewPartBlock,
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
    
	CMAILCORE_EXPORT void       CAbstractMessageRendererCallback_retain(CAbstractMessageRendererCallback self)
                                CF_SWIFT_NAME(CAbstractMessageRendererCallback.retain(self:));
    
	CMAILCORE_EXPORT void       CAbstractMessageRendererCallback_release(CAbstractMessageRendererCallback self)
                                CF_SWIFT_NAME(CAbstractMessageRendererCallback.release(self:));
    
#ifdef __cplusplus
}
#endif

#endif /* CAbstractMessageRendererCallback_h */
