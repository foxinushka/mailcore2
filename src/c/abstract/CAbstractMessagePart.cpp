#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMessagePart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessagePart
#define structName CAbstractMessagePart

CMessageHeader          header(struct CAbstractMessagePart self);
void                    setHeader(struct CAbstractMessagePart self, CMessageHeader header);
CAbstractPart           mainPart(CAbstractMessagePart self);
void                    setMainPart(struct CAbstractMessagePart self, CAbstractPart part);

CAbstractMessagePart newCAbstractMessagePart(mailcore::AbstractMessagePart *part){
    CAbstractMessagePart self;
    self.abstractPart = newCAbstractPart(part);
    self.instance = part;
    
    self.header = &header;
    self.setHeader = &setHeader;
    self.mainPart = &mainPart;
    self.setMainPart = &setMainPart;
    
    return self;
}

CMessageHeader header(CAbstractMessagePart self){
    return newCMessageHeader(self.instance->header());
}

void setHeader(CAbstractMessagePart self, CMessageHeader header){
    self.instance->setHeader(header.instance);
}

CAbstractPart mainPart(CAbstractMessagePart self){
    return newCAbstractPart(self.instance->mainPart());
}

void setMainPart(struct CAbstractMessagePart self, CAbstractPart part){
    self.instance->setMainPart(part.instance);
}






