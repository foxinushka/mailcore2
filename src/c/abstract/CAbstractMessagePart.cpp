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
    
    self.header = &header;
    self.setHeader = &setHeader;
    self.mainPart = &mainPart;
    self.setMainPart = &setMainPart;
    
    return self;
}

mailcore::AbstractMessagePart* cast(CAbstractMessagePart part) {
    return reinterpret_cast<mailcore::AbstractMessagePart*>(part.abstractPart.nativeInstance);
}

CMessageHeader header(CAbstractMessagePart self){
    return newCMessageHeader(cast(self)->header());
}

void setHeader(CAbstractMessagePart self, CMessageHeader header){
    cast(self)->setHeader(cast(header));
}

CAbstractPart mainPart(CAbstractMessagePart self){
    return newCAbstractPart(cast(self)->mainPart());
}

void setMainPart(struct CAbstractMessagePart self, CAbstractPart part){
    cast(self)->setMainPart(cast(part));
}






