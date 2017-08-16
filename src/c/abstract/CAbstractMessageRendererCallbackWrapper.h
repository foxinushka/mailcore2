//
//  CAbstractMessageRendererCallbackWrapper.h
//  mailcore2
//
//  Created by Andrew on 8/2/17.
//  Copyright © 2017 MailCore. All rights reserved.
//

#ifndef CAbstractMessageRendererCallbackWrapper_h
#define CAbstractMessageRendererCallbackWrapper_h




#ifdef __cplusplus

#include <MailCore/MCCore.h>
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

#ifdef __cplusplus
}

class AbstractMessageRendererCallback : public mailcore::Object, public mailcore::HTMLRendererTemplateCallback, public mailcore::HTMLRendererIMAPCallback {
public:
    AbstractMessageRendererCallback(CanPreviewPartBlock canPreviewPartBlock,
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
                                    const void* userInfo);
    
    virtual bool canPreviewPart(mailcore::AbstractPart * part);
    virtual bool shouldShowPart(mailcore::AbstractPart * part);
    virtual mailcore::HashMap * templateValuesForHeader(mailcore::MessageHeader * header);
    virtual mailcore::HashMap * templateValuesForPart(mailcore::AbstractPart * part);
    virtual mailcore::String * templateForMainHeader(mailcore::MessageHeader * header);
    virtual mailcore::String * templateForImage(mailcore::AbstractPart * part);
    virtual mailcore::String * templateForAttachment(mailcore::AbstractPart * part);
    virtual mailcore::String * templateForMessage(mailcore::AbstractMessage * message);
    virtual mailcore::String * templateForEmbeddedMessage(mailcore::AbstractMessagePart * part);
    virtual mailcore::String * templateForEmbeddedMessageHeader(mailcore::MessageHeader * header);
    virtual mailcore::String * templateForAttachmentSeparator();
    virtual mailcore::String * cleanHTMLForPart(mailcore::String * html);
    virtual mailcore::String * filterHTMLForPart(mailcore::String * html);
    virtual mailcore::String * filterHTMLForMessage(mailcore::String * html);
    virtual mailcore::Data * dataForIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part);
    virtual void prefetchAttachmentIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part);
    virtual void prefetchImageIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part);
    
private:
    CanPreviewPartBlock canPreviewPartBlock;
    ShouldShowPartBlock shouldShowPartBlock;
    TemplateValuesForHeaderBlock templateValuesForHeaderBlock;
    TemplateValuesForPartBlock templateValuesForPartBlock;
    TemplateForMainHeaderBlock templateForMainHeaderBlock;
    TemplateForImageBlock templateForImageBlock;
    TemplateForAttachmentBlock templateForAttachmentBlock;
    TemplateForMessageBlock templateForMessageBlock;
    TemplateForEmbeddedMessageBlock templateForEmbeddedMessageBlock;
    TemplateForEmbeddedMessageHeaderBlock templateForEmbeddedMessageHeaderBlock;
    TemplateForAttachmentSeparatorBlock templateForAttachmentSeparatorBlock;
    CleanHTMLForPartBlock cleanHTMLForPartBlock;
    FilterHTMLForPartBlock filterHTMLForPartBlock;
    FilterHTMLForMessageBlock filterHTMLForMessageBlock;
    
    DataForIMAPPartBlock dataForIMAPPartBlock;
    PrefetchAttachmentIMAPPartBlock prefetchAttachmentIMAPPartBlock;
    PrefetchImageIMAPPartBlock prefetchImageIMAPPartBlock;
    
    const void* userInfo;
};
#endif

#endif /* CAbstractMessageRendererCallbackWrapper_h */
