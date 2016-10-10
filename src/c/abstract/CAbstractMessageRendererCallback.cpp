#include "CAbstractMessageRendererCallback.h"
#include <MailCore/MCAsync.h>
#include <MailCore/MCRenderer.h>

class AbstractMessageRendererCallback : public mailcore::Object, public mailcore::HTMLRendererTemplateCallback, public mailcore::HTMLRendererIMAPCallback {
public:
    AbstractMessageRendererCallback() {

    }
    
    void setHtmlRendererDelegateCallbacks(CanPreviewPartBlock canPreviewPartBlock,
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
                                          FilterHTMLForMessageBlock filterHTMLForMessageBlock) {
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
    }
    
    void setHtmlRedererImapDelefate(DataForIMAPPartBlock dataForIMAPPartBlock,
                                    PrefetchAttachmentIMAPPartBlock prefetchAttachmentIMAPPartBlock,
                                    PrefetchImageIMAPPartBlock prefetchImageIMAPPartBlock) {
        this->dataForIMAPPartBlock = dataForIMAPPartBlock;
        this->prefetchAttachmentIMAPPartBlock = prefetchAttachmentIMAPPartBlock;
        this->prefetchImageIMAPPartBlock = prefetchImageIMAPPartBlock;
    }
    
    virtual bool canPreviewPart(mailcore::AbstractPart * part) {
        if (canPreviewPartBlock != NULL) {
            return canPreviewPartBlock(newCAbstractPart(part)) > 0;
        }
        return HTMLRendererTemplateCallback::canPreviewPart(part);
    }
    
    virtual bool shouldShowPart(mailcore::AbstractPart * part) {
        if (shouldShowPartBlock != NULL) {
            return shouldShowPartBlock(newCAbstractPart(part)) > 0;
        }
        return HTMLRendererTemplateCallback::shouldShowPart(part);
    }
    
    virtual mailcore::HashMap * templateValuesForHeader(mailcore::MessageHeader * header) {
        mailcore::HashMap * result = NULL;
        if (templateValuesForHeaderBlock != NULL) {
            result = templateValuesForHeaderBlock(newCMessageHeader(header)).instance;
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateValuesForHeader(header);
        }
        return result;
    }
    
    virtual mailcore::HashMap * templateValuesForPart(mailcore::AbstractPart * part) {
        mailcore::HashMap * result = NULL;
        if (templateValuesForPartBlock != NULL) {
            result = templateValuesForPartBlock(newCAbstractPart(part)).instance;
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateValuesForPart(part);
        }
        return result;
    }
    
    virtual mailcore::String * templateForMainHeader(mailcore::MessageHeader * header) {
        mailcore::String * result = NULL;
        if (templateForMainHeaderBlock != NULL) {
            result = new mailcore::String(templateForMainHeaderBlock(newCMessageHeader(header)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForMainHeader(header);
        }
        return result;
    }
    
    virtual mailcore::String * templateForImage(mailcore::AbstractPart * part) {
        mailcore::String * result = NULL;
        if (templateForImageBlock != NULL) {
            result = new mailcore::String(templateForImageBlock(newCAbstractPart(part)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForImage(part);
        }
        return result;
    }
    
    virtual mailcore::String * templateForAttachment(mailcore::AbstractPart * part) {
        mailcore::String * result = NULL;
        if (templateForAttachmentBlock != NULL) {
            result = new mailcore::String(templateForAttachmentBlock(newCAbstractPart(part)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForAttachment(part);
        }
        return result;
    }
    
    virtual mailcore::String * templateForMessage(mailcore::AbstractMessage * message) {
        mailcore::String * result = NULL;
        if (templateForMessageBlock != NULL) {
            result = new mailcore::String(templateForMessageBlock(newCAbstractMessage(message)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForMessage(message);
        }
        return result;
    }
    
    virtual mailcore::String * templateForEmbeddedMessage(mailcore::AbstractMessagePart * part) {
        mailcore::String * result = NULL;
        if (templateForEmbeddedMessageBlock != NULL) {
            result = new mailcore::String(templateForEmbeddedMessageBlock(newCAbstractMessagePart(part)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForEmbeddedMessage(part);
        }
        return result;
    }
    
    virtual mailcore::String * templateForEmbeddedMessageHeader(mailcore::MessageHeader * header) {
        mailcore::String * result = NULL;
        if (templateForEmbeddedMessageHeaderBlock != NULL) {
            result = new mailcore::String(templateForEmbeddedMessageHeaderBlock(newCMessageHeader(header)));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForEmbeddedMessageHeader(header);
        }
        return result;
    }
    
    virtual mailcore::String * templateForAttachmentSeparator() {
        mailcore::String * result = NULL;
        if (templateForAttachmentSeparatorBlock != NULL) {
            result = new mailcore::String(templateForAttachmentSeparatorBlock());
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::templateForAttachmentSeparator();
        }
        return result;
    }
    
    virtual mailcore::String * cleanHTMLForPart(mailcore::String * html) {
        mailcore::String * result = NULL;
        if (cleanHTMLForPartBlock != NULL) {
            result = new mailcore::String(cleanHTMLForPartBlock(html->unicodeCharacters()));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::cleanHTMLForPart(html);
        }
        return result;
    }
    
    virtual mailcore::String * filterHTMLForPart(mailcore::String * html) {
        mailcore::String * result = NULL;
        if (filterHTMLForPartBlock != NULL) {
            result = new mailcore::String(filterHTMLForPartBlock(html->unicodeCharacters()));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::filterHTMLForPart(html);
        }
        return result;
    }
    
    virtual mailcore::String * filterHTMLForMessage(mailcore::String * html) {
        mailcore::String * result = NULL;
        if (filterHTMLForMessageBlock != NULL) {
            result = new mailcore::String(filterHTMLForMessageBlock(html->unicodeCharacters()));
        }
        if (result == NULL) {
            result = HTMLRendererTemplateCallback::filterHTMLForMessage(html);
        }
        return result;
    }

    virtual mailcore::Data * dataForIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
        mailcore::Data * result = NULL;
        if (dataForIMAPPartBlock != NULL) {
            CData data = dataForIMAPPartBlock(folder->unicodeCharacters(), newCIMAPPart(part));
            result = new mailcore::Data(data.bytes, data.length);
        }
        return result;
    }
    
    virtual void prefetchAttachmentIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
        if (prefetchAttachmentIMAPPartBlock != NULL) {
            prefetchAttachmentIMAPPartBlock(folder->unicodeCharacters(), newCIMAPPart(part));
        }
    }
    
    virtual void prefetchImageIMAPPart(mailcore::String * folder, mailcore::IMAPPart * part) {
        if (prefetchImageIMAPPartBlock != NULL) {
            prefetchImageIMAPPartBlock(folder->unicodeCharacters(), newCIMAPPart(part));
        }
    }
    
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
};

void setHtmlRendererDelegateCallbacks(CAbstractMessageRendererCallback self,
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
                                                      FilterHTMLForMessageBlock filterHTMLForMessageBlock) {
    
    self.callbackBridge->setHtmlRendererDelegateCallbacks(canPreviewPartBlock,
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
                                                          filterHTMLForMessageBlock);
}

void setHtmlRedererImapDelefate(CAbstractMessageRendererCallback self,
                         DataForIMAPPartBlock dataForIMAPPartBlock,
                         PrefetchAttachmentIMAPPartBlock prefetchAttachmentIMAPPartBlock,
                         PrefetchImageIMAPPartBlock prefetchImageIMAPPartBlock) {
    self.callbackBridge->setHtmlRedererImapDelefate(dataForIMAPPartBlock, prefetchImageIMAPPartBlock, prefetchAttachmentIMAPPartBlock);
}

CAbstractMessageRendererCallback newCAbstractMessageRendererCallback() {
    CAbstractMessageRendererCallback self;
    self.callbackBridge = new AbstractMessageRendererCallback();
    
    return self;
}

void deleteCAbstractMessageRendererCallback(CAbstractMessageRendererCallback self) {
    
}
