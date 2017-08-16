#include "CAbstractMessageRendererCallback.h"
#include <MailCore/MCAsync.h>
#include <MailCore/MCRenderer.h>
#include "CData.h"

AbstractMessageRendererCallback::AbstractMessageRendererCallback(CanPreviewPartBlock canPreviewPartBlock,
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
                                    const void* userInfo) {
    this->canPreviewPartBlock = canPreviewPartBlock;
    this->shouldShowPartBlock = shouldShowPartBlock;
    this->templateValuesForHeaderBlock = templateValuesForHeaderBlock;
    this->templateValuesForPartBlock = templateValuesForPartBlock;
    this->templateForMainHeaderBlock = templateForMainHeaderBlock;
    this->templateForImageBlock = templateForImageBlock;
    this->templateForAttachmentBlock = templateForAttachmentBlock;
    this->templateForMessageBlock = templateForMessageBlock;
    this->templateForEmbeddedMessageBlock = templateForEmbeddedMessageBlock;
    this->templateForEmbeddedMessageHeaderBlock = templateForEmbeddedMessageHeaderBlock;
    this->templateForAttachmentSeparatorBlock = templateForAttachmentSeparatorBlock;
    this->cleanHTMLForPartBlock = cleanHTMLForPartBlock;
    this->filterHTMLForPartBlock = filterHTMLForPartBlock;
    this->filterHTMLForMessageBlock = filterHTMLForMessageBlock;
    this->dataForIMAPPartBlock = dataForIMAPPartBlock;
    this->prefetchAttachmentIMAPPartBlock = prefetchAttachmentIMAPPartBlock;
    this->prefetchImageIMAPPartBlock = prefetchImageIMAPPartBlock;
    this->userInfo = userInfo;
}
    
bool AbstractMessageRendererCallback::canPreviewPart(mailcore::AbstractPart * part) {
    if (canPreviewPartBlock != NULL) {
        return canPreviewPartBlock(userInfo, CAbstractPart_new(part)) > 0;
    }
    return HTMLRendererTemplateCallback::canPreviewPart(part);
}
    
bool AbstractMessageRendererCallback::shouldShowPart(mailcore::AbstractPart * part) {
    if (shouldShowPartBlock != NULL) {
        return shouldShowPartBlock(userInfo, CAbstractPart_new(part)) > 0;
    }
    return HTMLRendererTemplateCallback::shouldShowPart(part);
}
    
mailcore::HashMap * AbstractMessageRendererCallback::templateValuesForHeader(mailcore::MessageHeader * header) {
    mailcore::HashMap * result = NULL;
    if (templateValuesForHeaderBlock != NULL) {
        result = templateValuesForHeaderBlock(userInfo, CMessageHeader_new(header)).instance;
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateValuesForHeader(header);
    }
    return result;
}
    
mailcore::HashMap * AbstractMessageRendererCallback::templateValuesForPart(mailcore::AbstractPart * part) {
    mailcore::HashMap * result = NULL;
    if (templateValuesForPartBlock != NULL) {
        result = templateValuesForPartBlock(userInfo, CAbstractPart_new(part)).instance;
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateValuesForPart(part);
    }
    return result;
}
    
mailcore::String * AbstractMessageRendererCallback::templateForMainHeader(mailcore::MessageHeader * header) {
    mailcore::String * result = NULL;
    if (templateForMainHeaderBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForMainHeaderBlock(userInfo, CMessageHeader_new(header)).instance) ;
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForMainHeader(header);
    }
    return result;
}
    
mailcore::String * AbstractMessageRendererCallback::templateForImage(mailcore::AbstractPart * part) {
    mailcore::String * result = NULL;
    if (templateForImageBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForImageBlock(userInfo, CAbstractPart_new(part)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForImage(part);
    }
    return result;
}
    
mailcore::String * AbstractMessageRendererCallback::templateForAttachment(mailcore::AbstractPart * part) {
    mailcore::String * result = NULL;
    if (templateForAttachmentBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForAttachmentBlock(userInfo, CAbstractPart_new(part)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForAttachment(part);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::templateForMessage(mailcore::AbstractMessage * message) {
    mailcore::String * result = NULL;
    if (templateForMessageBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForMessageBlock(userInfo, CAbstractMessage_new(message)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForMessage(message);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::templateForEmbeddedMessage(mailcore::AbstractMessagePart * part) {
    mailcore::String * result = NULL;
    if (templateForEmbeddedMessageBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForEmbeddedMessageBlock(userInfo, CAbstractMessagePart_new(part)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForEmbeddedMessage(part);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::templateForEmbeddedMessageHeader(mailcore::MessageHeader * header) {
    mailcore::String * result = NULL;
    if (templateForEmbeddedMessageHeaderBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForEmbeddedMessageHeaderBlock(userInfo, CMessageHeader_new(header)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForEmbeddedMessageHeader(header);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::templateForAttachmentSeparator() {
    mailcore::String * result = NULL;
    if (templateForAttachmentSeparatorBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(templateForAttachmentSeparatorBlock(userInfo).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::templateForAttachmentSeparator();
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::cleanHTMLForPart(mailcore::String * html) {
    mailcore::String * result = NULL;
    if (cleanHTMLForPartBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(cleanHTMLForPartBlock(userInfo, MailCoreString_new(html)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::cleanHTMLForPart(html);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::filterHTMLForPart(mailcore::String * html) {
    mailcore::String * result = NULL;
    if (filterHTMLForPartBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(filterHTMLForPartBlock(userInfo, MailCoreString_new(html)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::filterHTMLForPart(html);
    }
    return result;
}

mailcore::String * AbstractMessageRendererCallback::filterHTMLForMessage(mailcore::String * html) {
    mailcore::String * result = NULL;
    if (filterHTMLForMessageBlock != NULL) {
        result = reinterpret_cast<mailcore::String*>(filterHTMLForMessageBlock(userInfo, MailCoreString_new(html)).instance);
    }
    if (result == NULL) {
        result = HTMLRendererTemplateCallback::filterHTMLForMessage(html);
    }
    return result;
}

mailcore::Data * AbstractMessageRendererCallback::dataForIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
    mailcore::Data * result = NULL;
    if (dataForIMAPPartBlock != NULL) {
        CData data = dataForIMAPPartBlock(userInfo, MailCoreString_new(folder), CIMAPPart_new(part));
        result = data.instance;
    }
    return result;
}

void AbstractMessageRendererCallback::prefetchAttachmentIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
    if (prefetchAttachmentIMAPPartBlock != NULL) {
        prefetchAttachmentIMAPPartBlock(userInfo, MailCoreString_new(folder), CIMAPPart_new(part));
    }
}

void AbstractMessageRendererCallback::prefetchImageIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
    if (prefetchImageIMAPPartBlock != NULL) {
        prefetchImageIMAPPartBlock(userInfo, MailCoreString_new(folder), CIMAPPart_new(part));
    }
}

CAbstractMessageRendererCallback CAbstractMessageRendererCallback_new(CanPreviewPartBlock canPreviewPartBlock,
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
                                                                     const void* userInfo) {
    CAbstractMessageRendererCallback self;
    self.callbackBridge = new AbstractMessageRendererCallback(canPreviewPartBlock,
                                                              shouldShowPartBlock,
                                                              templateValuesForHeaderBlock,
                                                              templateValuesForPartBlock,
                                                              templateForMainHeaderBlock,
                                                              templateForImageBlock,
                                                              templateForAttachmentBlock,
                                                              templateForMessageBlock,
                                                              templateForEmbeddedMessageBlock,
                                                              templateForEmbeddedMessageHeaderBlock,
                                                              templateForAttachmentSeparatorBlock,
                                                              cleanHTMLForPartBlock,
                                                              filterHTMLForPartBlock,
                                                              filterHTMLForMessageBlock,
                                                              dataForIMAPPartBlock,
                                                              prefetchAttachmentIMAPPartBlock,
                                                              prefetchImageIMAPPartBlock,
                                                              userInfo);
    return self;
}

void CAbstractMessageRendererCallback_rerain(CAbstractMessageRendererCallback self) {
    self.callbackBridge->retain();
}

void CAbstractMessageRendererCallback_release(CAbstractMessageRendererCallback self) {
    self.callbackBridge->release();
}
