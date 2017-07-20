#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMultipart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMultipart
#define structName CAbstractMultipart

CAbstractMultipart CAbstractMultipart_new(mailcore::AbstractMultipart *part){
    CAbstractMultipart self;
    self.abstractPart = CAbstractPart_new(part);
    self.instance = part;
    return self;
}

CArray CAbstractMultipart_parts(struct CAbstractMultipart self){
    return CArray_new(self.instance->parts());
}

void CAbstractMultipart_setParts(struct CAbstractMultipart self, CArray parts){
    self.instance->setParts(parts.instance);
}






