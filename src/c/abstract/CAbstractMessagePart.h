#ifndef MAILCORE_CABSTRACT_MESSAGE_PART_H
#define MAILCORE_CABSTRACT_MESSAGE_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    struct CMessageHeader;
    
    struct CAbstractMessagePart {
        CAbstractPart abstractPart;
        
        struct CMessageHeader           (*header)(struct CAbstractMessagePart self);
        void                            (*setHeader)(struct CAbstractMessagePart self, struct CMessageHeader header);
        struct CAbstractPart            (*mainPart)(struct CAbstractMessagePart self);
        void                            (*setMainPart)(struct CAbstractMessagePart self, struct CAbstractPart part);
        
    };
    typedef struct CAbstractMessagePart CAbstractMessagePart;
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAbstractMessagePart newCAbstractMessagePart(mailcore::AbstractMessagePart *part);
mailcore::AbstractMessagePart* cast(CAbstractMessagePart part);
#endif

#endif
