#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMessagePart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMessagePart
#define structName CAbstractMessagePart

CMessageHeader          header(struct CAbstractMessagePart* self);
void                    setHeader(struct CAbstractMessagePart* self, CMessageHeader* header);
CAbstractMessagePart    mainPart(struct CAbstractMessagePart *self);
void                    setMainPart(struct CAbstractMessagePart *self, CAbstractMessagePart* part);

CAbstractMessagePart newCAbstractMessagePart(mailcore::AbstractMessagePart *part){
    CAbstractMessagePart self;
    self.abstractPart = newCAbstractPart(part);
    
    self.header = &header;
    self.setHeader = &setHeader;
    self.mainPart = &mainPart;
    self.setMainPart = &setMainPart;
    
    return self;
}

mailcore::AbstractPart * cast(CAbstractMessagePart *part) {
    return reinterpret_cast<mailcore::AbstractPart*>(part->abstractPart.nativeInstance);
}

CMessageHeader header(struct CAbstractMessagePart* abstractMessagePart){
    CAbstractPart *self = &abstractMessagePart->abstractPart;
    return newCMessageHeader(C_NATIVE_INSTANCE->header());
}

void setHeader(struct CAbstractMessagePart* abstractMessagePart, CMessageHeader* header){
    CAbstractPart *self = &abstractMessagePart->abstractPart;
    C_NATIVE_INSTANCE->setHeader(cast(header));
}

CAbstractMessagePart mainPart(struct CAbstractMessagePart *abstractMessagePart){
    CAbstractPart *self = &abstractMessagePart->abstractPart;
    return newCAbstractMessagePart((mailcore::AbstractMessagePart *)C_NATIVE_INSTANCE->mainPart());
}

void setMainPart(struct CAbstractMessagePart *abstractMessagePart, CAbstractMessagePart* part){
    CAbstractPart *self = &abstractMessagePart->abstractPart;
    C_NATIVE_INSTANCE->setMainPart(cast(part));
}






