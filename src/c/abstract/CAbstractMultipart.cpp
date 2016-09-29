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

CAbstractMultipart newCAbstractMultipart(mailcore::AbstractPart *part){
    CAbstractMultipart self;
    self.abstractPart = newCAbstractPart(part);
    
    self.parts = &parts;
    self.setParts = &setParts;
    
    return self;
}

mailcore::AbstractMultipart * cast(CAbstractMultipart part){
    return reinterpret_cast<mailcore::AbstractMultipart*>(part.abstractPart.nativeInstance);
}

CArray parts(struct CAbstractMultipart self){
    return newCArray(cast(self)->parts());
}

void setParts(struct CAbstractMultipart self, CArray parts){
    cast(self)->setParts(cast(parts));
}






