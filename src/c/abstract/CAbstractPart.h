#ifndef MAILCORE_CABSTRACT_PART_H
#define MAILCORE_CABSTRACT_PART_H

#include "stdint.h"

#include "CBase.h"
#include "CArray.h"
#include "CMessageConstants.h"

#ifdef __cplusplus

namespace mailcore {
    class AbstractPart;
}

extern "C" {
#endif

    struct CAbstractPart {
#ifdef __cplusplus
        mailcore::AbstractPart* instance;
#else
        void*                   instance;
#endif
        PartType        (*partType)(struct CAbstractPart self);
        void            (*setPartType)(struct CAbstractPart self, PartType type);
        const UChar*    (*filename)(struct CAbstractPart self);
        void            (*setFilename)(struct CAbstractPart self, const UChar* filename);
        const UChar*    (*mimeType)(struct CAbstractPart self);
        void            (*setMimeType)(struct CAbstractPart self, const UChar* mimeType);
        const UChar*    (*charset)(struct CAbstractPart self);
        void            (*setCharset)(struct CAbstractPart self, const UChar* charset);
        const UChar*    (*uniqueID)(struct CAbstractPart self);
        void            (*setUniqueID)(struct CAbstractPart self, const UChar* uniqueID);
        const UChar*    (*contentID)(struct CAbstractPart self);
        void            (*setContentID)(struct CAbstractPart self, const UChar* contentID);
        const UChar*    (*contentLocation)(struct CAbstractPart self);
        void            (*setContentLocation)(struct CAbstractPart self, const UChar* contentLocation);
        const UChar*    (*contentDescriprion)(struct CAbstractPart self);
        void            (*setContentDescription)(struct CAbstractPart self, const UChar* contentDescription);
        bool            (*isInlineAttachment)(struct CAbstractPart self);
        void            (*setInlineAttachment)(struct CAbstractPart self, bool isInlineAttachment);
        bool            (*isAttachment)(struct CAbstractPart self);
        void            (*setAttachment)(struct CAbstractPart self, bool isAttachment);
        
        struct CAbstractPart    (*partForContentID)(struct CAbstractPart self, const UChar* contentID);
        struct CAbstractPart    (*partForUniqueID)(struct CAbstractPart self, const UChar* uniqueID);
        const UChar*            (*decodedStringForData)(struct CAbstractPart self, const uint8_t* bytes, uint32_t lenght);
        void                    (*setContentTypeParameterValue)(struct CAbstractPart self, const UChar* value, const UChar* name);
        void                    (*removeContentTypeParameterForName)(struct CAbstractPart self, const UChar* name);
        const UChar*            (*contentTypeParameterValueForName)(struct CAbstractPart self, const UChar* name);
        CArray                  (*allContentTypeParametersNames)(struct CAbstractPart self);
        
        CObject                 (*castToCObject)(struct CAbstractPart self);
    };
    typedef struct CAbstractPart CAbstractPart;
    
    CAbstractPart castFromCObject(CObject obj);
    void deleteCAbstractPart(CAbstractPart self);
    
#ifdef __cplusplus
}

CAbstractPart newCAbstractPart(mailcore::AbstractPart *part);
#endif

#endif
