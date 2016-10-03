#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMultipart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMultipart
#define structName CAbstractMultipart

CArray      parts(struct CAbstractMultipart multipart);
void        setParts(struct CAbstractMultipart multipart, CArray parts);

CAbstractMultipart newCAbstractMultipart(mailcore::AbstractMultipart *part){
    CAbstractMultipart self;
    self.abstractPart = newCAbstractPart(part);
    self.instance = part;
    
    self.parts = &parts;
    self.setParts = &setParts;
    
    return self;
}

CArray parts(struct CAbstractMultipart self){
    return newCArray(self.instance->parts());
}

void setParts(struct CAbstractMultipart self, CArray parts){
    self.instance->setParts(parts.instance);
}






