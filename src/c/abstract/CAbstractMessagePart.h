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
        
        struct CMessageHeader           (*header)(struct CAbstractMessagePart *self);
        void                            (*setHeader)(struct CAbstractMessagePart *self, struct CMessageHeader* header);
        struct CAbstractMessagePart     (*mainPart)(struct CAbstractMessagePart *self);
        void                            (*setMainPart)(struct CAbstractMessagePart *self, struct CAbstractMessagePart* part);
        
    };
    typedef struct CAbstractMessagePart CAbstractMessagePart;
    
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
CAbstractPart newCAbstractMessagePart(mailcore::AbstractPart *part);
mailcore::AbstractPart * cast(CAbstractMessagePart *part);
#endif

#endif
