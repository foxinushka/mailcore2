#ifndef MAILCORE_CABSTRACT_MESSAGE_PART_H
#define MAILCORE_CABSTRACT_MESSAGE_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CAbstractPart.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractMessagePart;
}

extern "C" {
#endif
    
    struct CMessageHeader;
    
    struct CAbstractMessagePart {
#ifdef __cplusplus
        mailcore::AbstractMessagePart*  instance;
#else
        void*                           instance;
#endif
        CAbstractPart abstractPart;
        
        struct CMessageHeader           (*header)(struct CAbstractMessagePart self);
        void                            (*setHeader)(struct CAbstractMessagePart self, struct CMessageHeader header);
        struct CAbstractPart            (*mainPart)(struct CAbstractMessagePart self);
        void                            (*setMainPart)(struct CAbstractMessagePart self, struct CAbstractPart part);
        
    };
    typedef struct CAbstractMessagePart CAbstractMessagePart;
    
#ifdef __cplusplus
}

CAbstractMessagePart newCAbstractMessagePart(mailcore::AbstractMessagePart *part);
#endif

#endif
