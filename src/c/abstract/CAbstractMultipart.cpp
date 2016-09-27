#include <MailCore/MCCore.h>
#include "CAbstractMessage.h"
#include "CMessageHeader.h"
#include "CAbstractPart.h"
#include "CAbstractMultipart.h"
#include "CBase+Private.h"

#define nativeType mailcore::AbstractMultipart
#define structName CAbstractMultipart

CArray      parts(struct CAbstractMultipart *multipart);
void        setParts(struct CAbstractMultipart *multipart, CArray *parts);

CAbstractMultipart newCAbstractMultipart(mailcore::AbstractPart *part){
    CAbstractMultipart self;
    self.abstractPart = newCAbstractPart(part);
    
    self.parts = &parts;
    self.setParts = &setParts;
    
    return self;
}

mailcore::AbstractPart * cast(CAbstractMultipart *part){
    return reinterpret_cast<mailcore::AbstractMultipart*>(part->abstractPart.nativeInstance);
}

CArray parts(struct CAbstractMultipart *multipart){
    CAbstractPart *self = &multipart->abstractPart;
    return newCArray2(C_NATIVE_INSTANCE->parts());
}

void setParts(struct CAbstractMultipart *multipart, CArray *parts){
    CAbstractPart *self = &multipart->abstractPart;
    C_NATIVE_INSTANCE->setParts(cast(parts));
}






