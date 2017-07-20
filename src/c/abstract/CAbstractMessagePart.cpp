#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMessagePart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessagePart
#define structName CAbstractMessagePart

CAbstractMessagePart CAbstractMessagePart_new(mailcore::AbstractMessagePart *part){
    CAbstractMessagePart self;
    self.abstractPart = CAbstractPart_new(part);
    self.instance = part;
    return self;
}

CMessageHeader CAbstractMessagePart_header(CAbstractMessagePart self){
    return CMessageHeader_new(self.instance->header());
}

void CAbstractMessagePart_setHeader(CAbstractMessagePart self, CMessageHeader header){
    self.instance->setHeader(header.instance);
}

CAbstractPart CAbstractMessagePart_mainPart(CAbstractMessagePart self){
    return CAbstractPart_new(self.instance->mainPart());
}

void CAbstractMessagePart_setMainPart(struct CAbstractMessagePart self, CAbstractPart part){
    self.instance->setMainPart(part.instance);
}






